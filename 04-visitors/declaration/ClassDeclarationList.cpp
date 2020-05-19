#include "ClassDeclarationList.h"

void ClassDeclarationList::AddDeclaration(ClassDeclaration* class_declaration) {
  classes_declarations_.push_back(class_declaration);
}

int ClassDeclarationList::Length() {
  return classes_declarations_.size();
}

void ClassDeclarationList::Accept(Visitor* visitor) {
  visitor->Visit(this);
}