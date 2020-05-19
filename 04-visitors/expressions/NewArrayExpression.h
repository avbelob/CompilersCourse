#pragma once
#include "Expression.h"

class NewArrayExpression : public Expression {
 public:
  NewArrayExpression(std::string type, Expression* expr);
  int eval() const override;
  void Accept(Visitor* visitor) override;
  std::string type_;
  Expression* expr_;
};