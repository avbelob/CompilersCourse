#include "Types.h"

#include "elements.h"

#include <iostream>

Types::Types(ScopeLayer* tree) : tree_(tree) {
  current_layer_ = tree_.root_;
}

void Types::Visit(ExpressionList* expression_list) {
  for (Expression *expr : expression_list->expressions_) {
    expr->Accept(this);
  }
}

void Types::Visit(NumberExpression *expression) {
  tos_type = std::make_pair("int", false);
}

void Types::Visit(BoolExpression* expression) {
  tos_type = std::make_pair("boolean", false);
}

void Types::Visit(IdentExpression *expression) {
  auto id = current_layer_->Get(expression->ident_);
  tos_type = id->GetType();
}

void Types::Visit(AddExpression *expression) {
  expression->first->Accept(this);
  auto left = tos_type;
  expression->second->Accept(this);
  if (left != tos_type) {
    throw std::runtime_error("Different types of operands!");
  }
}

void Types::Visit(SubstractExpression *expression) {
  expression->first->Accept(this);
  auto left = tos_type;
  expression->second->Accept(this);
  if (left != tos_type) {
    throw std::runtime_error("Different types of operands!");
  }
}

void Types::Visit(MultExpression *expression) {
  expression->first->Accept(this);
  auto left = tos_type;
  expression->second->Accept(this);
  if (left != tos_type) {
    throw std::runtime_error("Different types of operands!");
  }
}

void Types::Visit(DivExpression *expression) {
  expression->first->Accept(this);
  auto left = tos_type;
  expression->second->Accept(this);
  if (left != tos_type) {
    throw std::runtime_error("Different types of operands!");
  }
}

void Types::Visit(ModuleExpression *expression) {
  expression->first->Accept(this);
  auto left = tos_type;
  expression->second->Accept(this);
  if (left != tos_type) {
    throw std::runtime_error("Different types of operands!");
  }
}

void Types::Visit(NegExpression* expression) {
  tos_type = std::make_pair("boolean", false);
}

void Types::Visit(LogAndExpression *expression) {
  expression->first->Accept(this);
  auto left = tos_type;
  expression->second->Accept(this);
  if (left != tos_type) {
    throw std::runtime_error("Different types of operands!");
  }
}

void Types::Visit(LogOrExpression *expression) {
  expression->first->Accept(this);
  auto left = tos_type;
  expression->second->Accept(this);
  if (left != tos_type) {
    throw std::runtime_error("Different types of operands!");
  }
}

void Types::Visit(LessExpression *expression) {
  expression->first->Accept(this);
  auto left = tos_type;
  expression->second->Accept(this);
  if (left != tos_type) {
    throw std::runtime_error("Different types of operands!");
  }
}

void Types::Visit(LargerExpression *expression) {
  expression->first->Accept(this);
  auto left = tos_type;
  expression->second->Accept(this);
  if (left != tos_type) {
    throw std::runtime_error("Different types of operands!");
  }
}

void Types::Visit(IsEqualExpression *expression) {
  expression->first->Accept(this);
  auto left = tos_type;
  expression->second->Accept(this);
  if (left != tos_type) {
    throw std::runtime_error("Different types of operands!");
  }
}

void Types::Visit(IsNotEqualExpression *expression) {
  expression->first->Accept(this);
  auto left = tos_type;
  expression->second->Accept(this);
  if (left != tos_type) {
    throw std::runtime_error("Different types of operands!");
  }
}

void Types::Visit(InRoundBrExpression* expression) {
  expression->expr_->Accept(this);
}

void Types::Visit(InQBrExpression* expression) {}

void Types::Visit(LengthExpression* expression) {}

void Types::Visit(NewExpression* expression) {
  tos_type = std::make_pair(expression->type_, false);
}

void Types::Visit(NewArrayExpression* expression) {
  tos_type = std::make_pair(expression->type_, false);
}

