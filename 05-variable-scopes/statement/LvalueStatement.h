#pragma once

#include "Statement.h"
#include "../expressions/Expression.h"

class LvalueStatement : public Statement {
 public:
  LvalueStatement(const std::string& type, const std::string& id);
  void eval() const override;
  void Accept(Visitor* visitor) override;

  std::string type_;
  std::string identifier_;
};