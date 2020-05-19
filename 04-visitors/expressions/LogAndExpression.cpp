#include "LogAndExpression.h"

LogAndExpression::LogAndExpression(Expression *e1, Expression *e2)
                                                    : first(e1), second(e2) {}

int LogAndExpression::eval() const {
  return first->eval() && second->eval();
}

void LogAndExpression::Accept(Visitor* visitor) {
  visitor->Visit(this);
}