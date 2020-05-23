#include "IsNotEqualExpression.h"

IsNotEqualExpression::IsNotEqualExpression(
        Expression *e1, Expression *e2
): first(e1), second(e2) {}

int IsNotEqualExpression::eval() const {
  return first->eval() != second->eval();
}

void IsNotEqualExpression::Accept(Visitor* visitor) {
  visitor->Visit(this);
}