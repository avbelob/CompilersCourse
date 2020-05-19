// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "parser.hh"


// Unqualified %code blocks.
#line 81 "parser.y"

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

#line 114 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 205 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser (Scanner &scanner_yyarg, Driver &driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 59: // class_declaration
        value.YY_MOVE_OR_COPY< ClassDeclaration* > (YY_MOVE (that.value));
        break;

      case 60: // classes_declaration
        value.YY_MOVE_OR_COPY< ClassDeclarationList* > (YY_MOVE (that.value));
        break;

      case 57: // declaration
        value.YY_MOVE_OR_COPY< Declaration* > (YY_MOVE (that.value));
        break;

      case 58: // declarations
        value.YY_MOVE_OR_COPY< DeclarationList* > (YY_MOVE (that.value));
        break;

      case 53: // expr
        value.YY_MOVE_OR_COPY< Expression* > (YY_MOVE (that.value));
        break;

      case 54: // expr_list
        value.YY_MOVE_OR_COPY< ExpressionList* > (YY_MOVE (that.value));
        break;

      case 67: // lvalue
        value.YY_MOVE_OR_COPY< Lvalue* > (YY_MOVE (that.value));
        break;

      case 68: // method_invocation
        value.YY_MOVE_OR_COPY< MInvExpression* > (YY_MOVE (that.value));
        break;

      case 71: // main_class
        value.YY_MOVE_OR_COPY< MainClass* > (YY_MOVE (that.value));
        break;

      case 62: // method_declaration
        value.YY_MOVE_OR_COPY< MethodDeclaration* > (YY_MOVE (that.value));
        break;

      case 69: // unit
      case 70: // program
        value.YY_MOVE_OR_COPY< Program* > (YY_MOVE (that.value));
        break;

      case 55: // statement
      case 66: // local_variable_declaration
        value.YY_MOVE_OR_COPY< Statement* > (YY_MOVE (that.value));
        break;

      case 56: // statements
        value.YY_MOVE_OR_COPY< StatementList* > (YY_MOVE (that.value));
        break;

      case 61: // variable_declaration
      case 63: // type_and_identifiere
        value.YY_MOVE_OR_COPY< VariableDeclaration* > (YY_MOVE (that.value));
        break;

      case 64: // types_and_identifieres
      case 65: // formals
        value.YY_MOVE_OR_COPY< VariableDeclarationList* > (YY_MOVE (that.value));
        break;

      case 44: // "number"
      case 47: // signed_number
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 43: // "identifier"
      case 48: // logic
      case 49: // type
      case 50: // simple_type
      case 51: // array_type
      case 52: // type_identifier
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 59: // class_declaration
        value.move< ClassDeclaration* > (YY_MOVE (that.value));
        break;

      case 60: // classes_declaration
        value.move< ClassDeclarationList* > (YY_MOVE (that.value));
        break;

      case 57: // declaration
        value.move< Declaration* > (YY_MOVE (that.value));
        break;

      case 58: // declarations
        value.move< DeclarationList* > (YY_MOVE (that.value));
        break;

      case 53: // expr
        value.move< Expression* > (YY_MOVE (that.value));
        break;

      case 54: // expr_list
        value.move< ExpressionList* > (YY_MOVE (that.value));
        break;

      case 67: // lvalue
        value.move< Lvalue* > (YY_MOVE (that.value));
        break;

      case 68: // method_invocation
        value.move< MInvExpression* > (YY_MOVE (that.value));
        break;

      case 71: // main_class
        value.move< MainClass* > (YY_MOVE (that.value));
        break;

      case 62: // method_declaration
        value.move< MethodDeclaration* > (YY_MOVE (that.value));
        break;

      case 69: // unit
      case 70: // program
        value.move< Program* > (YY_MOVE (that.value));
        break;

      case 55: // statement
      case 66: // local_variable_declaration
        value.move< Statement* > (YY_MOVE (that.value));
        break;

      case 56: // statements
        value.move< StatementList* > (YY_MOVE (that.value));
        break;

      case 61: // variable_declaration
      case 63: // type_and_identifiere
        value.move< VariableDeclaration* > (YY_MOVE (that.value));
        break;

      case 64: // types_and_identifieres
      case 65: // formals
        value.move< VariableDeclarationList* > (YY_MOVE (that.value));
        break;

      case 44: // "number"
      case 47: // signed_number
        value.move< int > (YY_MOVE (that.value));
        break;

      case 43: // "identifier"
      case 48: // logic
      case 49: // type
      case 50: // simple_type
      case 51: // array_type
      case 52: // type_identifier
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 59: // class_declaration
        value.copy< ClassDeclaration* > (that.value);
        break;

      case 60: // classes_declaration
        value.copy< ClassDeclarationList* > (that.value);
        break;

      case 57: // declaration
        value.copy< Declaration* > (that.value);
        break;

      case 58: // declarations
        value.copy< DeclarationList* > (that.value);
        break;

      case 53: // expr
        value.copy< Expression* > (that.value);
        break;

      case 54: // expr_list
        value.copy< ExpressionList* > (that.value);
        break;

      case 67: // lvalue
        value.copy< Lvalue* > (that.value);
        break;

      case 68: // method_invocation
        value.copy< MInvExpression* > (that.value);
        break;

      case 71: // main_class
        value.copy< MainClass* > (that.value);
        break;

      case 62: // method_declaration
        value.copy< MethodDeclaration* > (that.value);
        break;

      case 69: // unit
      case 70: // program
        value.copy< Program* > (that.value);
        break;

      case 55: // statement
      case 66: // local_variable_declaration
        value.copy< Statement* > (that.value);
        break;

      case 56: // statements
        value.copy< StatementList* > (that.value);
        break;

      case 61: // variable_declaration
      case 63: // type_and_identifiere
        value.copy< VariableDeclaration* > (that.value);
        break;

      case 64: // types_and_identifieres
      case 65: // formals
        value.copy< VariableDeclarationList* > (that.value);
        break;

      case 44: // "number"
      case 47: // signed_number
        value.copy< int > (that.value);
        break;

      case 43: // "identifier"
      case 48: // logic
      case 49: // type
      case 50: // simple_type
      case 51: // array_type
      case 52: // type_identifier
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 59: // class_declaration
        value.move< ClassDeclaration* > (that.value);
        break;

      case 60: // classes_declaration
        value.move< ClassDeclarationList* > (that.value);
        break;

      case 57: // declaration
        value.move< Declaration* > (that.value);
        break;

      case 58: // declarations
        value.move< DeclarationList* > (that.value);
        break;

      case 53: // expr
        value.move< Expression* > (that.value);
        break;

      case 54: // expr_list
        value.move< ExpressionList* > (that.value);
        break;

      case 67: // lvalue
        value.move< Lvalue* > (that.value);
        break;

      case 68: // method_invocation
        value.move< MInvExpression* > (that.value);
        break;

      case 71: // main_class
        value.move< MainClass* > (that.value);
        break;

      case 62: // method_declaration
        value.move< MethodDeclaration* > (that.value);
        break;

      case 69: // unit
      case 70: // program
        value.move< Program* > (that.value);
        break;

      case 55: // statement
      case 66: // local_variable_declaration
        value.move< Statement* > (that.value);
        break;

      case 56: // statements
        value.move< StatementList* > (that.value);
        break;

      case 61: // variable_declaration
      case 63: // type_and_identifiere
        value.move< VariableDeclaration* > (that.value);
        break;

      case 64: // types_and_identifieres
      case 65: // formals
        value.move< VariableDeclarationList* > (that.value);
        break;

      case 44: // "number"
      case 47: // signed_number
        value.move< int > (that.value);
        break;

      case 43: // "identifier"
      case 48: // logic
      case 49: // type
      case 50: // simple_type
      case 51: // array_type
      case 52: // type_identifier
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (scanner, driver));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 59: // class_declaration
        yylhs.value.emplace< ClassDeclaration* > ();
        break;

      case 60: // classes_declaration
        yylhs.value.emplace< ClassDeclarationList* > ();
        break;

      case 57: // declaration
        yylhs.value.emplace< Declaration* > ();
        break;

      case 58: // declarations
        yylhs.value.emplace< DeclarationList* > ();
        break;

      case 53: // expr
        yylhs.value.emplace< Expression* > ();
        break;

      case 54: // expr_list
        yylhs.value.emplace< ExpressionList* > ();
        break;

      case 67: // lvalue
        yylhs.value.emplace< Lvalue* > ();
        break;

      case 68: // method_invocation
        yylhs.value.emplace< MInvExpression* > ();
        break;

      case 71: // main_class
        yylhs.value.emplace< MainClass* > ();
        break;

      case 62: // method_declaration
        yylhs.value.emplace< MethodDeclaration* > ();
        break;

      case 69: // unit
      case 70: // program
        yylhs.value.emplace< Program* > ();
        break;

      case 55: // statement
      case 66: // local_variable_declaration
        yylhs.value.emplace< Statement* > ();
        break;

      case 56: // statements
        yylhs.value.emplace< StatementList* > ();
        break;

      case 61: // variable_declaration
      case 63: // type_and_identifiere
        yylhs.value.emplace< VariableDeclaration* > ();
        break;

      case 64: // types_and_identifieres
      case 65: // formals
        yylhs.value.emplace< VariableDeclarationList* > ();
        break;

      case 44: // "number"
      case 47: // signed_number
        yylhs.value.emplace< int > ();
        break;

      case 43: // "identifier"
      case 48: // logic
      case 49: // type
      case 50: // simple_type
      case 51: // array_type
      case 52: // type_identifier
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 267 "parser.y"
              {yylhs.value.as < Program* > () = yystack_[0].value.as < Program* > (); driver.program = yystack_[0].value.as < Program* > ();}
