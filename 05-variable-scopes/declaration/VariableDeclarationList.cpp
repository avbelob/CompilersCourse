#include "VariableDeclarationList.h"

void VariableDeclarationList::AddDeclaration(
        VariableDeclaration *variable_declaration) {
  variables_declarations_.push_back(variable_declaration);
}

int VariableDeclarationList::Length() {
  return variables_declarations_.size();
}

void VariableDeclarationList::Accept(Visitor *visitor) {
  visitor->Visit(this);
}