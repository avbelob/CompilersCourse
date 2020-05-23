
#include "Method.h"

Method MethodType::ToMethod() {
  return {};
}

MethodType::MethodType(const std::string &type, const std::string &id,
                       VariableDeclarationList* input)
        : type(type), name(id), var_list(input), is_array(false) {}

std::pair<std::string, bool> MethodType::GetType() {
  return std::make_pair(type, false);
}