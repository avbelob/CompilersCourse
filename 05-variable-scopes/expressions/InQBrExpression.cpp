#include "InQBrExpression.h"

InQBrExpression::InQBrExpression(Expression* e1, Expression* e2) :
        expr_first_(e1), expr_second_(e2){}

int InQBrExpression::eval() const {}

void InQBrExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);
}