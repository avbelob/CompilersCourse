#pragma once
#include "Expression.h"

class ThisExpression : public Expression {
 public:
  ThisExpression() = default;
  int eval() const override;
  void Accept(Visitor* visitor) override;
};