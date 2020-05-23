#pragma once

#include "Statement.h"
#include "../expressions/Expression.h"
#include <iostream>

class PrintlnStatement : public Statement {
 public:
  PrintlnStatement(Expression* expr);
  void Accept(Visitor* visitor) override;
  void eval() const override;
  Expression* expr_;
};