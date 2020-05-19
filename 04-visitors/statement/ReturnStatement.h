#pragma once

#include "Statement.h"
#include "../expressions/Expression.h"

class ReturnStatement : public Statement {
 public:
  ReturnStatement(Expression* expr);
  void eval() const override;
  void Accept(Visitor* visitor) override;

  Expression* expr_;
};