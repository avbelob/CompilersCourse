#pragma once

#include "declaration/Declaration.h"
#include "base_elements/BaseElement.h"
#include <vector>

class DeclarationList : public BaseElement {
 public:
  void AddDeclaration(Declaration* declaration);
  int Length();
  void Accept(Visitor* visitor);

  std::vector<Declaration*> declarations_;
};