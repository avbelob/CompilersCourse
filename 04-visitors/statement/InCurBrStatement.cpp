#include "InCurBrStatement.h"

InCurBrStatement::InCurBrStatement(StatementList* statements)
        : statement_list_(statements)
{}

void InCurBrStatement::eval() const {}
void InCurBrStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}