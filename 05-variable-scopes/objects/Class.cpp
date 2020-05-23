#include "Class.h"

Class ClassType::ToClass() { return {};
}

ClassType::ClassType(std::string type, bool array) : type(type), is_array(array) {}

std::pair<std::string, bool> ClassType::GetType() {
  return std::make_pair(type, is_array);
}