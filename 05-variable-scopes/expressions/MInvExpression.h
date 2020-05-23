#pragma once
#include "Expression.h"
#include "../statement/Statement.h"
#include <vector>

class MInvExpression : public Expression{
 public:
  MInvExpression(Expression* expr, const std::string& identifier,
          ExpressionList* expr_list);
  int eval() const override;
  void Accept(Visitor* visitor) override;

  Expression* expr_;
  std::string identifier_;
  ExpressionList* expr_list_;
};