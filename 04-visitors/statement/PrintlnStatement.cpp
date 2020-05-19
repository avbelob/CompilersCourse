#include "PrintlnStatement.h"

PrintlnStatement::PrintlnStatement(Expression* expr) : expr_(expr) {}

void PrintlnStatement::eval() const {
  std::cout<<expr_->eval();
}

void PrintlnStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}