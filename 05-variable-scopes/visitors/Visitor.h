#pragma once

#include "forward_decl.h"

class Visitor {
 public:
  virtual void Visit(ExpressionList *expression) = 0;
  virtual void Visit(NumberExpression *expression) = 0;
  virtual void Visit(BoolExpression *expression) = 0;
  virtual void Visit(IdentExpression *expression) = 0;
  virtual void Visit(AddExpression *expression) = 0;
  virtual void Visit(SubstractExpression *expression) = 0;
  virtual void Visit(MultExpression *expression) = 0;
  virtual void Visit(DivExpression *expression) = 0;
  virtual void Visit(ModuleExpression *expression) = 0;
  virtual void Visit(NegExpression *expression) = 0;
  virtual void Visit(LogAndExpression *expression) = 0;
  virtual void Visit(LogOrExpression *expression) = 0;
  virtual void Visit(LessExpression *expression) = 0;
  virtual void Visit(LargerExpression *expression) = 0;
  virtual void Visit(IsEqualExpression *expression) = 0;
  virtual void Visit(IsNotEqualExpression *expression) = 0;
  virtual void Visit(InRoundBrExpression *expression) = 0;
  virtual void Visit(InQBrExpression *expression) = 0;
  virtual void Visit(LengthExpression *expression) = 0;
  virtual void Visit(NewExpression *expression) = 0;
  virtual void Visit(NewArrayExpression *expression) = 0;
  virtual void Visit(MInvExpression *expression) = 0;
  virtual void Visit(ThisExpression *expression) = 0;
  virtual void Visit(StatementList *statement_list) = 0;
  virtual void Visit(PrintlnStatement *statement) = 0;
  virtual void Visit(AssertStatement *statement) = 0;
  virtual void Visit(IfStatement *statement) = 0;
  virtual void Visit(IfElseStatement *statement) = 0;
  virtual void Visit(WhileStatement *statement) = 0;
  virtual void Visit(ReturnStatement *statement) = 0;
  virtual void Visit(LvalueAssignStatement *statement) = 0;
  virtual void Visit(LvalueStatement *statement) = 0;
  virtual void Visit(InCurBrStatement *statement) = 0;
  virtual void Visit(DeclarationList *declaration_list) = 0;
  virtual void Visit(ClassDeclaration *declaration) = 0;
  virtual void Visit(ClassDeclarationList *declaration_list) = 0;
  virtual void Visit(MethodDeclaration *declaration) = 0;
  virtual void Visit(VariableDeclaration *declaration) = 0;
  virtual void Visit(VariableDeclarationList *declaration_list) = 0;
  virtual void Visit(IdentifierLvalue *identifier) = 0;
  virtual void Visit(IdentifierListLvalue *identifier) = 0;
  virtual void Visit(MainClass *main_class) = 0;
  virtual void Visit(Program *program) = 0;
};
