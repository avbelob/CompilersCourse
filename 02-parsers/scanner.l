%{
    #include <cerrno>
    #include <climits>
    #include <cstdlib>
    #include <cstring> // strerror
    #include <string>
    #include <iostream>
    #include "driver.hh"
    #include "parser.hh"
%}

%option noyywrap nounput noinput batch debug

%option c++
%option yyclass="Scanner"

%{
  // A number symbol corresponding to the value in S.
  yy::parser::symbol_type make_NUMBER(
    const std::string &s,
    const yy::parser::location_type& loc
  );
%}

id    [a-zA-Z][a-zA-Z_0-9]*
integer   [0-9]+
blank [ \t\r]

%{
  // Code run each time a pattern is matched.
  # define YY_USER_ACTION  loc.columns (yyleng);
%}
%%
%{
  // A handy shortcut to the location held by the driver.
  yy::location& loc = driver.location;
  // Code run each time yylex is called.
  loc.step();
%}

{blank}+   loc.step ();
\n+        loc.lines (yyleng); loc.step ();

"+"        return yy::parser::make_PLUS   (loc);
"-"        return yy::parser::make_MINUS  (loc);
"*"        return yy::parser::make_STAR   (loc);
"/"        return yy::parser::make_SLASH  (loc);
"%"        return yy::parser::make_MODULE (loc);
"="        return yy::parser::make_ASSIGN (loc);

"&&"       return yy::parser::make_LOGICALAND (loc);
"||"       return yy::parser::make_LOGICALOR (loc);
"<"        return yy::parser::make_LESS (loc);
">"        return yy::parser::make_LARGER (loc);
"=="       return yy::parser::make_ISEQUAL (loc);

"("         return yy::parser::make_LROUNDBRACKET (loc);
")"         return yy::parser::make_RROUNDBRACKET (loc);
"{"         return yy::parser::make_LCURBRACKET (loc);
"}"         return yy::parser::make_RCURBRACKET (loc);
"["         return yy::parser::make_LSQBRACKET (loc);
"]"         return yy::parser::make_RSQBRACKET (loc);

"int" return yy::parser::make_TYPEINT (loc);
"boolean" return yy::parser::make_TYPEBOOL (loc);
"void" return yy::parser::make_TYPEVOID (loc);

[/][/].*\n      ; // small comment
[/].*[/]     ; // big comment

"System.out.println" return yy::parser::make_PRINTLN (loc);
"main" return yy::parser::make_MAIN (loc);
"length" return yy::parser::make_LENGTH (loc);
"class" return yy::parser::make_CLASS (loc);
"public"    return yy::parser::make_PUBLIC (loc);
"static"    return yy::parser::make_STATIC (loc);
"assert" return yy::parser::make_ASSERT (loc);
"new"       return yy::parser::make_NEW (loc);

"."         return yy::parser::make_DOT (loc);
";"        return yy::parser::make_SEMICOLON (loc);


{integer}  return make_NUMBER(yytext, loc);
{id}       return yy::parser::make_IDENTIFIER(yytext, loc);
.          {
                throw yy::parser::syntax_error(loc, "invalid character: " + std::string(yytext));
           }
<<EOF>>    return yy::parser::make_END (loc);
%%

yy::parser::symbol_type make_NUMBER(
  const std::string &s,
  const yy::parser::location_type& loc
) {
  errno = 0;
  long n = strtol(s.c_str(), NULL, 10);
  if (! (INT_MIN <= n && n <= INT_MAX && errno != ERANGE))
    throw yy::parser::syntax_error(loc, "integer is out of range: " + s);
  return yy::parser::make_NUMBER((int) n, loc);
}