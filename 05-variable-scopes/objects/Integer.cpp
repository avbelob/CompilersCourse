#include "Integer.h"

Integer::Integer(int value, bool array): value_(value), is_array(array) {}

int Integer::ToInt() {
  return value_;
}

std::pair<std::string, bool> Integer::GetType() {
 return std::make_pair("int", is_array);
}