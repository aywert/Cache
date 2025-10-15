#include <iostream>
#include "../include/CacheOPTClass.hpp"
#include "../include/tests.hpp"

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
  size_t hits;
  
  cin >> cache_size >> N_elem;

  class Cache_OPT<int, int> Cache(cache_size, N_elem);  

  Cache.get_vector(N_elem, std::cin);

  for (size_t i = 0; i < N_elem; i++)
  {
    if(Cache.check_cache(Cache.vector_[i]))
      hits++;
  }

  cout << "Idial Cache: "<< hits << "\n";
  return 0;
}