#include "Visitor.h"
#include "TemplateVisitor.h"
#include "symbol_table/Table.h"
#include "symbol_table/ScopeLayerTree.h"

#include <map>
#include <set>
#include <vector>
#include <stack>

class Interpreter : public TemplateVisitor<int> {
 public:
    Interpreter(ScopeLayer* tree);
    void Visit(ExpressionList* expression) override;
    void Visit(NumberExpression* expression) override;
    void Visit(BoolExpression* expression) override;
    void Visit(IdentExpression* expression) override;

    void Visit(AddExpression* expression) override;
    void Visit(SubstractExpression* expression) override;
    void Visit(MultExpression* expression) override;
    void Visit(DivExpression* expression) override;
    void Visit(ModuleExpression* expression) override;
    void Visit(NegExpression* expression) override;

    void Visit(LogAndExpression* expression) override;
    void Visit(LogOrExpression* expression) override;
    void Visit(LessExpression* expression) override;
    void Visit(LargerExpression* expression) override;
    void Visit(IsEqualExpression* expression) override;
    void Visit(IsNotEqualExpression* expression) override;

    void Visit(InRoundBrExpression* expression) override;
    void Visit(InQBrExpression* expression) override;

    void Visit(LengthExpression* expression) override;
    void Visit(NewExpression* expression) override;
    void Visit(NewArrayExpression* expression) override;

    void Visit(MInvExpression* expression) override;
    void Visit(ThisExpression* expression) override;

    void Visit(StatementList* statement_list) override;
    void Visit(PrintlnStatement* statement) override;
    void Visit(AssertStatement* statement) override;

    void Visit(IfStatement* statement) override;
    void Visit(IfElseStatement* statement) override;
    void Visit(WhileStatement* statement) override;
    void Visit(ReturnStatement* statement) override;

    void Visit(LvalueAssignStatement* statement) override;
    void Visit(LvalueStatement* statement) override;

    void Visit(InCurBrStatement* statement) override;

    void Visit(DeclarationList* declaration_list) override;
    void Visit(ClassDeclaration* declaration) override;
    void Visit(ClassDeclarationList* declaration_list) override;
    void Visit(MethodDeclaration* declaration) override;
    void Visit(VariableDeclaration* declaration) override;
    void Visit(VariableDeclarationList* declaration_list) override;

    void Visit(IdentifierLvalue* identifier) override;
    void Visit(IdentifierListLvalue* identifier) override;

    void Visit(MainClass* main_class) override;
    void Visit(Program* program) override;

    int GetResult(Program* program);

 private:
  ScopeLayer* current_layer_;

  std::stack<int> offsets_;

};