#pragma once

#include "Object.h"
#include <declaration/VariableDeclaration.h>
#include <memory>

class MethodType : public Object {
 public:
  explicit MethodType( const std::string &type, const std::string &id,
                       VariableDeclarationList* input);

  MethodType() = default;

  Method ToMethod() override;

  std::pair<std::string, bool> GetType() override;

  VariableDeclarationList* var_list;
  std::string name;
  std::string type;
  bool is_array;
};