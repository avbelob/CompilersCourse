#include "DeclarationList.h"

void DeclarationList::AddDeclaration(Declaration* declaration) {
  declarations_.push_back(declaration);
}

int DeclarationList::Length() {
  return declarations_.size();
}

void DeclarationList::Accept(Visitor* visitor) {
  visitor->Visit(this);
}