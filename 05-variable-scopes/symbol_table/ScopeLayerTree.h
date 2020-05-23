#pragma once

#include "ScopeLayer.h"

class ScopeLayerTree {
 public:
  explicit ScopeLayerTree(ScopeLayer* root);
  void Free(ScopeLayer* layer);
 public:
  ScopeLayer* root_;
};
