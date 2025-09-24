#include "../include/CacheOPTClass.hpp"

void Cache_OPT::get_vector_stdin(size_t arg_n)
  {
    size_t buf = 0;
    for (size_t i = 0; i < arg_n; i++)
    {
      std::cin >> buf;
      vector_.emplace_back(buf);
    }
  }

  void Cache_OPT::dump_vector(void)
  {
    std::cout << "vector_: | ";
    for (size_t i = 0; i < vector_.size(); i++)
      std::cout << vector_[i] << " | ";
  }