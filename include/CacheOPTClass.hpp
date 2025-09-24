#include <iostream>
#include <unordered_map>
#include <vector>

typedef int data_t; // using data_t = int;

struct CacheLine
{
  int key;
  int data;
};

class Cache_OPT
{
  private:
  size_t size_; 
  size_t n_sells_;
  size_t n_hits_;

  std::vector<int> vector;     
  
  //std::unordered_map<int, LstIt> hash_table; // using hashtable for saving iterators isterad of numbers itself 
  
  
  public:          
  Cache_OPT(size_t size, size_t num_sells, size_t hits = 0) : //explicit constructor
              size_(size), 
              n_sells_(num_sells), 
              n_hits_(hits) {}; 
              //hash_table() 
            

  int get_vector_stdin(void)
  {

  }

  ~Cache_OPT() {};                     //default destructor
};
