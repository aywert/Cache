#include "../include/HashlineClass.hpp"

//initialisation of method for Hash_cl

void Hash_cl::resize (size_t new_size) {size_ = new_size;}
size_t Hash_cl::get_size(void) const {return size_;}
auto Hash_cl::find(int key)
{
  return hash_.find(key);
}

bool Hash_cl::check_hash(int key)
{
  
  auto it = hash_.find(key);

  if (it != hash_.end()) {
    n_hits_++;
    return true;
  }

  if (!this->is_full()) {
    //std::cout << "i have been here\n";
    hash_.insert({key, key});
  }

  else {
    auto it = hash_.begin();
    hash_.erase(it->first);
    hash_.insert({key, key});
  }

  return false;
}
// std::unordered_map<data_t, int> HashTable;

// auto it = HashTable.find(buf);

    // if (HashTable.size() < cache_size)
    //   HashTable.insert({buf, buf});
    // else
    // {
    //   if (it != HashTable.end())
    //   {
    //     cout << "Cache hit: " << buf << "\n";
    //   }
    //   else 
    //   {
    //     auto it = HashTable.begin();
    //     HashTable.erase(it->first);
    //     HashTable.insert({buf, buf});
    //   }
    //}