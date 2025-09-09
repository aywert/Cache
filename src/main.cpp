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

  std::unordered_map<data_t, int> HashTable;

  data_t buf;
  for (size_t i = 0; i < N_elem; i++)
  {
    cin >> buf;
    auto it = Hash_obj.find(buf);

    if (Hash_obj.get_size() < cache_size)
      HashTable.insert({buf, buf});
    else
    {
      if (it != HashTable.end())
      {
        cout << "Cache hit: " << buf << "\n";
      }
      else 
      {
        auto it = HashTable.begin();
        HashTable.erase(it->first);
        HashTable.insert({buf, buf});
      }
    }
  }

  return 0;
}