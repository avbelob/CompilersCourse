#pragma once

#include "Lvalue.h"
#include "../expressions/Expression.h"
#include <string>

class IdentifierListLvalue : public Lvalue {
 public:
  IdentifierListLvalue(const std::string& identifier, Expression* expr);
  void Accept(Visitor* visitor);

  std::string identifier_;
  Expression* expr_;
};
