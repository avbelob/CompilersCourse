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
}

// %param { Driver &drv }

%define parse.trace
%define parse.error verbose

%code {
    #include "driver.hh"
    #include "location.hh"
    #include <cassert>

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

        // logical and comparison operators
        LOGICALAND "&&"
        LOGICALOR "||"
        LESS "<"
        LARGER ">"
        ISEQUAL "=="

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
        END 0 "end of file"
        SEMICOLON ";"
;

%token <std::string> IDENTIFIER "identifier"
%token <int> NUMBER "number"

%nterm <int> expr
%nterm <std::string> lvalue
%nterm <int> statements
%nterm <int> program

%printer { /*yyo << $$;*/ } <*>;

%left "+" "-";
%left "*" "/";


%%
%start unit;
unit: program { driver.result = $1; }

program:
     main_class classes_declaration;

classes_declaration:
     %empty {}
     | classes_declaration class_declaration {};

main_class:
     "class" "identifier" "{"
         "public" "static" "void" "main" "(" ")" "{"
          statements "}"
     "}" {};

statements:
    %empty {}
    | statements statement {};

class_declaration:
    "class" "identifier" "[" "extends" "identifier" "]" "{"
        declarations
    "}";

declarations:
    %empty {}
    | declarations declaration {};

declaration:
    variable_declaration | method_declaration;

method_declaration:
    "public" type "identifier" "(" [ formals ] ")" "{" statements "}";

variable_declaration:
    simple_type_declaration {}
    | array_type_declaration {};

simple_type_declaration:
    simple_type "identifier" ";" {
    if (driver.variables.find($2) == driver.variables.end() &&
            driver.array_variables.find($2) == driver.array_variables.end()) {
        driver.variables[$2] = 0;
    }
    };

array_type_declaration:
    array_type "identifier" ";" {
    if (driver.variables.find($2) == driver.variables.end() &&
            driver.array_variables.find($2) == driver.array_variables.end()) {
        driver.array_variables[$2] = std::vector<int>(1);
    }
    };

formals: type "identifier" types_and_identifieres;

types_and_identifieres:
    %empty {}
    | types_and_identifieres "," type "identifier" {};

type:
    simple_type {}
    | array_type {};

simple_type:
    "int"
    | "boolean"
    | "void"
    | type_identifier;

array_type:
    simple_type "[" "]";

type_identifier:
    "identifier";

statement:
    "assert" "(" expr ")" ";" { assert($3); } |
    local_variable_declaration {}
    | "{" statements "}" {}
    | "if"  "(" expr ")" statement
    | "if"  "(" expr ")" statement "else" statement
    | "while"  "(" expr ")" statement
    | "System.out.println" "(" expr ")" ";" { std::cout << $3 << std::endl; }
    | "identifier" "=" expr ";" {
        if (driver.variables.find($1) != driver.variables.end()){
            driver.variables[$1] = $3;
        } }
    | "identifier" "[" expr "]" "=" expr ";" {
        if (driver.array_variables.find($1) != driver.array_variables.end()){
            driver.array_variables[$1][$3] = $6;
        } }
    | "return" expr ";" {}
    | method_invocation ";" {} ;
    | "identifier" "=" "new" "int" "[" expr "]" ";" {
        if (driver.array_variables.find($1) != driver.array_variables.end()) {
            driver.array_variables[$1] = std::vector<int>($6);
        } }

local_variable_declaration: variable_declaration;

method_invocation:
    expr "." "identifier" "(" "[" expr expres "]" ")";

expres:
    %empty {}
    | expres "," expr {};

lvalue:
    "identifier" {$$ = $1; }
    | "identifier" "[" expr "]" {$$ = driver.array_variables[$1][$3]; };

expr:
    "number" {$$ = $1; }
    | expr "+" expr {$$ = $1 + $3; }
    | expr "-" expr {$$ = $1 - $3; }
    | expr "*" expr {$$ = $1 * $3; }
    | expr "/" expr {$$ = $1 / $3; }
    | expr "%" expr {$$ = $1 && $3; }
    | expr "&&" expr {$$ = $1 && $3; }
    | expr "||" expr {$$ = $1 || $3; }
    | expr "<" expr {$$ = $1 < $3; }
    | expr ">" expr {$$ = $1 > $3; }
    | expr "==" expr {$$ = $1 == $3; }
    | expr "[" expr "]"
    | "identifier" "." "length" {
    if (driver.array_variables.find($1) != driver.array_variables.end()) {
       $$ = driver.array_variables[$1].size();
    } }
    | "new" type_identifier "(" ")"
    | "!" expr
    | "(" expr ")"
    | "identifier" {$$ = driver.variables[$1]; }
    | "identifier" "[" expr "]" {$$ = driver.array_variables[$1][$3]; }
    | "this"  | "true"  | "false"
    | method_invocation;
%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}