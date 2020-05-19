%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <string>

    class Scanner;
    class Driver;

    class Expression;
    class ExpressionList;
    class NumberExpression;
    class BoolExpression;
    class IdentExpression;

    class AddExpression;
    class SubstractExpression;
    class MultExpression;
    class DivExpression;
    class ModuleExpression;
    class NegExpression;

    class LogAndExpression;
    class LogOrExpression;
    class LessExpression;
    class LargerExpression;
    class IsEqualExpression;
    class IsNotEqualExpression;

    class InRoundBrExpression;
    class InQBrExpression;

    class LengthExpression;
    class NewExpression;
    class NewArrayExpression;

    class MInvExpression;
    class ThisExpression;

    class Statement;
    class StatementList;
    class PrintlnStatement;
    class AssertStatement;

    class IfStatement;
    class IfElseStatement;
    class WhileStatement;
    class ReturnStatement;

    class LvalueAssignStatement;
    class LvalueStatement;

    class InCurBrStatement;

    class Program;
    class MainClass;

    class Declaration;
    class DeclarationList;
    class VariableDeclaration;
    class VariableDeclarationList;
    class ClassDeclaration;
    class ClassDeclarationList;
    class MethodDeclaration;

    class Lvalue;
    class IdentifierLvalue;
    class IdentifierListLvalue;
}

// %param { Driver &drv }

%define parse.trace
%define parse.error verbose

%code {
    #include "driver.hh"
    #include "location.hh"

    #include "expressions/Expression.h"
    #include "expressions/ExpressionList.h"
    #include "expressions/NumberExpression.h"
    #include "expressions/BoolExpression.h"
    #include "expressions/IdentExpression.h"

    #include "expressions/AddExpression.h"
    #include "expressions/SubstractExpression.h"
    #include "expressions/MultExpression.h"
    #include "expressions/DivExpression.h"
    #include "expressions/ModuleExpression.h"
    #include "expressions/NegExpression.h"

    #include "expressions/LogAndExpression.h"
    #include "expressions/LogOrExpression.h"
    #include "expressions/LessExpression.h"
    #include "expressions/LargerExpression.h"
    #include "expressions/IsEqualExpression.h"
    #include "expressions/IsNotEqualExpression.h"

    #include "expressions/InRoundBrExpression.h"
    #include "expressions/InQBrExpression.h"

    #include "expressions/LengthExpression.h"
    #include "expressions/NewExpression.h"
    #include "expressions/NewArrayExpression.h"

    #include "expressions/MInvExpression.h"
    #include "expressions/ThisExpression.h"

    #include "statement/Statement.h"
    #include "statement/StatementList.h"
    #include "statement/PrintlnStatement.h"
    #include "statement/AssertStatement.h"

    #include "statement/IfStatement.h"
    #include "statement/IfElseStatement.h"
    #include "statement/WhileStatement.h"
    #include "statement/ReturnStatement.h"

    #include "statement/LvalueAssignStatement.h"
    #include "statement/LvalueStatement.h"

    #include "statement/InCurBrStatement.h"

    #include "declaration/Declaration.h"
    #include "declaration/DeclarationList.h"
    #include "declaration/ClassDeclaration.h"
    #include "declaration/ClassDeclarationList.h"
    #include "declaration/MethodDeclaration.h"
    #include "declaration/VariableDeclaration.h"
    #include "declaration/VariableDeclarationList.h"

    #include "lvalue/Lvalue.h"
    #include "lvalue/IdentifierLvalue.h"
    #include "lvalue/IdentifierListLvalue.h"

    #include "Program.h"
    #include "MainClass.h"

    static yy::parser::symbol_type yylex(Scanner &scanner, Driver& driver) {
        return scanner.ScanToken();
    }
}

%lex-param { Scanner &scanner }
%lex-param { Driver &driver }
%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%locations

%define api.token.prefix {TOK_}

