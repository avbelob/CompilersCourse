#pragma once

#include "VariableDeclaration.h"
#include "DeclarationList.h"
#include "../statement/Statement.h"
#include <string>

class ClassDeclaration : public Declaration {
 public:
  ClassDeclaration(const std::string &identifier,
                   const std::string &extra_identifier,
                   DeclarationList* declarations);

  void Accept(Visitor *visitor) override;

  void eval() const override;

  std::string identifier_;
  std::string extra_identifier_;
  DeclarationList* declarations_;
};