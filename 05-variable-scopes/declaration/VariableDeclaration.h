#pragma once

#include "Declaration.h"
#include <string>

class VariableDeclaration : public Declaration {
 public:
  VariableDeclaration(const std::string &type, const std::string &identifier);

  void Accept(Visitor *visitor) override;

  void eval() const override;

  std::string type_;
  std::string identifier_;
};