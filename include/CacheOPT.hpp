#include <iostream>
#include <unordered_map>
#include <list>

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

  bool is_ideal; //defines should it work like idial one or not

  std::list<CacheLine> cache_;      
  
  using LstIt = typename std::list<CacheLine>::iterator;
  std::unordered_map<int, LstIt> hash_ls; // using hashtable for saving iterators isterad of numbers itself 
  
  
  public:
  Cache_OPT() : size_(0),               //default constructor
              n_sells_(0), 
              n_hits_(0), 
              is_ideal(true),
              cache_(),
              hash_ls() {};        
              
  Cache_OPT(size_t size, size_t num_sells, size_t hits = 0) : //explicit constructor
              size_(size), 
              n_sells_(num_sells), 
              n_hits_(hits), 
              is_ideal(false),
              cache_(),
              hash_ls() {}; 

  ~Cache_OPT() {};                     //default destructor
};
