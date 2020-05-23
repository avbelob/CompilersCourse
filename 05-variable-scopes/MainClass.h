#pragma once

#include "statement/Statement.h"
#include "statement/StatementList.h"
#include "base_elements/BaseElement.h"

#include <string>

class MainClass : public BaseElement {
 public:
  MainClass(const std::string &identifier,
            StatementList* statement_list);
  void Accept(Visitor* visitor) override;

  std::string identifier_;
  StatementList* statement_list_;
};