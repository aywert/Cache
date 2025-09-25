#ifndef CACHE_OPT_CLASS
#define CACHE_OPT_CLASS

#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>

struct CacheLine_OPT
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
  size_t pos_in_vector_;
 
  std::list<CacheLine_OPT> cache_;
  using LstIt = typename std::list<CacheLine_OPT>::iterator;
  std::unordered_map<int, LstIt> hash_table;
  
  public:   
  std::vector<int> vector_;        
  Cache_OPT(size_t size, size_t num_sells, size_t hits = 0) : //explicit constructor
    size_(size), 
    n_sells_(num_sells), 
    n_hits_(hits),
    pos_in_vector_(0), 
    cache_(),
    hash_table(),
    vector_() {};
            
  ~Cache_OPT() {};                     //default destructor

  bool check_cache(int key);
  void get_vector(size_t arg_n, std::istream& input);
  void dump_vector(void);
  bool is_full(void) { return hash_table.size() == size_; };
  int select_key_func(void);
  size_t get_hits(void) const {return n_hits_;}

};

#endif