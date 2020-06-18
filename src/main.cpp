#include "../include/dsc_base.hpp"
#include "../include/dsc_array.hpp"
#include "../include/dsc_list.hpp"

#include <iostream>
#include <string>

using namespace std;

template <class T>
void dsc_move(dsc_base<T>* first, dsc_base<T>* second);


int main(int argc, char* argv[]) {

  dsc_base<int>* first = new dsc_array<int,20>();

  for (int i = 0; i < 20; i++)
    first->insert(i);



  dsc_base<int>* second = new dsc_list<int>;

/*  for (int i = 20; i < 40; i++)
    second->insert(i);
  */


  cout << "First: " << first << endl;
  dsc_move(first, second);
  cout << "Second: " << second<< endl;
  cout << "Esta es mi salida\n";
}


template <class T>
void dsc_move(dsc_base<T>* first, dsc_base<T>* second) {
  while(!first->empty()) 
    second->insert(first->retrieve());
}