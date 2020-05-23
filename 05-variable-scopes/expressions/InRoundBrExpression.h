#pragma once
#include "Expression.h"

class InRoundBrExpression : public Expression {
 public:
  InRoundBrExpression(Expression* expr);
  int eval() const override;
  void Accept(Visitor* visitor) override;
  Expression* expr_;
};