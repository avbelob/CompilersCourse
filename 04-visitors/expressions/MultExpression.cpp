#include "MultExpression.h"

MultExpression::MultExpression(
    Expression *e1, Expression *e2
): first(e1), second(e2) {}

int MultExpression::eval() const {
    return first->eval() * second->eval();
}

void MultExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}