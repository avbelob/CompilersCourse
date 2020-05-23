#pragma once

#include <string>
#include <vector>

class Field {
 public:
  Field() = default;
  Field(std::string type, std::string id) : type_(type), id_(id) {}
  std::string id_;
  std::string type_;
};


class Method {
 public:
  Method() = default;
  Method(std::string type, std::string name,
         std::vector<std::pair<std::string, std::string>> args)
         : name_(name), type_(type), args_(args) {}
  std::string name_;
  std::string type_;
  std::vector<std::pair<std::string, std::string>> args_;
};


class Class {
 public:
  std::vector<Field> fields_;
  std::vector<Method> methods_;
};

class Object {
 public:
  virtual int ToInt();
  virtual bool ToBoolean();
  virtual Class ToClass();
  virtual Method ToMethod();
  virtual std::pair<std::string, bool> GetType();
  virtual ~Object() = default;
};