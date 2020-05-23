#pragma once
#include "Expression.h"
#include "ExpressionList.h"

class LengthExpression: public Expression {
 public:
  LengthExpression(Expression* expr_);
  int eval() const override;
  void Accept(Visitor* visitor) override;
  Expression* expr_;
};