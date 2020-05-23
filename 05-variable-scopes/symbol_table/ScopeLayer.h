#pragma once

#include "Symbol.h"
#include "objects/Method.h"
#include "objects/Object.h"

#include <unordered_map>
#include <string>
#include <memory>
#include <vector>
#include <set>
#include <map>

class ScopeLayer {
 public:
  explicit ScopeLayer(ScopeLayer *parent);
  ScopeLayer();
  void DeclareVariable(Symbol symbol, std::pair<std::string, bool> type);
  void DeclareClass(std::string name);
  void DeclareMethod(const std::string &id, MethodType m);
  void Put(Symbol symbol, std::shared_ptr<Object> value);
  void DeclareMethodInClass(std::string cl, std::string t, std::string id,
                            std::vector<std::pair<std::string, std::string>> args);

  void DeclareFieldInClass(std::string cl, std::string t, std::string id);
  std::shared_ptr<Object> Get(Symbol symbol);
  bool Has(Symbol symbol);
  std::pair<std::string, bool> GetType(std::string symbol);

  void AddChild(ScopeLayer *child);
  void AttachParent();

  ScopeLayer *GetChild(size_t index);
  ScopeLayer *GetParent() const;

  std::unordered_map<Symbol, std::shared_ptr<Object>> values_;
  std::unordered_map<Symbol, size_t> offsets_;
  std::vector<Symbol> symbols_;
  std::set<std::string> classes_;
  std::map<std::string, MethodType> methods_;
  std::map<std::string, Class> defined_classes;
  std::string name_;
  ScopeLayer *parent_;
  std::vector<ScopeLayer *> children_;
};