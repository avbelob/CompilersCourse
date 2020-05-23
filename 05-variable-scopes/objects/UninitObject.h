#pragma once

#include "Object.h"


class UninitObject : public Object {
 public:
  UninitObject(std::string types, bool array);

  int ToInt() override;

  std::pair<std::string, bool> GetType() override;

  std::string type;
  bool is_array;
};