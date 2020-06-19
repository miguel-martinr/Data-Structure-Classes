#pragma once

#include "dsc_base.hpp"

template <class T>
struct dsc_nodo {
  
  dsc_nodo(T data, dsc_nodo<T>* next): data_(data), next_(next) {}

  dsc_nodo<T>* next_;
  T data_;
};

template <class T>
class dsc_list : public dsc_base<T> {

 public:
   dsc_list(void): head_(NULL) {}

   void insert(const T&);
   T retrieve(void);
   ostream& write(ostream& os) const;
   bool empty(void) const;

 private:
    dsc_nodo<T>* head_;
};


template <class T>
void dsc_list<T>::insert(const T& element) {
  dsc_nodo<T>* ptr = new dsc_nodo<T>(element, head_);
  head_ = ptr;
}

template <class T>
T dsc_list<T>::retrieve(void) {
  if (empty())
    throw exception_empty("list");
    
  T data = head_->data_;
  dsc_nodo<T>* aux = head_;
  head_ = head_->next_;
  delete aux;
  return data;
  
}

template <class T>
ostream& dsc_list<T>::write(ostream& os) const {
  dsc_nodo<T>* aux = head_;
  while (aux != NULL) {
    os << endl << aux->data_ << endl;
    aux = aux->next_;
  }
  return os;
}

template <class T>
bool dsc_list<T>::empty(void) const {
  return (head_ == NULL);
}