#include "Interpreter.h"

#include "elements.h"

#include <iostream>

Interpreter::Interpreter() : variables_(std::map<std::string, int>()),
                             array_variables_(
                                     std::map<std::string, std::vector<int>>()),
                             declared_ids_(std::set<std::string>()),
                             is_tos_expression_(false), id_index_({}),
                             is_new_(false),
                             tos_value_(0) {}

void Interpreter::Visit(ExpressionList* expression_list) {
  for (Expression *expr : expression_list->expressions_) {
    expr->Accept(this);
  }
  UnsetTosValue();
}

void Interpreter::Visit(NumberExpression *expression) {
  SetTosValue(expression->value_);
}

void Interpreter::Visit(BoolExpression* expression) {
  SetTosValue(expression->value_);
}

void Interpreter::Visit(IdentExpression *expression) {
  int value = variables_[expression->ident_];

  SetTosValue(value);
}

void Interpreter::Visit(AddExpression *expression) {
  expression->first->Accept(this);
  int value = tos_value_;

  expression->second->Accept(this);
  value += tos_value_;
  SetTosValue(value);
}

void Interpreter::Visit(SubstractExpression *expression) {
  expression->first->Accept(this);
  int value = tos_value_;
  expression->second->Accept(this);
  value -= tos_value_;

  SetTosValue(value);
}

void Interpreter::Visit(MultExpression *expression) {
  expression->first->Accept(this);
  int value = tos_value_;
  expression->second->Accept(this);
  value *= tos_value_;

  SetTosValue(value);
}

void Interpreter::Visit(DivExpression *expression) {
  expression->first->Accept(this);
  int value = tos_value_;
  expression->second->Accept(this);
  value /= tos_value_;

  SetTosValue(value);
}

void Interpreter::Visit(ModuleExpression *expression) {
  expression->first->Accept(this);
  int value = tos_value_;
  expression->second->Accept(this);
  value %= tos_value_;

  SetTosValue(value);
}

void Interpreter::Visit(NegExpression* expression) {
  expression->expr_->Accept(this);
  int value = tos_value_;

  SetTosValue(!value);
}

void Interpreter::Visit(LogAndExpression *expression) {
  expression->first->Accept(this);
  int value = tos_value_;
  expression->second->Accept(this);
  value = value && tos_value_;

  SetTosValue(value);
}

void Interpreter::Visit(LogOrExpression *expression) {
  expression->first->Accept(this);
  int value = tos_value_;
  expression->second->Accept(this);
  value = value || tos_value_;

  SetTosValue(value);
}

void Interpreter::Visit(LessExpression *expression) {
  expression->first->Accept(this);
  int value = tos_value_;
  expression->second->Accept(this);
  value = value < tos_value_;

  SetTosValue(value);
}

void Interpreter::Visit(LargerExpression *expression) {
  expression->first->Accept(this);
  int value = tos_value_;
  expression->second->Accept(this);
  value = value > tos_value_;

  SetTosValue(value);
}

void Interpreter::Visit(IsEqualExpression *expression) {
  expression->first->Accept(this);
  int value = tos_value_;
  expression->second->Accept(this);
  value = value == tos_value_;

  SetTosValue(value);
}

void Interpreter::Visit(IsNotEqualExpression *expression) {
  expression->first->Accept(this);
  int value = tos_value_;
  expression->second->Accept(this);
  value = value != tos_value_;

  SetTosValue(value);
}

void Interpreter::Visit(InRoundBrExpression* expression) {
  expression->expr_->Accept(this);
  SetTosValue(tos_value_);
}

void Interpreter::Visit(InQBrExpression* expression) {
  expression->expr_first_->Accept(this);
  expression->expr_second_->Accept(this);
  if (array_variables_.find(id_index_.first) == array_variables_.end()) {
    std::cout << "Undeclared variable" << std::endl;
    exit(1);
  }
  SetTosValue(array_variables_[id_index_.first][tos_value_]);
}

void Interpreter::Visit(LengthExpression* expression) {
  expression->expr_->Accept(this);
  if (array_variables_.find(id_index_.first) == array_variables_.end()) {
    std::cout << "Undeclared variable" << std::endl;
    exit(1);
  }

  SetTosValue(array_variables_[id_index_.first].size());
}

void Interpreter::Visit(NewExpression* expression) {
  is_new_ = true;
  SetTosValue(0);
}

