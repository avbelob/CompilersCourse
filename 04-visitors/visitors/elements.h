#pragma once

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