#line 1023 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 3:
#line 270 "parser.y"
                                 {yylhs.value.as < Program* > () = new Program(yystack_[1].value.as < MainClass* > (), yystack_[0].value.as < ClassDeclarationList* > ());}
#line 1029 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 4:
#line 273 "parser.y"
            {yylhs.value.as < ClassDeclarationList* > () = new ClassDeclarationList(); }
#line 1035 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 5:
#line 275 "parser.y"
     { yystack_[1].value.as < ClassDeclarationList* > ()->AddDeclaration(yystack_[0].value.as < ClassDeclaration* > ()); yylhs.value.as < ClassDeclarationList* > () = yystack_[1].value.as < ClassDeclarationList* > (); }
#line 1041 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 6:
#line 281 "parser.y"
         {yylhs.value.as < MainClass* > () = new MainClass(yystack_[11].value.as < std::string > (), yystack_[2].value.as < StatementList* > ());}
#line 1047 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 7:
#line 284 "parser.y"
           {yylhs.value.as < StatementList* > () = new StatementList();}
#line 1053 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 8:
#line 285 "parser.y"
                           {  yystack_[1].value.as < StatementList* > ()->AddStatement(yystack_[0].value.as < Statement* > ()); yylhs.value.as < StatementList* > () = yystack_[1].value.as < StatementList* > ();}
