#pragma once

#include "visitors/Visitor.h"
#include <string>

class BaseElement {
 public:
    virtual void Accept(Visitor* visitor) = 0;
    virtual ~BaseElement() = default;
};
