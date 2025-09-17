#include "../include/tests.hpp"

bool run_tests(void)
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
    class Hash_cl Hash_obj = Hash_cl(cache_size, N_elem);

    int buf;
    for (size_t i = 0; i < N_elem; i++)
    {
      in >> buf;
      Hash_obj.check_hash(buf);
    }

    in >> buf; //take the additional number in the sequence which is the actual numbers of hits
    if(Hash_obj.get_hits() == size_t(buf))
      std::cout << "Test[" << iter << "] | passed\n";
    else
    {
      std::cout << "Test[" << iter << "] | failed\n";
      std::cout << "My Hits: " << Hash_obj.get_hits() << "\n";
      std::cout << "Actual Hits: " << buf << "\n";
    }

    if (in.eof()) {
      run = false;
      return true;
    }
  }

  return false;
  
}