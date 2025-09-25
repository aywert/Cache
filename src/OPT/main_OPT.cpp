#include <iostream>
#include "../include/CacheOPTClass.hpp"

int main(void)
{
  using std::cin;
  using std::cout;

  size_t cache_size;
  size_t N_elem;
  
  cin >> cache_size >> N_elem;

  class Cache_OPT Cache = Cache_OPT(cache_size, N_elem);  

  Cache.get_vector_stdin(N_elem);
  Cache.dump_vector();

  for (size_t i = 0; i < N_elem; i++)
    Cache.check_cache(Cache.vector_[i]);

  std::cout << "Idial Cache: "<<Cache.get_hits() << "\n";
  return 0;
}