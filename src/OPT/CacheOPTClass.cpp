#include "../include/CacheOPTClass.hpp"

void Cache_OPT::get_vector(size_t arg_n, std::istream& input) {
  size_t buf = 0;
  for (size_t i = 0; i < arg_n; i++) {
    //std::cin >> buf;
    input >> buf;
    vector_.emplace_back(buf);
  }
}

void Cache_OPT::dump_vector(void) {
  std::cout << "vector_: | ";
  for (size_t i = 0; i < vector_.size(); i++)
    std::cout << vector_[i] << " | ";
  std::cout << "\n";
}

bool Cache_OPT::check_cache(int key)
{
  auto it = hash_table.find(key);

  if (it != hash_table.end()) { //if hit - don`t do anything
    n_hits_++;
    pos_in_vector_++;
    return true;
  } 

  if (!is_full()) {
    cache_.push_front(CacheLine_OPT{key, key});
    hash_table.insert({key, cache_.begin()});
  }

  else {
    int del_key = select_key_func(); 
    if (del_key == -1) {pos_in_vector_++; return false;} // checking whether del_key was not selected
    if (del_key == -2) { //deleting last element as is never going to be encountered again
      hash_table.erase(cache_.back().key);         //deleting itearator with that key from Hashtable
      cache_.pop_back();                            //deleting last element of cache_
      cache_.push_front(CacheLine_OPT{key, key});
      hash_table.insert({key, cache_.begin()});
    }

    auto del_it = hash_table.find(del_key);

    if (del_it != hash_table.end()) {
      std::cout << "i am here\n";
      cache_.erase(del_it->second); 
      hash_table.erase(del_it);   
      cache_.push_front(CacheLine_OPT{key, key});
      hash_table.insert({key, cache_.begin()});
    }
  }
  pos_in_vector_++;
  return false;
}

int Cache_OPT::select_key_func()
{
  bool is_selected = false;
  auto begin_it = cache_.begin();
  size_t furthest = 0;

  for (auto it = cache_.begin(); (size_t)std::distance(begin_it, it) < size_ ; it++) {
    //printf("iter key: %d\n", it->key);
    for (size_t i = pos_in_vector_ + 1; i < n_sells_; i++) {
      if (vector_[i] == it->key) {
        if ((i - pos_in_vector_) >= furthest)
          furthest = i - pos_in_vector_;
        break;
      }
    } 
  }
  
  //printf("------------------------\n");
  if (furthest == 0) return -2;
  for (size_t i = pos_in_vector_ + 1; i < n_sells_; i++) {
    if (vector_[i] == vector_[pos_in_vector_]) {
      is_selected = true; // entering if means that there is at least one number with same value
      if ((i - pos_in_vector_) >= furthest)
        is_selected = false;
      break; 
    }
  }

  return is_selected ? vector_[furthest+pos_in_vector_] : -1;
}