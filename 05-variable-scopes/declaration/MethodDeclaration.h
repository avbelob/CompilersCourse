#pragma once

#include "VariableDeclaration.h"
#include "../statement/Statement.h"
#include <string>

class MethodDeclaration : public Declaration {
 public:
  MethodDeclaration(const std::string &type, const std::string &identifier,
                    VariableDeclarationList* variable_list,
                    StatementList* statements_list);
  void Accept(Visitor *visitor) override;

  void eval() const override;

  std::string type_;
  std::string identifier_;
  VariableDeclarationList* variable_list_;
  StatementList* statements_list_;
};