%token
        //arithmetic
        PLUS "+"
        MINUS "-"
        STAR "*"
        SLASH "/"
        MODULE "%"
        ASSIGN "="
        NEGATION "!"

        // logical and comparison operators
        LOGICALAND "&&"
        LOGICALOR "||"
        LESS "<"
        LARGER ">"
        ISEQUAL "=="
        ISNOTEQUAL "!="

        //brackets
        LROUNDBRACKET "("
        RROUNDBRACKET ")"
        LCURBRACKET "{"
        RCURBRACKET "}"
        LSQBRACKET "["
        RSQBRACKET "]"

        //type
        TYPEINT "int"
        TYPEBOOL "boolean"
        TYPEVOID "void"

        //words
        PRINTLN "System.out.println"
        MAIN "main"
        LENGTH "length"
        CLASS "class"
        PUBLIC "public"
        STATIC "static"
        ASSERT "assert"
        NEW "new"

        //other
        DOT "."
        SEMICOLON ";"
        COLON  ","
        IF "if"
        ELSE "else"
        WHILE "while"
        RETURN "return"
        THIS "this"

        TRUE "true"
        FALSE "false"
        END 0 "end of file"
;

%token <std::string> IDENTIFIER "identifier"
%token <int> NUMBER "number"
%nterm <int> signed_number
%nterm <std::string> logic
%nterm <std::string> type
%nterm <std::string> simple_type
%nterm <std::string> array_type
%nterm <std::string> type_identifier

%nterm <Expression*> expr
%nterm <ExpressionList*> expr_list

%nterm <Statement*> statement
%nterm <StatementList*> statements

%nterm <Declaration*> declaration
%nterm <DeclarationList*> declarations
%nterm <ClassDeclaration*> class_declaration
%nterm <ClassDeclarationList*> classes_declaration
%nterm <VariableDeclaration*> variable_declaration
%nterm <MethodDeclaration*> method_declaration
%nterm <VariableDeclaration*> type_and_identifiere
%nterm <VariableDeclarationList*> types_and_identifieres
%nterm <VariableDeclarationList*> formals
%nterm <Statement*> local_variable_declaration

%nterm <Lvalue*> lvalue

%nterm <MInvExpression*> method_invocation

%nterm <Program*> unit
%nterm <Program*> program

%nterm <MainClass*> main_class

// %printer { /*yyo << $$;*/ } <*>;

%left "||";
%left "&&";
%left "<" ">" "==" "!=" ;
%left "+" "-";
%left "*" "/" "%";

%precedence "identifier";
%precedence "[";
%precedence ".";
%precedence "length";
%precedence "else";


%%
%start unit;
unit: program {$$ = $1; driver.program = $1;};

program:
  main_class classes_declaration {$$ = new Program($1, $2);};

classes_declaration:
     %empty {$$ = new ClassDeclarationList(); }
     | classes_declaration class_declaration
     { $1->AddDeclaration($2); $$ = $1; };

main_class:
     "class" "identifier" "{"
         "public" "static" "void" "main" "(" ")" "{"
          statements "}"
     "}" {$$ = new MainClass($2, $11);};

statements:
    %empty {$$ = new StatementList();}
    | statements statement {  $1->AddStatement($2); $$ = $1;};

class_declaration:
    "class" "identifier" "{" declarations "}"
    { $$ = new ClassDeclaration($2, "", $4); }

    | "class" "identifier" "extends" "identifier" "{" declarations "}"
    { $$ = new ClassDeclaration($2, $4, $6); };

declarations:
    %empty {$$ = new DeclarationList(); }
    | declarations declaration { $1->AddDeclaration($2); $$ = $1; };

declaration:
    variable_declaration {$$ = $1;}
    | method_declaration {$$ = $1;};

variable_declaration:
    type "identifier" ";" {$$ = new VariableDeclaration($1, $2);};

method_declaration:
    "public" type "identifier" "(" ")" "{" statements "}"
    { $$ = new MethodDeclaration($2, $3, new VariableDeclarationList(), $7); };

    | "public" type "identifier" "(" formals ")" "{" statements "}"
    { $$ = new MethodDeclaration($2, $3, $5, $8); };

types_and_identifieres:
    type_and_identifiere {$$ = new VariableDeclarationList();
                          $$->AddDeclaration($1);};
    | types_and_identifieres "," type_and_identifiere {$1->AddDeclaration($3);
     $$ = $1;};

