#pragma once

#include "Statement.h"
#include "../expressions/Expression.h"
#include <assert.h>

class AssertStatement : public Statement {
 public:
  AssertStatement(Expression* expr);
  void Accept(Visitor* visitor) override;
  void eval() const override;
  Expression* expr_;
};