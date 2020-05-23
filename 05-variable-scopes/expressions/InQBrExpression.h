#pragma once
#include "Expression.h"

class InQBrExpression : public Expression {
 public:
  InQBrExpression(Expression* e1, Expression* e2);
  int eval() const override;
  void Accept(Visitor* visitor) override;
  Expression* expr_first_;
  Expression* expr_second_;
};