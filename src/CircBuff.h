#ifndef CircBuff_H
#define CircBuff_H

#include <vector>
#include <numeric>
#include <functional>

// #define _DEBUG_1

#ifdef _DEBUG_1
#include <iostream>
#endif

class CircBuff{
private:
  std::vector<double> el;
  int current_pointer = 0;
  size_t buf_size;
public:
  CircBuff(size_t size){
    el.resize(size, 0);
    buf_size = size;
#ifdef _DEBUG_1
std::cout << "CircBuff initialized with size : " << el.size() << " : ";
  for(auto _el = el.begin(); _el!=el.end(); _el++){
    std::cout << *_el << " ";
  }
std::cout << std::endl;
#endif
  }
  void insert(double item){
    current_pointer =  (current_pointer + 1) % buf_size;
#ifdef _DEBUG_1
    std::cout << "Added element " << item << " at position << " << current_pointer << std::endl;
#endif
    el[current_pointer] = item;
  }
  double sum(){
    return std::accumulate(el.begin(), el.end(), 0.0, std::plus<double>());
  }
};
#endif
