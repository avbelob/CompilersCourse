#include "VariableDeclaration.h"

VariableDeclaration::VariableDeclaration
        (const std::string &type, const std::string &identifier)
        : type_(type), identifier_(identifier) {}

void VariableDeclaration::eval() const {}

void VariableDeclaration::Accept(Visitor *visitor) {
  visitor->Visit(this);
}