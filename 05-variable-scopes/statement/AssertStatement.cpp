#include "AssertStatement.h"

AssertStatement::AssertStatement(Expression* expr) : expr_(expr) {}

void AssertStatement::eval() const {
  assert(expr_->eval());
}

void AssertStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}