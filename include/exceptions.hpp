
#pragma once 

#include <exception>
#include <string>

using namespace std;

class exception_empty : public exception {

  public:
    exception_empty(string ds_name = "data structure") {
      msg_ = "Oops! " + ds_name + " is empty.\n";
    }
   
    const char* what() const throw() {
      return msg_.c_str();
    }
   
  private:
    string msg_;
   
};


class exception_full : public exception {
 public:
   exception_full(string dsname = "data structure") {
     msg_ = "Oops! " + dsname + " is full.\n";
   }
   exception_full(int id): msg_("Error " + to_string(id)) {}

   const char* what() const throw() {
     return msg_.c_str();
   }

 private:
   string msg_;
};