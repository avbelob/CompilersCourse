#include "LargerExpression.h"

LargerExpression::LargerExpression(
        Expression *e1, Expression *e2
): first(e1), second(e2) {}

int LargerExpression::eval() const {
  return first->eval() > second->eval();
}

void LargerExpression::Accept(Visitor* visitor) {
  visitor->Visit(this);
}