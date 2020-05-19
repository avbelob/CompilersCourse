#include "MInvExpression.h"

MInvExpression::MInvExpression(
        Expression* expr, const std::string& identifier,
        ExpressionList* expr_list)
        : expr_(std::move(expr)), identifier_(identifier), expr_list_(expr_list)
{}

int MInvExpression::eval() const {
}

void MInvExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);
}