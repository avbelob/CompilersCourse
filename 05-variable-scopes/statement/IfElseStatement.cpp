#include "IfElseStatement.h"

IfElseStatement::IfElseStatement(Expression *expr, Statement *pos_statement,
                                 Statement *neg_statement)
        : expr_(expr),
          pos_statement_(pos_statement),
          neg_statement_(neg_statement) {}

void IfElseStatement::eval() const {
  if (expr_->eval()) {
    pos_statement_->eval();
  } else {
    neg_statement_->eval();
  }
}

void IfElseStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}