#pragma once 

#include <iostream>

using namespace std;

template <class T>
class dsc_base {

 public:


  virtual bool empty(void) const = 0;
  virtual void insert(const T&) = 0;
  virtual T retrieve(void) = 0;

  template <class F>
  friend ostream& operator<<(ostream& os, const dsc_base<F>* obj);
 
 
 
 private:
   virtual ostream& write(ostream&) const = 0;

};

template <class F>
ostream& operator<<(ostream& os, const dsc_base<F>* obj) {
  obj->write(os);
}