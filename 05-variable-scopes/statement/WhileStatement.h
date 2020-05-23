#pragma once

#include "Statement.h"
#include "../expressions/Expression.h"

class WhileStatement : public Statement {
 public:
  WhileStatement(Expression* expr, Statement* statement);
  void eval() const override;
  void Accept(Visitor* visitor) override;

  Expression* expr_;
  Statement* statement_;
};