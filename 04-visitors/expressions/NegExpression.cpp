#include "NegExpression.h"

NegExpression::NegExpression(Expression* expr) : expr_(expr) {}

int NegExpression::eval() const {
  return !expr_->eval();
}

void NegExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);
}