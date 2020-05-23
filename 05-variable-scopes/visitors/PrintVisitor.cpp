#include "PrintVisitor.h"

#include "elements.h"

#include <iostream>

PrintVisitor::PrintVisitor(const std::string &filename) : stream_(
        filename) {
}

void PrintVisitor::Visit(ExpressionList *expression_list) {
  PrintTabs();
  stream_ << "ExpressionList: " << std::endl;

  ++num_tabs_;
  for (Expression *expr : expression_list->expressions_) {
    expr->Accept(this);
  }
  --num_tabs_;
}

void PrintVisitor::Visit(NumberExpression *expression) {
  PrintTabs();
  stream_ << "NumberExpression " << expression->value_ << std::endl;
}

void PrintVisitor::Visit(BoolExpression *expression) {
  PrintTabs();
  stream_ << "BoolExpression " << expression->value_ << std::endl;
}

void PrintVisitor::Visit(IdentExpression *expression) {
  PrintTabs();
  stream_ << "IdentExpression " << expression->ident_ << std::endl;
}

void PrintVisitor::Visit(AddExpression *expression) {
  PrintTabs();
  stream_ << "AddExpression is:" << std::endl;

  ++num_tabs_;
  expression->first->Accept(this);
  expression->second->Accept(this);
  --num_tabs_;
}

void PrintVisitor::Visit(SubstractExpression *expression) {
  PrintTabs();

  stream_ << "SubExpression: " << std::endl;
  ++num_tabs_;
  expression->first->Accept(this);
  expression->second->Accept(this);
  --num_tabs_;
}

void PrintVisitor::Visit(MultExpression *expression) {
  PrintTabs();

  stream_ << "MulExpression: " << std::endl;
  ++num_tabs_;
  expression->first->Accept(this);
  expression->second->Accept(this);
  --num_tabs_;
}

void PrintVisitor::Visit(DivExpression *expression) {
  PrintTabs();
  stream_ << "DivExpression: " << std::endl;
  ++num_tabs_;
  expression->first->Accept(this);
  expression->second->Accept(this);
  --num_tabs_;
}

void PrintVisitor::Visit(ModuleExpression *expression) {
  PrintTabs();
  stream_ << "ModuleExpression: " << std::endl;
  ++num_tabs_;
  expression->first->Accept(this);
  expression->second->Accept(this);
  --num_tabs_;
}

void PrintVisitor::Visit(NegExpression *expression) {
  PrintTabs();
  stream_ << "NegExpression: " << std::endl;
  ++num_tabs_;
  expression->expr_->Accept(this);
  --num_tabs_;
}

void PrintVisitor::Visit(LogAndExpression *expression) {
  PrintTabs();
  stream_ << "LogAndExpression: " << std::endl;
  ++num_tabs_;
  expression->first->Accept(this);
  expression->second->Accept(this);
  --num_tabs_;
}

void PrintVisitor::Visit(LogOrExpression *expression) {
  PrintTabs();
  stream_ << "LogOrExpression: " << std::endl;
  ++num_tabs_;
  expression->first->Accept(this);
  expression->second->Accept(this);
  --num_tabs_;
}

void PrintVisitor::Visit(LessExpression *expression) {
  PrintTabs();
  stream_ << "LessExpression: " << std::endl;
  ++num_tabs_;
  expression->first->Accept(this);
  expression->second->Accept(this);
  --num_tabs_;
}

void PrintVisitor::Visit(LargerExpression *expression) {
  PrintTabs();
  stream_ << "LargerExpression: " << std::endl;
  ++num_tabs_;
  expression->first->Accept(this);
  expression->second->Accept(this);
  --num_tabs_;
}

void PrintVisitor::Visit(IsEqualExpression *expression) {
  PrintTabs();
  stream_ << "IsEqualExpression: " << std::endl;
  ++num_tabs_;
  expression->first->Accept(this);
  expression->second->Accept(this);
  --num_tabs_;
}

