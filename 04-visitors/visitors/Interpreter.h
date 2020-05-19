#include "Visitor.h"

#include <map>
#include <set>
#include <vector>

class Interpreter : public Visitor {
 public:
    Interpreter();
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
    std::map<std::string, int> variables_;
    std::map<std::string, std::vector<int>> array_variables_;
    std::set<std::string> declared_ids_;
    bool is_tos_expression_;
    int tos_value_;
    bool is_new_;
    std::pair<std::string, int> id_index_;

    void SetTosValue(int value);
    void UnsetTosValue();

};