#include "ThisExpression.h"

int ThisExpression::eval() const {}

void ThisExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);
}