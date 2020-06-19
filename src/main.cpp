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





    

  dsc_base<int>* second = new dsc_list<int>;

  for (int i = 0; i < 40; i++)
    second->insert(i);
  


  cout << "Array: " << first << endl;
  dsc_move(second, first);
  cout << "List: " << second<< endl;
  for (int i = 0; i < 50; i++)
    second->retrieve();
  cout << "Esta es mi salida\n";
}


template <class T>
void dsc_move(dsc_base<T>* first, dsc_base<T>* second) {
  while(!first->empty()) 
  try
  {
    second->insert(first->retrieve());
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    return;
  }
}