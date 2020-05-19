#pragma once

#include "declaration/ClassDeclaration.h"
#include "base_elements/BaseElement.h"
#include <vector>

class ClassDeclarationList : public BaseElement {
 public:
  void AddDeclaration(ClassDeclaration* class_declaration);
  int Length();
  void Accept(Visitor* visitor);

  std::vector<ClassDeclaration*> classes_declarations_;
};