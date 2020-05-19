#include "WhileStatement.h"

WhileStatement::WhileStatement(Expression *expr, Statement *statement)
        : expr_(expr), statement_(statement) {}

void WhileStatement::eval() const {
  while (expr_->eval()) {
    statement_->eval();
  }
}

void WhileStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}