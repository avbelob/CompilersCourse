#pragma once

#include "declaration/VariableDeclaration.h"
#include "base_elements/BaseElement.h"
#include <vector>

class VariableDeclarationList : public BaseElement {
 public:
  void AddDeclaration(VariableDeclaration* variable_declaration);
  int Length();
  void Accept(Visitor* visitor);

  std::vector<VariableDeclaration*> variables_declarations_;
};