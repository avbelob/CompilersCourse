#pragma once

#include "Lvalue.h"
#include <string>

class IdentifierLvalue : public Lvalue {
 public:
  IdentifierLvalue(const std::string& identifier);
  void Accept(Visitor* visitor) override;

  std::string identifier_;
};