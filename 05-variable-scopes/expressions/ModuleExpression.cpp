#include "ModuleExpression.h"

ModuleExpression::ModuleExpression(
        Expression *e1, Expression *e2
): first(e1), second(e2) {}

int ModuleExpression::eval() const {
  return first->eval() % second->eval();
}

void ModuleExpression::Accept(Visitor* visitor) {
  visitor->Visit(this);
}