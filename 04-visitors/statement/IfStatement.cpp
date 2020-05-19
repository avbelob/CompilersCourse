#include "IfStatement.h"

IfStatement::IfStatement(Expression* expr, Statement* statement)
        : expr_(expr), statement_(statement) {}

void IfStatement::eval() const {
  if(expr_->eval()) {
    statement_->eval();
  }
}

void IfStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}