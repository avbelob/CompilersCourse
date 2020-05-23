#include "LvalueAssignStatement.h"

LvalueAssignStatement::LvalueAssignStatement(Lvalue* lvalue, Expression* expr)
        : lvalue_(lvalue)
        , expr_(expr)
{}

void LvalueAssignStatement::eval() const {}

void LvalueAssignStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}