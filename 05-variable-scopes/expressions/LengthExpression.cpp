#include "LengthExpression.h"

LengthExpression::LengthExpression(Expression* expr) : expr_ (expr) {}

int LengthExpression::eval() const {}

void LengthExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);
}