#pragma once

#include "statement/Statement.h"
#include "base_elements/BaseElement.h"
#include <vector>

class StatementList : public BaseElement {
 public:
  void AddStatement(Statement* statement);
  int Length();
  void Accept(Visitor* visitor);

  std::vector<Statement*> statements_;
};