#pragma once
#include "Expression.h"
#include <string>

class BoolExpression : public Expression {
 public:
  BoolExpression(const std::string& value);
  int eval() const override;
  void Accept(Visitor* visitor) override;
  bool value_;
};