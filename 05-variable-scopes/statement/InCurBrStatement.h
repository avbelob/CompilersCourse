#pragma once

#include "Statement.h"
#include "../expressions/Expression.h"
#include "StatementList.h"

class InCurBrStatement : public Statement {
 public:
  InCurBrStatement(StatementList* statements);
  void eval() const override;
  void Accept(Visitor* visitor) override;

  StatementList* statement_list_;
};