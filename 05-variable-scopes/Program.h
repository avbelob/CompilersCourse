#pragma once

#include "base_elements/BaseElement.h"
#include "MainClass.h"
#include "declaration/ClassDeclaration.h"
#include "declaration/ClassDeclarationList.h"

class Program : public BaseElement {
 public:
  Program(MainClass* main_class, ClassDeclarationList* classes_declarations);
  void Accept(Visitor* visitor);

  MainClass* main_class_;
  ClassDeclarationList* classes_declarations_;
};