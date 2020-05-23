#include "StatementList.h"

void StatementList::AddStatement(Statement* statement) {
  statements_.push_back(statement);
}

int StatementList::Length() {
  return statements_.size();
}

void StatementList::Accept(Visitor* visitor) {
  visitor->Visit(this);
}