#pragma once

#include "expressions/Expression.h"
#include "base_elements/BaseElement.h"
#include <vector>

class ExpressionList : public BaseElement {
 public:
  void AddExpression(Expression* expression);
  int Length();
  void Accept(Visitor* visitor);

  std::vector<Expression*> expressions_;
};