type_and_identifiere:
    type "identifier" {$$ = new VariableDeclaration($1, $2);};

formals:
    type "identifier" types_and_identifieres
    {$3->AddDeclaration(new VariableDeclaration($1, $2)); $$ = $3;};

type:
    simple_type {$$ = $1;}
    | array_type {$$ = $1;};

simple_type:
    "int" {$$ = "int";}
    | "boolean" {$$ = "boolean"; }
    | "void" {$$ = "void";}
    | type_identifier { $$ = $1;};

array_type:
    simple_type "[" "]" {$$ = $1;};

type_identifier:
    "identifier" {$$ = $1;};

statement:
    "assert" "(" expr ")" ";" { $$ = new AssertStatement($3); }
    | local_variable_declaration {$$ = $1;}
    | "{" statements "}" {$$ = new InCurBrStatement($2);}
    | "if"  "(" expr ")" statement {$$ = new IfStatement($3, $5);}
    | "if"  "(" expr ")" statement "else" statement
    {$$ = new IfElseStatement($3, $5, $7);}
    | "while"  "(" expr ")" statement
    {$$ = new WhileStatement($3, $5);}
    | "System.out.println" "(" expr ")" ";" { $$ = new PrintlnStatement($3);}
    | lvalue "=" expr ";" { $$ = new LvalueAssignStatement($1, $3);}
    | "return" expr ";" {$$ = new ReturnStatement($2);};
    //| method_invocation ";" {$$ = $1;};

local_variable_declaration:
    variable_declaration
    {VariableDeclaration* vd = $1;
     $$ = new LvalueStatement(vd->type_, vd->identifier_); };

method_invocation:
    expr "." "identifier" "(" ")"
    {$$ = new MInvExpression($1, $3, new ExpressionList()); }
    | expr "." "identifier" "(" expr_list ")"
    {$$ = new MInvExpression($1, $3, $5);};

expr_list:
    expr {$$ = new ExpressionList(); $$->AddExpression($1);}
    | expr_list "," expr {$1->AddExpression($3); $$ = $1; };

lvalue:
    "identifier" {$$ = new IdentifierLvalue($1);}
    | "identifier" "[" expr "]" {$$ = new IdentifierListLvalue($1, $3);};

signed_number:
    "-" "number" {$$ = -$2;}
    | "number" {$$ = $1;};

logic:
    "false" {$$ = "false";}
    | "true" {$$ = "true";};

expr:
expr "+" expr {$$ = new AddExpression($1, $3); }
  | expr "-" expr {$$ = new SubstractExpression($1, $3); }
  | expr "*" expr {$$ = new MultExpression($1, $3); }
  | expr "/" expr {$$ = new DivExpression($1, $3); }
  | expr "%" expr {$$ = new ModuleExpression($1, $3); }
  | expr "&&" expr {$$ = new LogAndExpression($1, $3); }
  | expr "||" expr {$$ = new LogOrExpression($1, $3); }
  | expr "<" expr {$$ = new LessExpression($1, $3); }
  | expr ">" expr {$$ = new LargerExpression($1, $3); }
  | expr "==" expr {$$ = new IsEqualExpression($1, $3); }
  | expr "!=" expr {$$ = new IsNotEqualExpression($1, $3); }
  | expr "[" expr "]" {$$ = new InQBrExpression($1, $3); }
  | method_invocation {$$ = $1;}
  | "new" simple_type "[" expr "]" {$$ = new NewArrayExpression($2, $4);}
  | "(" expr ")" {$$ = new InRoundBrExpression($2); }
  | "!" expr {$$ = new NegExpression($2); }

  | expr "." "length" {$$ = new LengthExpression($1);}
  | "new" type_identifier "(" ")" {$$ = new NewExpression($2);}
  | "identifier" {$$ = new IdentExpression($1);}
  | signed_number {$$ = new NumberExpression($1);}
  | "this" {$$ = new ThisExpression();}
  | logic {$$ = new BoolExpression($1);}
  ;

%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}