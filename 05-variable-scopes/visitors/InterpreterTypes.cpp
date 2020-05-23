#include "InterpreterTypes.h"

#include "elements.h"

#include <iostream>

InterpreterTypes::InterpreterTypes(ScopeLayer* tree) : tree_(tree) {
  current_layer_ = tree_.root_;
}

void InterpreterTypes::Visit(ExpressionList* expression_list) {
  for (Expression *expr : expression_list->expressions_) {
    expr->Accept(this);
  }
}

void InterpreterTypes::Visit(NumberExpression *expression) {
  tos_value = std::make_shared<Integer>(expression->value_, false);
}

void InterpreterTypes::Visit(BoolExpression* expression) {
  tos_value = std::make_shared<Boolean>(expression->value_, false);
}

void InterpreterTypes::Visit(IdentExpression *expression) {
  id = expression->ident_;
  tos_value = current_layer_->Get(expression->ident_);
}

void InterpreterTypes::Visit(AddExpression *expression) {
  expression->first->Accept(this);
  auto left = tos_value;
  expression->second->Accept(this);
  tos_value =
          std::make_shared<Integer>(left->ToInt() + tos_value->ToInt(), false);
}

void InterpreterTypes::Visit(SubstractExpression *expression) {
  expression->first->Accept(this);
  auto left = tos_value;
  expression->second->Accept(this);
  tos_value =
          std::make_shared<Integer>(left->ToInt() - tos_value->ToInt(), false);
}

void InterpreterTypes::Visit(MultExpression *expression) {
  expression->first->Accept(this);
  auto left = tos_value;
  expression->second->Accept(this);
  tos_value =
          std::make_shared<Integer>(left->ToInt() * tos_value->ToInt(), false);
}

void InterpreterTypes::Visit(DivExpression *expression) {
  expression->first->Accept(this);
  auto left = tos_value;
  expression->second->Accept(this);
  tos_value =
          std::make_shared<Integer>(left->ToInt() / tos_value->ToInt(), false);
}

void InterpreterTypes::Visit(ModuleExpression *expression) {
  expression->first->Accept(this);
  auto left = tos_value;
  expression->second->Accept(this);
  tos_value =
          std::make_shared<Integer>(left->ToInt() % tos_value->ToInt(), false);
}

void InterpreterTypes::Visit(NegExpression* expression) {}

void InterpreterTypes::Visit(LogAndExpression *expression) {
  expression->first->Accept(this);
  auto left = tos_value;
  expression->second->Accept(this);
  if (tos_value->GetType().first == "int") {
    tos_value =
            std::make_shared<Boolean>(left->ToInt() && tos_value->ToInt(), false);
  } else {
    tos_value = std::make_shared<Boolean>(left && tos_value, false);
  }
}

void InterpreterTypes::Visit(LogOrExpression *expression) {
  expression->first->Accept(this);
  auto left = tos_value;
  expression->second->Accept(this);
  if (tos_value->GetType().first == "int") {
    tos_value =
            std::make_shared<Boolean>(left->ToInt() || tos_value->ToInt(), false);
  } else {
    tos_value = std::make_shared<Boolean>(left || tos_value, false);
  }
}

void InterpreterTypes::Visit(LessExpression *expression) {
  expression->first->Accept(this);
  auto left = tos_value;
  expression->second->Accept(this);
  if (tos_value->GetType().first == "int") {
    tos_value =
            std::make_shared<Boolean>(left->ToInt() < tos_value->ToInt(), false);
  } else {
    tos_value = std::make_shared<Boolean>(left < tos_value, false);
  }
}

void InterpreterTypes::Visit(LargerExpression *expression) {
  expression->first->Accept(this);
  auto left = tos_value;
  expression->second->Accept(this);
  if (tos_value->GetType().first == "int") {
    tos_value =
            std::make_shared<Boolean>(left->ToInt() > tos_value->ToInt(), false);
  } else {
    tos_value = std::make_shared<Boolean>(left > tos_value, false);
  }
}

void InterpreterTypes::Visit(IsEqualExpression *expression) {
  expression->first->Accept(this);
  auto left = tos_value;
  expression->second->Accept(this);
  if (tos_value->GetType().first == "int") {
    tos_value =
            std::make_shared<Boolean>(left->ToInt() == tos_value->ToInt(), false);
  } else {
    tos_value = std::make_shared<Boolean>(left == tos_value, false);
  }
}

