#include "MethodDeclaration.h"

MethodDeclaration::MethodDeclaration(const std::string &type,
                                     const std::string &identifier,
                                     VariableDeclarationList* variable_list,
                                     StatementList* statements_list)
        : type_(type), identifier_(identifier),
          variable_list_(variable_list),
          statements_list_(statements_list) {}

void MethodDeclaration::eval() const {}

void MethodDeclaration::Accept(Visitor *visitor) {
  visitor->Visit(this);
}