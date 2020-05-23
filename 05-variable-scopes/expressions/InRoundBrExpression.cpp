#include "InRoundBrExpression.h"

InRoundBrExpression::InRoundBrExpression(Expression* expr) : expr_(expr) {}

int InRoundBrExpression::eval() const {
  return expr_->eval();
}

void InRoundBrExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);
}