#line 1059 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 9:
#line 289 "parser.y"
    { yylhs.value.as < ClassDeclaration* > () = new ClassDeclaration(yystack_[3].value.as < std::string > (), "", yystack_[1].value.as < DeclarationList* > ()); }
#line 1065 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 10:
#line 292 "parser.y"
    { yylhs.value.as < ClassDeclaration* > () = new ClassDeclaration(yystack_[5].value.as < std::string > (), yystack_[3].value.as < std::string > (), yystack_[1].value.as < DeclarationList* > ()); }
#line 1071 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 11:
#line 295 "parser.y"
           {yylhs.value.as < DeclarationList* > () = new DeclarationList(); }
#line 1077 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 12:
#line 296 "parser.y"
                               { yystack_[1].value.as < DeclarationList* > ()->AddDeclaration(yystack_[0].value.as < Declaration* > ()); yylhs.value.as < DeclarationList* > () = yystack_[1].value.as < DeclarationList* > (); }
#line 1083 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 13:
#line 299 "parser.y"
                         {yylhs.value.as < Declaration* > () = yystack_[0].value.as < VariableDeclaration* > ();}
#line 1089 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 14:
#line 300 "parser.y"
                         {yylhs.value.as < Declaration* > () = yystack_[0].value.as < MethodDeclaration* > ();}
#line 1095 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 15:
#line 303 "parser.y"
                          {yylhs.value.as < VariableDeclaration* > () = new VariableDeclaration(yystack_[2].value.as < std::string > (), yystack_[1].value.as < std::string > ());}
#line 1101 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 16:
#line 307 "parser.y"
    { yylhs.value.as < MethodDeclaration* > () = new MethodDeclaration(yystack_[6].value.as < std::string > (), yystack_[5].value.as < std::string > (), new VariableDeclarationList(), yystack_[1].value.as < StatementList* > ()); }
#line 1107 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 17:
#line 310 "parser.y"
    { yylhs.value.as < MethodDeclaration* > () = new MethodDeclaration(yystack_[7].value.as < std::string > (), yystack_[6].value.as < std::string > (), yystack_[4].value.as < VariableDeclarationList* > (), yystack_[1].value.as < StatementList* > ()); }
