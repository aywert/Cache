#include "../include/HashlineClass.hpp"

//initialisation of method for Hash_cl

void Hash_cl::resize (size_t new_size) {size_ = new_size;}
size_t Hash_cl::get_size(void) const {return size_;}
auto Hash_cl::find(int key)
{
  return hash_.find(key);
}