#include "ExpressionList.h"

void ExpressionList::AddExpression(Expression* expression) {
  expressions_.push_back(expression);
}

int ExpressionList::Length() {
  return expressions_.size();
}

void ExpressionList::Accept(Visitor* visitor) {
  visitor->Visit(this);
}