#line 1113 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 18:
#line 313 "parser.y"
                         {yylhs.value.as < VariableDeclarationList* > () = new VariableDeclarationList();
                          yylhs.value.as < VariableDeclarationList* > ()->AddDeclaration(yystack_[0].value.as < VariableDeclaration* > ());}
#line 1120 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 19:
#line 315 "parser.y"
                                                      {yystack_[2].value.as < VariableDeclarationList* > ()->AddDeclaration(yystack_[0].value.as < VariableDeclaration* > ());
     yylhs.value.as < VariableDeclarationList* > () = yystack_[2].value.as < VariableDeclarationList* > ();}
#line 1127 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 20:
#line 319 "parser.y"
                      {yylhs.value.as < VariableDeclaration* > () = new VariableDeclaration(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::string > ());}
#line 1133 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 21:
#line 323 "parser.y"
    {yystack_[0].value.as < VariableDeclarationList* > ()->AddDeclaration(new VariableDeclaration(yystack_[2].value.as < std::string > (), yystack_[1].value.as < std::string > ())); yylhs.value.as < VariableDeclarationList* > () = yystack_[0].value.as < VariableDeclarationList* > ();}
#line 1139 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 22:
#line 326 "parser.y"
                {yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 1145 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 23:
#line 327 "parser.y"
                 {yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 1151 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 24:
#line 330 "parser.y"
          {yylhs.value.as < std::string > () = "int";}
#line 1157 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 25:
#line 331 "parser.y"
                {yylhs.value.as < std::string > () = "boolean"; }
#line 1163 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 26:
#line 332 "parser.y"
             {yylhs.value.as < std::string > () = "void";}
#line 1169 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 27:
#line 333 "parser.y"
                      { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 1175 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 28:
#line 336 "parser.y"
                        {yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > ();}
#line 1181 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 29:
#line 339 "parser.y"
                 {yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 1187 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 30:
#line 342 "parser.y"
                              { yylhs.value.as < Statement* > () = new AssertStatement(yystack_[2].value.as < Expression* > ()); }
#line 1193 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 31:
#line 343 "parser.y"
                                 {yylhs.value.as < Statement* > () = yystack_[0].value.as < Statement* > ();}
#line 1199 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 32:
#line 344 "parser.y"
                         {yylhs.value.as < Statement* > () = new InCurBrStatement(yystack_[1].value.as < StatementList* > ());}
#line 1205 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 33:
#line 345 "parser.y"
                                   {yylhs.value.as < Statement* > () = new IfStatement(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Statement* > ());}
#line 1211 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 34:
#line 347 "parser.y"
    {yylhs.value.as < Statement* > () = new IfElseStatement(yystack_[4].value.as < Expression* > (), yystack_[2].value.as < Statement* > (), yystack_[0].value.as < Statement* > ());}
#line 1217 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 35:
#line 349 "parser.y"
    {yylhs.value.as < Statement* > () = new WhileStatement(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Statement* > ());}
#line 1223 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 36:
#line 350 "parser.y"
                                            { yylhs.value.as < Statement* > () = new PrintlnStatement(yystack_[2].value.as < Expression* > ());}
#line 1229 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 37:
#line 351 "parser.y"
                          { yylhs.value.as < Statement* > () = new LvalueAssignStatement(yystack_[3].value.as < Lvalue* > (), yystack_[1].value.as < Expression* > ());}
#line 1235 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 38:
#line 352 "parser.y"
                        {yylhs.value.as < Statement* > () = new ReturnStatement(yystack_[1].value.as < Expression* > ());}
#line 1241 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 39:
#line 357 "parser.y"
    {VariableDeclaration* vd = yystack_[0].value.as < VariableDeclaration* > ();
     yylhs.value.as < Statement* > () = new LvalueStatement(vd->type_, vd->identifier_); }
#line 1248 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 40:
#line 362 "parser.y"
    {yylhs.value.as < MInvExpression* > () = new MInvExpression(yystack_[4].value.as < Expression* > (), yystack_[2].value.as < std::string > (), new ExpressionList()); }
#line 1254 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 41:
#line 364 "parser.y"
    {yylhs.value.as < MInvExpression* > () = new MInvExpression(yystack_[5].value.as < Expression* > (), yystack_[3].value.as < std::string > (), yystack_[1].value.as < ExpressionList* > ());}
#line 1260 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 42:
#line 367 "parser.y"
         {yylhs.value.as < ExpressionList* > () = new ExpressionList(); yylhs.value.as < ExpressionList* > ()->AddExpression(yystack_[0].value.as < Expression* > ());}
#line 1266 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 43:
#line 368 "parser.y"
                         {yystack_[2].value.as < ExpressionList* > ()->AddExpression(yystack_[0].value.as < Expression* > ()); yylhs.value.as < ExpressionList* > () = yystack_[2].value.as < ExpressionList* > (); }
#line 1272 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 44:
#line 371 "parser.y"
                 {yylhs.value.as < Lvalue* > () = new IdentifierLvalue(yystack_[0].value.as < std::string > ());}
#line 1278 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 45:
#line 372 "parser.y"
                                {yylhs.value.as < Lvalue* > () = new IdentifierListLvalue(yystack_[3].value.as < std::string > (), yystack_[1].value.as < Expression* > ());}
#line 1284 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 46:
#line 375 "parser.y"
                 {yylhs.value.as < int > () = -yystack_[0].value.as < int > ();}
#line 1290 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 47:
#line 376 "parser.y"
               {yylhs.value.as < int > () = yystack_[0].value.as < int > ();}
#line 1296 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 48:
#line 379 "parser.y"
            {yylhs.value.as < std::string > () = "false";}
#line 1302 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 49:
#line 380 "parser.y"
             {yylhs.value.as < std::string > () = "true";}
#line 1308 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 50:
#line 383 "parser.y"
              {yylhs.value.as < Expression* > () = new AddExpression(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 1314 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 51:
#line 384 "parser.y"
                  {yylhs.value.as < Expression* > () = new SubstractExpression(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 1320 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 52:
#line 385 "parser.y"
                  {yylhs.value.as < Expression* > () = new MultExpression(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 1326 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 53:
#line 386 "parser.y"
                  {yylhs.value.as < Expression* > () = new DivExpression(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 1332 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 54:
#line 387 "parser.y"
                  {yylhs.value.as < Expression* > () = new ModuleExpression(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 1338 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 55:
#line 388 "parser.y"
                   {yylhs.value.as < Expression* > () = new LogAndExpression(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 1344 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 56:
#line 389 "parser.y"
                   {yylhs.value.as < Expression* > () = new LogOrExpression(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 1350 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 57:
#line 390 "parser.y"
                  {yylhs.value.as < Expression* > () = new LessExpression(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 1356 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 58:
#line 391 "parser.y"
                  {yylhs.value.as < Expression* > () = new LargerExpression(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 1362 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 59:
#line 392 "parser.y"
                   {yylhs.value.as < Expression* > () = new IsEqualExpression(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 1368 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 60:
#line 393 "parser.y"
                   {yylhs.value.as < Expression* > () = new IsNotEqualExpression(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 1374 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 61:
#line 394 "parser.y"
                      {yylhs.value.as < Expression* > () = new InQBrExpression(yystack_[3].value.as < Expression* > (), yystack_[1].value.as < Expression* > ()); }
#line 1380 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 62:
#line 395 "parser.y"
                      {yylhs.value.as < Expression* > () = yystack_[0].value.as < MInvExpression* > ();}
#line 1386 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 63:
#line 396 "parser.y"
                                   {yylhs.value.as < Expression* > () = new NewArrayExpression(yystack_[3].value.as < std::string > (), yystack_[1].value.as < Expression* > ());}
#line 1392 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 64:
#line 397 "parser.y"
                 {yylhs.value.as < Expression* > () = new InRoundBrExpression(yystack_[1].value.as < Expression* > ()); }
#line 1398 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 65:
#line 398 "parser.y"
             {yylhs.value.as < Expression* > () = new NegExpression(yystack_[0].value.as < Expression* > ()); }
#line 1404 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 66:
#line 400 "parser.y"
                      {yylhs.value.as < Expression* > () = new LengthExpression(yystack_[2].value.as < Expression* > ());}
#line 1410 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 67:
#line 401 "parser.y"
                                  {yylhs.value.as < Expression* > () = new NewExpression(yystack_[2].value.as < std::string > ());}
#line 1416 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 68:
#line 402 "parser.y"
                 {yylhs.value.as < Expression* > () = new IdentExpression(yystack_[0].value.as < std::string > ());}
#line 1422 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 69:
#line 403 "parser.y"
                  {yylhs.value.as < Expression* > () = new NumberExpression(yystack_[0].value.as < int > ());}
#line 1428 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 70:
#line 404 "parser.y"
           {yylhs.value.as < Expression* > () = new ThisExpression();}
#line 1434 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;

  case 71:
#line 405 "parser.y"
          {yylhs.value.as < Expression* > () = new BoolExpression(yystack_[0].value.as < std::string > ());}
#line 1440 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"
    break;


#line 1444 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    std::ptrdiff_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */
    if (!yyla.empty ())
      {
        symbol_number_type yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];

        int yyn = yypact_[+yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -123;

  const signed char parser::yytable_ninf_ = -45;

  const short
  parser::yypact_[] =
  {
      -9,   -21,    26,  -123,  -123,     9,  -123,     1,    27,    12,
    -123,    34,    -8,    33,  -123,    31,    51,   464,    65,    66,
    -123,  -123,  -123,  -123,    -7,  -123,    37,    67,  -123,  -123,
    -123,  -123,  -123,  -123,    68,    46,    56,    70,   472,    78,
      81,  -123,  -123,  -123,  -123,    11,   382,    80,    58,    82,
    -123,    88,    92,    99,   100,   112,    77,    64,  -123,  -123,
    -123,   127,  -123,    -7,   118,   404,  -123,    77,    77,    77,
      77,    93,    77,    77,    -7,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,   119,  -123,    77,    77,   414,    95,  -123,   106,
    -123,  -123,   169,   193,   217,   241,  -123,   361,   265,   122,
     128,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,   -13,  -123,   289,   144,  -123,  -123,    -7,
     436,   109,   111,   446,   446,  -123,    77,   129,    -2,    -2,
      43,    43,    43,    55,   383,   107,   107,   107,   107,   313,
    -123,   145,  -123,  -123,  -123,  -123,  -123,  -123,   123,  -123,
     337,  -123,  -123,    62,   446,  -123,  -123,   361,     3,  -123,
    -123,    77,   361
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     2,     4,     0,     1,     3,     0,     0,
       5,     0,     0,     0,    11,     0,     0,     0,     0,     0,
       9,    24,    25,    26,     0,    29,     0,    22,    23,    27,
      12,    13,    14,    11,     0,     0,     0,     0,     0,     0,
       0,    15,    28,    10,     7,     0,     0,     0,     0,     0,
       7,     0,     0,     0,     0,     0,     0,    29,     8,    39,
      31,     0,     7,     0,     0,     0,     6,     0,     0,     0,
       0,     0,     0,     0,     0,    70,    49,    48,    68,    47,
      69,    71,     0,    62,     0,     0,     0,     0,    18,    21,
       7,    32,     0,     0,     0,     0,    46,    65,     0,     0,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,     0,     0,    16,    20,     0,
       0,     0,     0,     0,     0,    64,     0,     0,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,     0,
      66,     0,    45,    37,    19,    17,    36,    30,    33,    35,
       0,    67,    61,     0,     0,    63,    40,    42,     0,    34,
      41,     0,    43
  };

  const short
  parser::yypgoto_[] =
  {
    -123,  -123,  -123,   -24,    89,  -123,    91,   -61,  -123,  -122,
     -37,  -123,   133,  -123,  -123,    35,  -123,    48,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,  -123
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,    80,    81,    26,    27,    28,    29,    82,   158,    58,
      46,    30,    17,    10,     7,    59,    32,    88,    89,    49,
      60,    61,    83,     2,     3,     4
  };

  const short
  parser::yytable_[] =
  {
      35,   148,   149,   103,   104,   105,    92,    93,    94,    95,
      14,    97,    98,    65,   140,    21,    22,    23,   112,     1,
     160,    48,     5,   115,   116,    86,     6,     8,    47,     9,
     141,   113,   159,    21,    22,    23,    25,    15,   161,    87,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,    31,   120,    25,    12,    11,    16,   101,   102,
     103,   104,   105,   112,    13,   150,    71,   108,   109,   110,
     111,    72,   -44,    31,    18,   112,   113,    19,    73,   156,
      36,    71,    34,    33,    84,    39,    72,    37,   113,    40,
      41,    42,   157,    73,    74,    87,    44,    45,    62,    64,
     162,    63,    75,    76,    77,    78,    79,    66,    67,    74,
     101,   102,   103,   104,   105,    68,    69,    75,    76,    77,
      78,    79,   101,   102,   103,   104,   105,   112,    70,   106,
     107,   108,   109,   110,   111,    85,    90,    96,   118,   112,
     113,   119,   126,   146,   127,   147,   151,   101,   102,   103,
     104,   105,   113,   114,   106,   107,   108,   109,   110,   111,
     154,   153,     0,    99,   112,   100,    38,   144,     0,     0,
       0,     0,   101,   102,   103,   104,   105,   113,   143,   106,
     107,   108,   109,   110,   111,     0,   121,     0,     0,   112,
       0,     0,     0,     0,     0,     0,   101,   102,   103,   104,
     105,     0,   113,   106,   107,   108,   109,   110,   111,     0,
     122,     0,     0,   112,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,     0,   113,   106,   107,   108,
     109,   110,   111,     0,   123,     0,     0,   112,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,     0,
     113,   106,   107,   108,   109,   110,   111,     0,   124,     0,
       0,   112,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,     0,   113,   106,   107,   108,   109,   110,
     111,     0,   125,     0,     0,   112,     0,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,     0,   113,   106,
     107,   108,   109,   110,   111,     0,     0,     0,     0,   112,
     142,     0,     0,     0,     0,     0,   101,   102,   103,   104,
     105,     0,   113,   106,   107,   108,   109,   110,   111,     0,
       0,     0,     0,   112,   152,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,     0,   113,   106,   107,   108,
     109,   110,   111,     0,     0,     0,     0,   112,   155,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,     0,
     113,   106,   107,   108,   109,   110,   111,     0,     0,     0,
       0,   112,     0,     0,     0,     0,   101,   102,   103,   104,
     105,     0,     0,   106,   113,   108,   109,   110,   111,     0,
      50,    51,     0,   112,    21,    22,    23,    52,     0,     0,
       0,     0,     0,    53,     0,     0,   113,     0,    54,     0,
      55,    56,    50,    91,     0,    57,    21,    22,    23,    52,
       0,     0,    50,   117,     0,    53,    21,    22,    23,    52,
      54,     0,    55,    56,     0,    53,     0,    57,     0,     0,
      54,     0,    55,    56,    50,   145,     0,    57,    21,    22,
      23,    52,     0,     0,    50,     0,     0,    53,    21,    22,
      23,    52,    54,     0,    55,    56,     0,    53,     0,    57,
       0,     0,    54,    20,    55,    56,    21,    22,    23,    57,
       0,    43,     0,    24,    21,    22,    23,     0,     0,     0,
       0,    24,     0,     0,     0,     0,     0,    25,     0,     0,
       0,     0,     0,     0,     0,    25
  };

  const short
  parser::yycheck_[] =
  {
      24,   123,   124,     5,     6,     7,    67,    68,    69,    70,
      18,    72,    73,    50,    27,    22,    23,    24,    20,    28,
      17,    45,    43,    84,    85,    62,     0,    18,    17,    28,
      43,    33,   154,    22,    23,    24,    43,    45,    35,    63,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,    17,    90,    43,    43,    29,    24,     3,     4,
       5,     6,     7,    20,    30,   126,     4,    12,    13,    14,
      15,     9,     8,    38,    43,    20,    33,    26,    16,    17,
      43,     4,    16,    18,    20,    17,     9,    20,    33,    43,
      34,    21,   153,    16,    32,   119,    18,    16,    18,    17,
     161,    43,    40,    41,    42,    43,    44,    19,    16,    32,
       3,     4,     5,     6,     7,    16,    16,    40,    41,    42,
      43,    44,     3,     4,     5,     6,     7,    20,    16,    10,
      11,    12,    13,    14,    15,     8,    18,    44,    43,    20,
      33,    35,    20,    34,    16,    34,    17,     3,     4,     5,
       6,     7,    33,    34,    10,    11,    12,    13,    14,    15,
      37,    16,    -1,    74,    20,    74,    33,   119,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,    33,    34,    10,
      11,    12,    13,    14,    15,    -1,    17,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,    -1,    33,    10,    11,    12,    13,    14,    15,    -1,
      17,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,    -1,    33,    10,    11,    12,
      13,    14,    15,    -1,    17,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,
      33,    10,    11,    12,    13,    14,    15,    -1,    17,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,    -1,    33,    10,    11,    12,    13,    14,
      15,    -1,    17,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,    -1,    33,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    20,
      21,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,    -1,    33,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    20,    21,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,    -1,    33,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    20,    21,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,
      33,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    10,    33,    12,    13,    14,    15,    -1,
      18,    19,    -1,    20,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    33,    -1,    36,    -1,
      38,    39,    18,    19,    -1,    43,    22,    23,    24,    25,
      -1,    -1,    18,    19,    -1,    31,    22,    23,    24,    25,
      36,    -1,    38,    39,    -1,    31,    -1,    43,    -1,    -1,
      36,    -1,    38,    39,    18,    19,    -1,    43,    22,    23,
      24,    25,    -1,    -1,    18,    -1,    -1,    31,    22,    23,
      24,    25,    36,    -1,    38,    39,    -1,    31,    -1,    43,
      -1,    -1,    36,    19,    38,    39,    22,    23,    24,    43,
      -1,    19,    -1,    29,    22,    23,    24,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43
  };

  const signed char
  parser::yystos_[] =
  {
       0,    28,    69,    70,    71,    43,     0,    60,    18,    28,
      59,    29,    43,    30,    18,    45,    24,    58,    43,    26,
      19,    22,    23,    24,    29,    43,    49,    50,    51,    52,
      57,    61,    62,    18,    16,    49,    43,    20,    58,    17,
      43,    34,    21,    19,    18,    16,    56,    17,    49,    65,
      18,    19,    25,    31,    36,    38,    39,    43,    55,    61,
      66,    67,    18,    43,    17,    56,    19,    16,    16,    16,
      16,     4,     9,    16,    32,    40,    41,    42,    43,    44,
      47,    48,    53,    68,    20,     8,    56,    49,    63,    64,
      18,    19,    53,    53,    53,    53,    44,    53,    53,    50,
      52,     3,     4,     5,     6,     7,    10,    11,    12,    13,
      14,    15,    20,    33,    34,    53,    53,    19,    43,    35,
      56,    17,    17,    17,    17,    17,    20,    16,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      27,    43,    21,    34,    63,    19,    34,    34,    55,    55,
      53,    17,    21,    16,    37,    21,    17,    53,    54,    55,
      17,    35,    53
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    46,    69,    70,    60,    60,    71,    56,    56,    59,
      59,    58,    58,    57,    57,    61,    62,    62,    64,    64,
      63,    65,    49,    49,    50,    50,    50,    50,    51,    52,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    66,
      68,    68,    54,    54,    67,    67,    47,    47,    48,    48,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     0,     2,    13,     0,     2,     5,
       7,     0,     2,     1,     1,     3,     8,     9,     1,     3,
       2,     3,     1,     1,     1,     1,     1,     1,     3,     1,
       5,     1,     3,     5,     7,     5,     5,     4,     3,     1,
       5,     6,     1,     3,     1,     4,     2,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     4,     1,     5,     3,     2,     3,     4,     1,     1,
       1,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"+\"", "\"-\"", "\"*\"",
  "\"/\"", "\"%\"", "\"=\"", "\"!\"", "\"&&\"", "\"||\"", "\"<\"", "\">\"",
  "\"==\"", "\"!=\"", "\"(\"", "\")\"", "\"{\"", "\"}\"", "\"[\"", "\"]\"",
  "\"int\"", "\"boolean\"", "\"void\"", "\"System.out.println\"",
  "\"main\"", "\"length\"", "\"class\"", "\"public\"", "\"static\"",
  "\"assert\"", "\"new\"", "\".\"", "\";\"", "\",\"", "\"if\"", "\"else\"",
  "\"while\"", "\"return\"", "\"this\"", "\"true\"", "\"false\"",
  "\"identifier\"", "\"number\"", "\"extends\"", "$accept",
  "signed_number", "logic", "type", "simple_type", "array_type",
  "type_identifier", "expr", "expr_list", "statement", "statements",
  "declaration", "declarations", "class_declaration",
  "classes_declaration", "variable_declaration", "method_declaration",
  "type_and_identifiere", "types_and_identifieres", "formals",
  "local_variable_declaration", "lvalue", "method_invocation", "unit",
  "program", "main_class", YY_NULLPTR
  };

#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   267,   267,   270,   273,   274,   278,   284,   285,   288,
     291,   295,   296,   299,   300,   303,   306,   309,   313,   315,
     319,   322,   326,   327,   330,   331,   332,   333,   336,   339,
     342,   343,   344,   345,   346,   348,   350,   351,   352,   356,
     361,   363,   367,   368,   371,   372,   375,   376,   379,   380,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   400,   401,   402,   403,
     404,   405
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 2010 "/home/anna/comp/CompilersCourse-master/build/04-visitors/parser.cpp"

#line 408 "parser.y"


void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
