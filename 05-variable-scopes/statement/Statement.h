#pragma once
#include "base_elements/BaseElement.h"

class Statement : public BaseElement {
 public:
  virtual void eval() const = 0;
};