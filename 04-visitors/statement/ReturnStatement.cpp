#include "ReturnStatement.h"

ReturnStatement::ReturnStatement(Expression *expr) : expr_(expr) {}

void ReturnStatement::eval() const {}

void ReturnStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}