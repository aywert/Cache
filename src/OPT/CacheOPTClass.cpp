#include "../include/CacheOPTClass.hpp"

void Cache_OPT::get_vector_stdin(size_t arg_n)
  {
    size_t buf = 0;
    for (size_t i = 0; i < arg_n; i++)
    {
      std::cin >> buf;
      vector_.emplace_back(buf);
    }
  }

  void Cache_OPT::dump_vector(void)
  {
    std::cout << "vector_: | ";
    for (size_t i = 0; i < vector_.size(); i++)
      std::cout << vector_[i] << " | ";
  }

bool Cache_OPT::check_cache(int key)
{
  auto it = hash_table.find(key);

  if (it != hash_table.end()) { //if hit - don`t do anything
    n_hits_++;
    return true;
  } 

  if (!is_full()) {
    cache_.push_front(CacheLine{key, key});
    hash_table.insert({key, cache_.begin()});
  }

  else {
    
    int del_key = select_key_func();//add select function for determening whooch element to erase
    hash_table.erase(del_key);         //deleting itearator with that key from Hashtable
    cache_.pop_back();                 //deleting last element of cache_
    cache_.push_front(CacheLine{key, key});
    hash_table.insert({key, cache_.begin()});
  }

  return false;
}

int Cache_OPT::select_key_func()
{
  return 0; // yet to be made
}