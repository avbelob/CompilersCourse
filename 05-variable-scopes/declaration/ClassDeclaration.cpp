#include "ClassDeclaration.h"

ClassDeclaration::ClassDeclaration(const std::string &identifier,
                 const std::string &extra_identifier,
                 DeclarationList* declarations) :
identifier_(identifier), extra_identifier_(extra_identifier), declarations_
(declarations) {};

void ClassDeclaration::eval() const {}

void ClassDeclaration::Accept(Visitor* visitor) {
  visitor->Visit(this);
}