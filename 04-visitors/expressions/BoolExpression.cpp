#include "BoolExpression.h"

BoolExpression::BoolExpression(const std::string &value) {
  if (value == "true") {
    value_ = true;
  }
  else value_ = false;
}

int BoolExpression::eval() const {
  return value_;
}

void BoolExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);
}