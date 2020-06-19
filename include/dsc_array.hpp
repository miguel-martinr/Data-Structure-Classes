#pragma once

#include "dsc_base.hpp"
#include "exceptions.hpp"

#include <vector>

using namespace std;


template <class T, int N = 10>
class dsc_array : public dsc_base<T> {
 public:
   dsc_array(void): occ_(0) {}

   void insert(const T&);
   T retrieve(void);
   ostream& write(ostream&) const;


   bool empty(void) const;

 private:
  vector<T*> arr_ = vector<T*>(N);
  int occ_;
};


template <class T, int N>
void dsc_array<T,N>::insert(const T& element) {
  if (occ_ == arr_.size()) 
    throw exception_full("array");
  
  T* ptr = new T(element);
  arr_[occ_] = ptr;
  occ_++;
}

template <class T, int N>
T dsc_array<T,N>::retrieve(void) {
  if (empty()) 
    throw exception_empty("array");

  T aux = *(arr_[--occ_]); 
  delete arr_[occ_];
  return aux;
}

template <class T, int N>
ostream& dsc_array<T,N>::write(ostream& os) const {
  for (int i = 0; i < occ_; i++)
    os << endl << *arr_[i] << endl;
  return os;
}

template <class T, int N>
bool dsc_array<T,N>::empty(void) const{
  return (occ_ == 0);
}