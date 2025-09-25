#include "../include/tests.hpp"

bool run_tests_OPT(void)
{
  std::ifstream in;
  bool run = true;

  in.open("./src/tests/tests.txt");

  if (!in.is_open()) 
    {
      std::cout << "Mistake in opening the file\n";
      return false;
    }
  
  std::cout << "Proceding emplementings tests...\n";

  size_t iter = 0;
  while (run) {
    iter++;
    size_t cache_size;
    size_t N_elem;
    in >> cache_size >> N_elem;

    //std::cout << "cache_size: " << cache_size << "\n" << "Num_of_elem: "<< N_elem << "\n";
    class Cache_OPT Cache = Cache_OPT(cache_size, N_elem);

    Cache.get_vector(N_elem, in);

    int buf;
    in >> buf; //take the additional number in the sequence which is the actual numbers of hits
    
    if(Cache.get_hits() == size_t(buf))
      std::cout << "Test[" << iter << "] | passed\n";
    else
    {
      std::cout << "Test[" << iter << "] | failed\n";
      std::cout << "My Hits: " << Cache.get_hits() << "\n";
      std::cout << "Actual Hits: " << buf << "\n";
    }

    if (in.eof()) {
      run = false;
      return true;
    }
  }

  return false;
}