#include "Object.h"
#include <iostream>

int Object::ToInt() {
  std::cout << "Error" << std::endl;
}

bool Object::ToBoolean() {
  std::cout << "Error" << std::endl;
}

Class Object::ToClass() {
  std::cout << "Error" << std::endl;
}

Method Object::ToMethod() {
  std::cout << "Error" << std::endl;
}

std::pair<std::string, bool> Object::GetType() {}