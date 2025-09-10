#include <iostream>
#include <unordered_map>
#include "../include/HashlineClass.hpp" // data_t

//typedef int data_t; 

int main(void)
{
  using std::cin;
  using std::cout;

  size_t cache_size;
  size_t N_elem;
  
  cin >> cache_size >> N_elem;
  cout << "cache_size: " << cache_size << "\n" << "Num_of_elem: "<< N_elem << "\n";

  class Hash_cl Hash_obj = Hash_cl(cache_size, N_elem); 

  int buf;
  for (size_t i = 0; i < N_elem; i++)
  {
    cin >> buf;
    if (Hash_obj.check_hash(buf))
    {
      cout << "Cache hit: " << buf << "\n";
    }
  }

  std::cout << "Number of hits = " << Hash_obj.get_hits() << "\n";

  return 0;
}