#pragma once
#include "Expression.h"

class NegExpression : public Expression {
 public:
  NegExpression(Expression* expr);
  int eval() const override;
  void Accept(Visitor* visitor) override;

  Expression* expr_;
};