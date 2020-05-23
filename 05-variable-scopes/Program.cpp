#include "Program.h"

Program::Program(MainClass *main_class,
                 ClassDeclarationList* classes_declarations)
        : main_class_(main_class),
          classes_declarations_(classes_declarations) {}

void Program::Accept(Visitor *visitor) {
  visitor->Visit(this);
}