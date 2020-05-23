#include "IdentifierLvalue.h"

IdentifierLvalue::IdentifierLvalue(const std::string &identifier)
        : identifier_(identifier) {}

void IdentifierLvalue::Accept(Visitor *visitor) {
  visitor->Visit(this);
}