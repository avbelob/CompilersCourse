#pragma once

#include "Statement.h"
#include "../expressions/Expression.h"
#include "../lvalue/Lvalue.h"

class LvalueAssignStatement : public Statement {
 public:
  LvalueAssignStatement(Lvalue* lvalue, Expression* expr);
  void eval() const override;
  void Accept(Visitor* visitor) override;

  Lvalue* lvalue_;
  Expression* expr_;
};