void Types::Visit(MInvExpression* expression) {
  expression->expr_->Accept(this);
  auto left = tos_type;

  ScopeLayer* cur = current_layer_;
  while (cur->defined_classes.find(left.first) == cur->defined_classes.end()
          && cur->parent_ != nullptr) {
    cur = cur->parent_;
  }
  if (cur->defined_classes.find(left.first) != cur->defined_classes.end()) {
    auto it = cur->defined_classes.find(left.first);
    for (auto m : it->second.methods_) {
      if (m.name_ == expression->identifier_) {
        tos_type = std::make_pair(m.type_, false);
      }
    }
  } else {
    throw std::runtime_error("No class");
  }
}

void Types::Visit(ThisExpression* expression) {}

void Types::Visit(StatementList* statement_list) {
  for (Statement *statement: statement_list->statements_) {
    statement->Accept(this);
  }
}

void Types::Visit(PrintlnStatement* statement) {}

void Types::Visit(AssertStatement *statement) {}

void Types::Visit(IfStatement* statement) {
  statement->statement_->Accept(this);
}

void Types::Visit(IfElseStatement* statement) {
  statement->pos_statement_->Accept(this);
  statement->neg_statement_->Accept(this);
}

void Types::Visit(WhileStatement* statement) {
  statement->statement_->Accept(this);
}

void Types::Visit(ReturnStatement* statement) {}

void Types::Visit(LvalueAssignStatement* statement) {
  statement->lvalue_->Accept(this);
  auto left = tos_type;
  statement->expr_->Accept(this);
  if (left != tos_type) {
    throw std::runtime_error("Different types in assigning");
  }
}

void Types::Visit(LvalueStatement* statement) {}

void Types::Visit(InCurBrStatement* statement) {
  offsets.push(0);
  current_layer_ = current_layer_->GetChild(offsets.top());
  for (size_t i = 0; i < statement->statement_list_->statements_.size(); ++i) {
    statement->statement_list_->statements_[i]->Accept(this);
  }
  size_t index = offsets.top() + 1;
  offsets.pop();
  offsets.push(index);
  current_layer_ = current_layer_->GetParent();
}

void Types::Visit(DeclarationList* declaration_list) {
  for (Declaration *declaration: declaration_list->declarations_) {
    declaration->Accept(this);
  }
}

void Types::Visit(ClassDeclaration* declaration) {}

void Types::Visit(ClassDeclarationList* declaration_list ) {
  for (ClassDeclaration *declaration: declaration_list->classes_declarations_) {
    declaration->Accept(this);
  }
}

void Types::Visit(MethodDeclaration* declaration) {
  offsets.push(0);
  current_layer_ = current_layer_->GetChild(offsets.top());
  for (Statement* statement : declaration->statements_list_->statements_) {
    statement->Accept(this);
  }
  size_t index = offsets.top() + 1;
  offsets.pop();
  offsets.push(index);
  current_layer_ = current_layer_->GetParent();
}

void Types::Visit(VariableDeclaration* declaration) {}

void Types::Visit(VariableDeclarationList* declaration_list ) {
  for (VariableDeclaration *declaration:
          declaration_list->variables_declarations_) {
    declaration->Accept(this);
  }
}

void Types::Visit(IdentifierLvalue* identifier) {
  auto id = current_layer_->Get(identifier->identifier_);
  tos_type = id->GetType();
}

void Types::Visit(IdentifierListLvalue* identifier) {
  tos_type = current_layer_->GetType(identifier->identifier_);
}

void Types::Visit(MainClass* main_class) {
  offsets.push(0);
  current_layer_ = current_layer_->GetChild(offsets.top());
  for (Statement* statement : main_class->statement_list_->statements_) {
    statement->Accept(this);
  }
  offsets.pop();
  current_layer_ = current_layer_->GetParent();
}

void Types::Visit(Program *program) {
  offsets.push(0);
  current_layer_ = current_layer_->GetChild(offsets.top());
  program->main_class_->Accept(this);
  current_layer_ = current_layer_->GetParent();
  offsets.pop();
  for (size_t i = 0; i < program->classes_declarations_->classes_declarations_.size(); ++i) {
    offsets.push(i + 1);
    current_layer_ = current_layer_->GetChild(offsets.top());
    program->classes_declarations_->classes_declarations_[i]->Accept(this);
    current_layer_ = current_layer_->GetParent();
    offsets.pop();
  }
}