void Interpreter::Visit(NewArrayExpression* expression) {
  expression->expr_->Accept(this);
  is_new_ = true;
}

void Interpreter::Visit(MInvExpression* expression) {}

void Interpreter::Visit(ThisExpression* expression) {}

void Interpreter::Visit(StatementList* statement_list) {
  for (Statement *statement: statement_list->statements_) {
    statement->Accept(this);
  }
  UnsetTosValue();
}

void Interpreter::Visit(PrintlnStatement* statement) {
  statement->expr_->Accept(this);
  std::cout << tos_value_ << std::endl;
}

void Interpreter::Visit(AssertStatement *statement) {
  statement->expr_->Accept(this);
  std::cout << tos_value_ << std::endl;
  if (!tos_value_) {
    std::cout << "Assertion Failed" << std::endl;
    exit(1);
  }
  UnsetTosValue();
}

void Interpreter::Visit(IfStatement* statement) {
  statement->expr_->Accept(this);
  if (tos_value_) {
    statement->statement_->Accept(this);
  }
}

void Interpreter::Visit(IfElseStatement* statement) {
  statement->expr_->Accept(this);
  if (tos_value_) {
    statement->pos_statement_->Accept(this);
  }
  else {
    statement->neg_statement_->Accept(this);
  }
}

void Interpreter::Visit(WhileStatement* statement) {
  statement->expr_->Accept(this);
  while (tos_value_) {
    statement->statement_->Accept(this);
    statement->expr_->Accept(this);
  }
}

void Interpreter::Visit(ReturnStatement* statement) {
  statement->expr_->Accept(this);
  exit(0);
}

void Interpreter::Visit(LvalueAssignStatement* statement) {
  statement->lvalue_->Accept(this);
  auto lvalue = id_index_;
  statement->expr_->Accept(this);
  if (lvalue.second != -1) {
    array_variables_[lvalue.first][lvalue.second] = tos_value_;
  }
  if (is_new_) {
    array_variables_[lvalue.first] = std::vector<int>(tos_value_);
    is_new_ = false;
  }
  else {
    variables_[lvalue.first] = tos_value_;
  }
}

void Interpreter::Visit(LvalueStatement* statement) {
  declared_ids_.emplace(statement->identifier_);
}

void Interpreter::Visit(InCurBrStatement* statement) {
  for (size_t i = 0; i < statement->statement_list_->statements_.size(); ++i) {
    statement->statement_list_->statements_[i]->Accept(this);
  }
}

void Interpreter::Visit(DeclarationList* declaration_list) {
  for (Declaration *declaration: declaration_list->declarations_) {
    declaration->Accept(this);
  }
  UnsetTosValue();
}

void Interpreter::Visit(ClassDeclaration* declaration) {}

void Interpreter::Visit(ClassDeclarationList* declaration_list ) {
  for (ClassDeclaration *declaration: declaration_list->classes_declarations_) {
    declaration->Accept(this);
  }
  UnsetTosValue();
}

void Interpreter::Visit(MethodDeclaration* declaration) {}

void Interpreter::Visit(VariableDeclaration* declaration) {
  declared_ids_.emplace(declaration->identifier_);
}

void Interpreter::Visit(VariableDeclarationList* declaration_list ) {
  for (VariableDeclaration *declaration:
  declaration_list->variables_declarations_) {
    declaration->Accept(this);
  }
  UnsetTosValue();
}

void Interpreter::Visit(IdentifierLvalue* identifier) {
  id_index_.first = identifier->identifier_;
  id_index_.second = -1;
  UnsetTosValue();
}

void Interpreter::Visit(IdentifierListLvalue* identifier) {
  identifier->expr_->Accept(this);
  id_index_.first = identifier->identifier_;
  id_index_.second = tos_value_;
  UnsetTosValue();
}

void Interpreter::Visit(MainClass* main_class) {
  for (Statement* statement : main_class->statement_list_->statements_) {
    statement->Accept(this);
  }
}

void Interpreter::Visit(Program *program) {
  program->main_class_->Accept(this);
}

void Interpreter::SetTosValue(int value) {
  tos_value_ = value;
  is_tos_expression_ = true;
}

void Interpreter::UnsetTosValue() {
  tos_value_ = 0;
  is_tos_expression_ = false;
}

int Interpreter::GetResult(Program *program) {
  UnsetTosValue();
  Visit(program);
  return tos_value_;
}