void PrintVisitor::Visit(IsNotEqualExpression *expression) {
  PrintTabs();
  stream_ << "IsNotEqualExpression: " << std::endl;
  ++num_tabs_;
  expression->first->Accept(this);
  expression->second->Accept(this);
  --num_tabs_;
}

void PrintVisitor::Visit(InRoundBrExpression *expression) {
  PrintTabs();
  stream_ << "InRoundBrExpression: " << std::endl;
  ++num_tabs_;
  expression->expr_->Accept(this);
  --num_tabs_;
}

void PrintVisitor::Visit(InQBrExpression *expression) {
  PrintTabs();
  stream_ << "InQBrExpression: " << std::endl;
  ++num_tabs_;
  expression->expr_first_->Accept(this);
  expression->expr_second_->Accept(this);
  --num_tabs_;
}

void PrintVisitor::Visit(LengthExpression *expression) {
  PrintTabs();
  stream_ << "LengthExpression: " << std::endl;
  ++num_tabs_;
  expression->expr_->Accept(this);
  --num_tabs_;
}

void PrintVisitor::Visit(NewExpression *expression) {
  PrintTabs();
  stream_ << "NewExpression: " << std::endl;
  stream_ << expression->type_ << std::endl;
}

void PrintVisitor::Visit(NewArrayExpression *expression) {
  PrintTabs();
  stream_ << "NewArrayExpression: " << std::endl;
  stream_ << expression->type_ << std::endl;
  ++num_tabs_;
  expression->expr_->Accept(this);
  --num_tabs_;
}

void PrintVisitor::Visit(MInvExpression *expression) {
  PrintTabs();
  stream_ << "MInvExpression: " << std::endl;
  ++num_tabs_;
  expression->expr_->Accept(this);
  expression->expr_list_->Accept(this);
  --num_tabs_;
}

void PrintVisitor::Visit(ThisExpression *expression) {
  PrintTabs();
  stream_ << "ThisExpression: " << std::endl;
}

void PrintVisitor::Visit(StatementList *statement_list) {
  PrintTabs();
  stream_ << "StatementList: " << std::endl;

  ++num_tabs_;
  for (Statement *statement : statement_list->statements_) {
    statement->Accept(this);
  }
  --num_tabs_;
}

void PrintVisitor::Visit(PrintlnStatement *statement) {
  PrintTabs();
  stream_ << "PrintlnStatement: " << std::endl;
  ++num_tabs_;
  statement->expr_->Accept(this);
  --num_tabs_;
}

void PrintVisitor::Visit(AssertStatement *statement) {
  PrintTabs();
  stream_ << "AssertStatement: " << std::endl;
  ++num_tabs_;
  statement->expr_->Accept(this);
  --num_tabs_;
}

void PrintVisitor::Visit(IfStatement *statement) {
  PrintTabs();
  stream_ << "IfStatement: " << std::endl;
  ++num_tabs_;
  statement->expr_->Accept(this);
  statement->statement_->Accept(this);
  --num_tabs_;
}

void PrintVisitor::Visit(IfElseStatement *statement) {
  PrintTabs();
  stream_ << "IfElseStatement: " << std::endl;
  ++num_tabs_;
  statement->expr_->Accept(this);
  statement->pos_statement_->Accept(this);
  statement->neg_statement_->Accept(this);
  --num_tabs_;
}

void PrintVisitor::Visit(WhileStatement *statement) {
  PrintTabs();
  stream_ << "WhileStatement: " << std::endl;
  ++num_tabs_;
  statement->expr_->Accept(this);
  statement->statement_->Accept(this);
  --num_tabs_;
}

void PrintVisitor::Visit(ReturnStatement *statement) {
  PrintTabs();
  stream_ << "ReturnStatement: " << std::endl;
  ++num_tabs_;
  statement->expr_->Accept(this);
  --num_tabs_;
}

