#include "../include/HashlineClass.hpp"

//initialisation of method for Hash_cl

void Hash_cl::resize (size_t new_size) {size_ = new_size;}
size_t Hash_cl::get_size(void) const {return size_;}
size_t Hash_cl::get_hits(void) const {return n_hits_;}

auto Hash_cl::find(int key)
{
  return hash_ls.find(key);
}

bool Hash_cl::check_hash(int key)
{
  auto it = hash_ls.find(key);

  if (it != hash_ls.end()) {
    n_hits_++;
    return true;
  } 

  if (is_ideal || !this->is_full()) {
    cache_.push_front(CacheLine{key, key});
    hash_ls.insert({key, cache_.begin()});
  }

  else {
    hash_ls.erase(cache_.back().key);         //deleting itearator with that key from Hashtable
    cache_.pop_back();                        //deleting last element of cache_
    cache_.push_front(CacheLine{key, key});
    hash_ls.insert({key, cache_.begin()});
  }

  return false;
}