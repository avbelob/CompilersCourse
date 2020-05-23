#include "IdentifierListLvalue.h"

IdentifierListLvalue::IdentifierListLvalue(const std::string &identifier,
                                           Expression *expr)
        : identifier_(identifier), expr_(expr) {}

void IdentifierListLvalue::Accept(Visitor *visitor) {
  visitor->Visit(this);
}