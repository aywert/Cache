#include <iostream>
#include <unordered_map>
#include "../include/HashlineClass.hpp"
#include "../include/tests.hpp" //run_tests

int main(void)
{

  #ifdef DEBUG
    std::cout << "DEBUG tests initialized.\n";
    if (run_tests())
      std::cout << "Tests completed\n";
    return 0;
  #endif

  using std::cin;
  using std::cout;

  size_t cache_size;
  size_t N_elem;
  
  cin >> cache_size >> N_elem;
  //cout << "cache_size: " << cache_size << "\n" << "Num_of_elem: "<< N_elem << "\n";

  class Hash_cl Hash_obj = Hash_cl(cache_size, N_elem); 
  class Hash_cl Idial_Hash = Hash_cl(); 

  int buf;
  for (size_t i = 0; i < N_elem; i++)
  {
    cin >> buf;
    Hash_obj.check_hash(buf);
    Idial_Hash.check_hash(buf);
  }

  std::cout << "My Cache: " << Hash_obj.get_hits() << "\n";
  std::cout << "Ideal cache: " << Idial_Hash.get_hits() << "\n";
  return 0;
}