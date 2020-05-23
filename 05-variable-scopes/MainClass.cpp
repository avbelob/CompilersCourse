#include "MainClass.h"

MainClass::MainClass(const std::string &identifier,
                     StatementList* statement_list)
        : identifier_(identifier), statement_list_(statement_list) {}

void MainClass::Accept(Visitor *visitor) {
  visitor->Visit(this);
}