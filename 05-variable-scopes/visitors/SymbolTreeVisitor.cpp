#include "SymbolTreeVisitor.h"

#include "elements.h"

#include <iostream>

#include "objects/Integer.h"
#include "objects/Boolean.h"
#include "objects/Class.h"
#include "objects/Method.h"
#include "objects/UninitObject.h"


SymbolTreeVisitor::SymbolTreeVisitor(): tree_(new ScopeLayer) {
    current_layer_ = tree_.root_;
}

void SymbolTreeVisitor::Visit(ExpressionList* expression) {}
void SymbolTreeVisitor::Visit(NumberExpression* expression) {}
void SymbolTreeVisitor::Visit(BoolExpression* expression) {}
void SymbolTreeVisitor::Visit(IdentExpression* expression) {}

void SymbolTreeVisitor::Visit(AddExpression* expression) {}
void SymbolTreeVisitor::Visit(SubstractExpression* expression) {}
void SymbolTreeVisitor::Visit(MultExpression* expression) {}
void SymbolTreeVisitor::Visit(DivExpression* expression) {}
void SymbolTreeVisitor::Visit(ModuleExpression* expression) {}
void SymbolTreeVisitor::Visit(NegExpression* expression) {}

void SymbolTreeVisitor::Visit(LogAndExpression* expression) {}
void SymbolTreeVisitor::Visit(LogOrExpression* expression) {}
void SymbolTreeVisitor::Visit(LessExpression* expression) {}
void SymbolTreeVisitor::Visit(LargerExpression* expression) {}
void SymbolTreeVisitor::Visit(IsEqualExpression* expression) {}
void SymbolTreeVisitor::Visit(IsNotEqualExpression* expression) {}

void SymbolTreeVisitor::Visit(InRoundBrExpression* expression) {}
void SymbolTreeVisitor::Visit(InQBrExpression* expression) {}

void SymbolTreeVisitor::Visit(LengthExpression* expression) {}
void SymbolTreeVisitor::Visit(NewExpression* expression) {}
void SymbolTreeVisitor::Visit(NewArrayExpression* expression) {}

void SymbolTreeVisitor::Visit(MInvExpression* expression) {}
void SymbolTreeVisitor::Visit(ThisExpression* expression) {}

void SymbolTreeVisitor::Visit(StatementList* statement_list) {
  for (Statement *statement: statement_list->statements_) {
    statement->Accept(this);
  }
}
void SymbolTreeVisitor::Visit(PrintlnStatement* statement) {}
void SymbolTreeVisitor::Visit(AssertStatement* statement) {}

void SymbolTreeVisitor::Visit(IfStatement* statement) {
  statement->expr_->Accept(this);
}
void SymbolTreeVisitor::Visit(IfElseStatement* statement) {
  statement->pos_statement_->Accept(this);
  statement->neg_statement_->Accept(this);
}
void SymbolTreeVisitor::Visit(WhileStatement* statement) {
  statement->statement_->Accept(this);
}
void SymbolTreeVisitor::Visit(ReturnStatement* statement) {}

void SymbolTreeVisitor::Visit(LvalueAssignStatement* statement) {}
void SymbolTreeVisitor::Visit(LvalueStatement* statement) {
  current_layer_->DeclareVariable(statement->identifier_, std::make_pair(statement->type_, false));
}

void SymbolTreeVisitor::Visit(InCurBrStatement* statement) {
  auto new_layer = new ScopeLayer(current_layer_);

  current_layer_ = new_layer;
  for (size_t i = 0; i < statement->statement_list_->statements_.size(); ++i) {
    statement->statement_list_->statements_[i]->Accept(this);
  }
  current_layer_ = current_layer_->GetParent();
}

void SymbolTreeVisitor::Visit(DeclarationList* declaration_list) {
  for (Declaration *declaration: declaration_list->declarations_) {
    declaration->Accept(this);
  }
}
void SymbolTreeVisitor::Visit(ClassDeclaration* declaration) {
  current_layer_->defined_classes[declaration->identifier_] = Class();
  cur_classes.push(declaration->identifier_);

  current_layer_->classes_.insert(declaration->identifier_);
  auto new_layer = new ScopeLayer(current_layer_);
  current_layer_ = new_layer;
  declaration->declarations_->Accept(this);

  current_layer_ = current_layer_->GetParent();
  cur_classes.pop();
}

void SymbolTreeVisitor::Visit(ClassDeclarationList* declaration_list) {
  for (ClassDeclaration *declaration: declaration_list->classes_declarations_) {
    declaration->Accept(this);
  }
}
void SymbolTreeVisitor::Visit(MethodDeclaration* declaration) {
  current_layer_->DeclareMethod(declaration->identifier_,
                                MethodType(declaration->type_,
                                           declaration->identifier_,
                                           declaration->variable_list_));

  current_layer_->DeclareMethodInClass(cur_classes.top(), declaration->type_,
                                       declaration->identifier_, {});

  current_layer_ = new ScopeLayer(current_layer_);
  for (Statement* statement : declaration->statements_list_->statements_) {
    statement->Accept(this);
  }
  current_layer_ = current_layer_->GetParent();
}
void SymbolTreeVisitor::Visit(VariableDeclaration* declaration) {
  current_layer_->DeclareVariable(declaration->identifier_, std::make_pair(declaration->type_, false));
}
void SymbolTreeVisitor::Visit(VariableDeclarationList* declaration_list) {
  for (VariableDeclaration *declaration:
          declaration_list->variables_declarations_) {
    declaration->Accept(this);
  }
}

void SymbolTreeVisitor::Visit(IdentifierLvalue* identifier) {}
void SymbolTreeVisitor::Visit(IdentifierListLvalue* identifier) {}

void SymbolTreeVisitor::Visit(MainClass* main_class) {
  current_layer_->DeclareMethodInClass(cur_classes.top(), "void", "main", {});

  current_layer_->DeclareMethod("main", MethodType("void", "main", {}));
  current_layer_ = new ScopeLayer(current_layer_);;

  for (Statement* statement : main_class->statement_list_->statements_) {
    statement->Accept(this);
  }

  current_layer_ = current_layer_->GetParent();
}
void SymbolTreeVisitor::Visit(Program* program) {
  current_layer_->defined_classes[program->main_class_->identifier_] = Class();
  cur_classes.push(program->main_class_->identifier_);

  current_layer_->classes_.insert(program->main_class_->identifier_);
  auto new_layer = new ScopeLayer(current_layer_);
  current_layer_ = new_layer;
  program->main_class_->Accept(this);
  current_layer_ = current_layer_->GetParent();

  cur_classes.pop();

  for (ClassDeclaration *declaration: program->classes_declarations_->classes_declarations_) {
    declaration->Accept(this);
  }
}

ScopeLayer* SymbolTreeVisitor::GetRoot() {
    return current_layer_;
}