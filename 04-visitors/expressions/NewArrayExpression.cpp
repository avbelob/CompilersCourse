#include "NewArrayExpression.h"

NewArrayExpression::NewArrayExpression(std::string type, Expression* expr)
                                                  : type_(type), expr_(expr) {}

int NewArrayExpression::eval() const {
}

void NewArrayExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);
}