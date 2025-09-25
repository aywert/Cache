#include <iostream>
#include "../include/CacheOPTClass.hpp"

int main(void)
{
  #ifdef DEBUG
    std::cout << "DEBUG tests initialized.\n";
    if (run_tests_OPT())
      std::cout << "Tests completed\n";
    else
    {
      std::cout << "Mistake occurede during tests\n";
    }
    return 0;
  #endif

  using std::cin;
  using std::cout;

  size_t cache_size;
  size_t N_elem;
  
  cin >> cache_size >> N_elem;

  class Cache_OPT Cache = Cache_OPT(cache_size, N_elem);  

  Cache.get_vector(N_elem, std::cin);

  for (size_t i = 0; i < N_elem; i++)
    Cache.check_cache(Cache.vector_[i]);

  cout << "Idial Cache: "<<Cache.get_hits() << "\n";
  return 0;
}