#include "NewExpression.h"

NewExpression::NewExpression(std::string type) : type_(type) {}

int NewExpression::eval() const {
}

void NewExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);
}