void InterpreterTypes::Visit(IsNotEqualExpression *expression) {
  expression->first->Accept(this);
  auto left = tos_value;
  expression->second->Accept(this);
  if (tos_value->GetType().first == "int") {
    tos_value =
            std::make_shared<Boolean>(left->ToInt() != tos_value->ToInt(), false);
  } else {
    tos_value = std::make_shared<Boolean>(left != tos_value, false);
  }
}

void InterpreterTypes::Visit(InRoundBrExpression* expression) {
  expression->expr_->Accept(this);
}

void InterpreterTypes::Visit(InQBrExpression* expression) {}

void InterpreterTypes::Visit(LengthExpression* expression) {}

void InterpreterTypes::Visit(NewExpression* expression) {
  if (expression->type_ == "boolean") {
    tos_value = std::make_shared<Boolean>(false, false);
  } else if (expression->type_ == "int") {
    tos_value = std::make_shared<Integer>(0, false);
  } else {
    tos_value = std::make_shared<ClassType>(expression->type_, false);
  }
}

void InterpreterTypes::Visit(NewArrayExpression* expression) {}

void InterpreterTypes::Visit(MInvExpression* expression) {}

void InterpreterTypes::Visit(ThisExpression* expression) {}

void InterpreterTypes::Visit(StatementList* statement_list) {
  for (Statement *statement: statement_list->statements_) {
    statement->Accept(this);
  }
}

void InterpreterTypes::Visit(PrintlnStatement* statement) {
  statement->expr_->Accept(this);
  std::cout << tos_value->ToInt() << std::endl;
}

void InterpreterTypes::Visit(AssertStatement *statement) {}

void InterpreterTypes::Visit(IfStatement* statement) {
  statement->expr_->Accept(this);
  if (tos_value->ToBoolean()) {
    statement->statement_->Accept(this);
  }
}

void InterpreterTypes::Visit(IfElseStatement* statement) {
  statement->expr_->Accept(this);
  if (tos_value->ToBoolean()) {
    statement->pos_statement_->Accept(this);
  } else {
    statement->neg_statement_->Accept(this);
  }

}

void InterpreterTypes::Visit(WhileStatement* statement) {
  statement->expr_->Accept(this);
  while (tos_value->ToBoolean()) {
    statement->statement_->Accept(this);
  }
}

void InterpreterTypes::Visit(ReturnStatement* statement) {}

void InterpreterTypes::Visit(LvalueAssignStatement* statement) {
  statement->lvalue_->Accept(this);
  auto name = id;
  statement->expr_->Accept(this);
  current_layer_->Put(name, tos_value);
}

void InterpreterTypes::Visit(LvalueStatement* statement) {}

void InterpreterTypes::Visit(InCurBrStatement* statement) {
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

void InterpreterTypes::Visit(DeclarationList* declaration_list) {
  for (Declaration *declaration: declaration_list->declarations_) {
    declaration->Accept(this);
  }
}

void InterpreterTypes::Visit(ClassDeclaration* declaration) {}

void InterpreterTypes::Visit(ClassDeclarationList* declaration_list ) {
  for (ClassDeclaration *declaration: declaration_list->classes_declarations_) {
    declaration->Accept(this);
  }
}

void InterpreterTypes::Visit(MethodDeclaration* declaration) {
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

void InterpreterTypes::Visit(VariableDeclaration* declaration) {}

void InterpreterTypes::Visit(VariableDeclarationList* declaration_list ) {
  for (VariableDeclaration *declaration:
          declaration_list->variables_declarations_) {
    declaration->Accept(this);
  }
}

void InterpreterTypes::Visit(IdentifierLvalue* identifier) {
  id = identifier->identifier_;
  sz = 0;
}

void InterpreterTypes::Visit(IdentifierListLvalue* identifier) {
  id = identifier->identifier_;
  identifier->expr_->Accept(this);
  sz = tos_value->ToInt();
}

void InterpreterTypes::Visit(MainClass* main_class) {
  offsets.push(0);
  current_layer_ = current_layer_->GetChild(offsets.top());
  for (Statement* statement : main_class->statement_list_->statements_) {
    statement->Accept(this);
  }
  offsets.pop();
  current_layer_ = current_layer_->GetParent();
}

void InterpreterTypes::Visit(Program *program) {
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
