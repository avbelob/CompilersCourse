#pragma once
#include "Expression.h"

class NewExpression : public Expression {
 public:
  NewExpression(std::string type);
  int eval() const override;
  void Accept(Visitor* visitor) override;
  std::string type_;
};