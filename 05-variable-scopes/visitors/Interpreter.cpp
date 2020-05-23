#include "Interpreter.h"

#include "elements.h"

#include <iostream>

Interpreter::Interpreter(ScopeLayer* root) : current_layer_(root) {
  offsets_.push(0);
  tos_value_ = 0;
}

void Interpreter::Visit(ExpressionList* expression_list) {
  for (Expression *expr : expression_list->expressions_) {
    expr->Accept(this);
  }
}

void Interpreter::Visit(NumberExpression *expression) {
  tos_value_ = expression->value_;
}

void Interpreter::Visit(BoolExpression* expression) {
  tos_value_ = expression->value_;
}

void Interpreter::Visit(IdentExpression *expression) {
  tos_value_ = current_layer_->Get(Symbol(expression->ident_))->ToInt();
}

void Interpreter::Visit(AddExpression *expression) {
  tos_value_ = Accept(expression->first) + Accept(expression->second);
}

void Interpreter::Visit(SubstractExpression *expression) {
  tos_value_ = Accept(expression->first) - Accept(expression->second);
}

void Interpreter::Visit(MultExpression *expression) {
  tos_value_ = Accept(expression->first) * Accept(expression->second);
}

void Interpreter::Visit(DivExpression *expression) {
  tos_value_ = Accept(expression->first) / Accept(expression->second);
}

void Interpreter::Visit(ModuleExpression *expression) {
  tos_value_ = Accept(expression->first) % Accept(expression->second);
}

void Interpreter::Visit(NegExpression* expression) {
  tos_value_ = !Accept(expression->expr_);
}

void Interpreter::Visit(LogAndExpression *expression) {
  tos_value_ = Accept(expression->first) && Accept(expression->second);
}

void Interpreter::Visit(LogOrExpression *expression) {
  tos_value_ = Accept(expression->first) || Accept(expression->second);
}

void Interpreter::Visit(LessExpression *expression) {
  tos_value_ = Accept(expression->first) < Accept(expression->second);
}

void Interpreter::Visit(LargerExpression *expression) {
  tos_value_ = Accept(expression->first) > Accept(expression->second);
}

void Interpreter::Visit(IsEqualExpression *expression) {
  tos_value_ = Accept(expression->first) == Accept(expression->second);
}

void Interpreter::Visit(IsNotEqualExpression *expression) {
  tos_value_ = Accept(expression->first) != Accept(expression->second);
}

void Interpreter::Visit(InRoundBrExpression* expression) {
  expression->expr_->Accept(this);
}

void Interpreter::Visit(InQBrExpression* expression) {
}

void Interpreter::Visit(LengthExpression* expression) {
  expression->expr_->Accept(this);
}

void Interpreter::Visit(NewExpression* expression) {
}

void Interpreter::Visit(NewArrayExpression* expression) {
  expression->expr_->Accept(this);
}

void Interpreter::Visit(MInvExpression* expression) {}

void Interpreter::Visit(ThisExpression* expression) {}

void Interpreter::Visit(StatementList* statement_list) {
  for (Statement *statement: statement_list->statements_) {
    statement->Accept(this);
  }
}

void Interpreter::Visit(PrintlnStatement* statement) {
  int value = Accept(statement->expr_);
  std::cout << value << std::endl;

}

void Interpreter::Visit(AssertStatement *statement) {
  int value = Accept(statement->expr_);
  std::cout << value << std::endl;
  if (!value) {
    std::cout << "Assertion Failed" << std::endl;
    exit(1);
  }
}

void Interpreter::Visit(IfStatement* statement) {
  statement->expr_->Accept(this);
  if (tos_value_) {
    statement->statement_->Accept(this);
  }
}

void Interpreter::Visit(IfElseStatement* statement) {
  if (Accept(statement->expr_)) {
    Accept(statement->pos_statement_);
  } else {
    Accept(statement->neg_statement_);
  }
}

void Interpreter::Visit(WhileStatement* statement) {
  while (Accept(statement->expr_)) {
    Accept(statement->statement_);
  }
}

void Interpreter::Visit(ReturnStatement* statement) {
  statement->expr_->Accept(this);
  exit(0);
}

void Interpreter::Visit(LvalueAssignStatement* statement) {
}

void Interpreter::Visit(LvalueStatement* statement) {
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
}

void Interpreter::Visit(ClassDeclaration* declaration) {}

void Interpreter::Visit(ClassDeclarationList* declaration_list ) {
  for (ClassDeclaration *declaration: declaration_list->classes_declarations_) {
    declaration->Accept(this);
  }
}

void Interpreter::Visit(MethodDeclaration* declaration) {}

void Interpreter::Visit(VariableDeclaration* declaration) {
}

void Interpreter::Visit(VariableDeclarationList* declaration_list ) {
  for (VariableDeclaration *declaration:
  declaration_list->variables_declarations_) {
    declaration->Accept(this);
  }
}

void Interpreter::Visit(IdentifierLvalue* identifier) {
}

void Interpreter::Visit(IdentifierListLvalue* identifier) {
}

void Interpreter::Visit(MainClass* main_class) {
  for (Statement* statement : main_class->statement_list_->statements_) {
    statement->Accept(this);
  }
}

void Interpreter::Visit(Program *program) {
  program->main_class_->Accept(this);
}

int Interpreter::GetResult(Program *program) {
  Visit(program);
  return tos_value_;
}