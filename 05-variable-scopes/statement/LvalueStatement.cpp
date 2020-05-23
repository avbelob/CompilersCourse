#include "LvalueStatement.h"

LvalueStatement::LvalueStatement(const std::string &type, const std::string &id)
        : type_(type), identifier_(id) {}

void LvalueStatement::eval() const {}

void LvalueStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}