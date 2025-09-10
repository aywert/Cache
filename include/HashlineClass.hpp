#ifndef HASH_CLASS
#define HASH_CLASS

#include <iostream>
#include <unordered_map>
#include <list>

typedef int data_t; // using data_t = int;


class Hash_cl
{
  private:
  size_t size_; 
  size_t n_sells_;
  size_t n_hits_;

  std::list<int> cache_;                  // Cachelines
  std::unordered_map<int, int> hash_;

  public:
  Hash_cl() {size_ = 0; n_sells_ = 0;}; //default constructor
  Hash_cl(size_t size, size_t num_sells)  //explicit constructor
  {size_ = size; n_sells_ = num_sells;}; 

  ~Hash_cl() {};                        //default destructor
  
  void resize(size_t new_size);
  auto find(int key);
  size_t get_size(void) const ;
  bool is_full(void) {return size_ == hash_.size() ? true : false;}
  bool check_hash(int key);

};


#endif