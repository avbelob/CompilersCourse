#include "LogOrExpression.h"

LogOrExpression::LogOrExpression(
        Expression *e1, Expression *e2
): first(e1), second(e2) {}

int LogOrExpression::eval() const {
  return first->eval() || second->eval();
}

void LogOrExpression::Accept(Visitor* visitor) {
  visitor->Visit(this);
}