void PrintVisitor::Visit(LvalueAssignStatement *statement) {
  PrintTabs();
  stream_ << "LvalueAssignStatement: " << std::endl;
  ++num_tabs_;
  statement->lvalue_->Accept(this);
  statement->expr_->Accept(this);
  --num_tabs_;
}

void PrintVisitor::Visit(LvalueStatement *statement) {
  PrintTabs();
  stream_ << "LvalueStatement: " << std::endl;
  stream_ << statement->type_ << " ";
  stream_ << statement->identifier_ << std::endl;
}

void PrintVisitor::Visit(InCurBrStatement *statement) {
  PrintTabs();
  stream_ << "InCurBrStatement: " << std::endl;
  ++num_tabs_;
  statement->statement_list_->Accept(this);
  --num_tabs_;
}

void PrintVisitor::Visit(DeclarationList *declaration_list) {
  PrintTabs();
  stream_ << "DeclarationList: " << std::endl;

  ++num_tabs_;
  for (Declaration *declaration : declaration_list->declarations_) {
    declaration->Accept(this);
  }
  --num_tabs_;
}

void PrintVisitor::Visit(ClassDeclaration *declaration) {
  PrintTabs();
  stream_ << "ClassDeclaration: " << std::endl;

  stream_ << declaration->identifier_ << std::endl;
  stream_ << declaration->extra_identifier_ << std::endl;

  ++num_tabs_;
  declaration->declarations_->Accept(this);
  --num_tabs_;
}

void PrintVisitor::Visit(ClassDeclarationList *declaration_list) {
  PrintTabs();
  stream_ << "ClassDeclarationList: " << std::endl;

  ++num_tabs_;
  for (ClassDeclaration *declaration : declaration_list->classes_declarations_) {
    declaration->Accept(this);
  }
  --num_tabs_;
}

void PrintVisitor::Visit(MethodDeclaration *declaration) {
  PrintTabs();
  stream_ << "MethodDeclaration: " << std::endl;

  stream_ << declaration->type_ << std::endl;
  stream_ << declaration->identifier_ << std::endl;

  ++num_tabs_;
  declaration->variable_list_->Accept(this);
  declaration->statements_list_->Accept(this);
  --num_tabs_;
}

void PrintVisitor::Visit(VariableDeclaration *declaration) {
  PrintTabs();
  stream_ << "VariableDeclaration: " << std::endl;

  stream_ << declaration->type_ << std::endl;
  stream_ << declaration->identifier_ << std::endl;
}

void PrintVisitor::Visit(VariableDeclarationList *declaration_list) {
  PrintTabs();
  stream_ << "VariableDeclarationList: " << std::endl;

  ++num_tabs_;
  for (VariableDeclaration *declaration : declaration_list->variables_declarations_) {
    declaration->Accept(this);
  }
  --num_tabs_;
}

void PrintVisitor::Visit(IdentifierLvalue* identifier) {
  PrintTabs();
  stream_ << "IdentifierLvalue: " << std::endl;
  stream_ << identifier->identifier_ << std::endl;
}

void PrintVisitor::Visit(IdentifierListLvalue* identifier) {
  PrintTabs();
  stream_ << "IdentifierListLvalue: " << std::endl;
  stream_ << identifier->identifier_ << std::endl;

  ++num_tabs_;
  identifier->expr_->Accept(this);
  --num_tabs_;
}

void PrintVisitor::Visit(MainClass* main_class) {
  PrintTabs();
  stream_ << "MainClass: " << std::endl;
  stream_ << main_class->identifier_ << std::endl;

  ++num_tabs_;
  main_class->statement_list_->Accept(this);
  --num_tabs_;
}

void PrintVisitor::Visit(Program *program) {
  stream_ << "Program:" << std::endl;

  ++num_tabs_;

  program->main_class_->Accept(this);
  program->classes_declarations_->Accept(this);

  --num_tabs_;
}

void PrintVisitor::PrintTabs() {
  for (int i = 0; i < num_tabs_; ++i) {
    stream_ << '\t';
  }
}

PrintVisitor::~PrintVisitor() {
  stream_.close();
}