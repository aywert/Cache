#include "../include/CacheLRUClass.hpp"

//initialisation of method for Cache_LRU

void Cache_LRU::resize (size_t new_size) {size_ = new_size;}
size_t Cache_LRU::get_size(void) const {return size_;}
size_t Cache_LRU::get_hits(void) const {return n_hits_;}

auto Cache_LRU::find(int key)
{
  return hash_ls.find(key);
}

bool Cache_LRU::check_cache(int key)
{
  auto it = hash_ls.find(key);

  if (it != hash_ls.end()) {
    
    cache_.erase(it->second);
    hash_ls.erase(key);
    cache_.push_front(CacheLine_LRU{key, key});
    hash_ls.insert({key, cache_.begin()});
    
    n_hits_++;
    return true;
  } 

  if (is_ideal || !this->is_full()) {
    cache_.push_front(CacheLine_LRU{key, key});
    hash_ls.insert({key, cache_.begin()});
  }

  else {
    hash_ls.erase(cache_.back().key);         //deleting itearator with that key from Hashtable
    cache_.pop_back();                        //deleting last element of cache_
    cache_.push_front(CacheLine_LRU{key, key});
    hash_ls.insert({key, cache_.begin()});
  }

  return false;
}