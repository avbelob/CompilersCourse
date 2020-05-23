#pragma once

#include "Statement.h"
#include "../expressions/Expression.h"

class IfElseStatement : public Statement {
 public:
  IfElseStatement(Expression *expr, Statement *pos_statement,
                  Statement *neg_statement);

  void eval() const override;

  void Accept(Visitor *visitor) override;

  Expression *expr_;
  Statement *pos_statement_;
  Statement *neg_statement_;
};