#pragma once
#include "../base_elements/BaseElement.h"

class Declaration : public BaseElement {
 public:
  virtual void eval() const = 0;
};