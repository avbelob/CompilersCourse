project(Visitor)
set(
        HEADERS
        driver.hh
        parser.hh
)

BISON_TARGET(
        ParserVisitor
        parser.y
        ${Visitor_SOURCE_DIR}/parser.cpp
        COMPILE_FLAGS --graph
        DEFINES_FILE ${Visitor_SOURCE_DIR}/parser.hh
)

FLEX_TARGET(
        ScannerVisitor
        scanner.l
        ${Visitor_SOURCE_DIR}/scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(ScannerVisitor ParserVisitor)

add_executable(
        ScopesExecutable
        main.cpp
        driver.cpp
        ${BISON_ParserVisitor_OUTPUTS}
        ${FLEX_ScannerVisitor_OUTPUTS}
        expressions/ExpressionList.cpp
        expressions/NumberExpression.cpp
        expressions/BoolExpression.cpp
        expressions/IdentExpression.cpp

        expressions/AddExpression.cpp
        expressions/SubstractExpression.cpp
        expressions/MultExpression.cpp
        expressions/DivExpression.cpp
        expressions/ModuleExpression.cpp
        expressions/NegExpression.cpp

        expressions/LogAndExpression.cpp
        expressions/LogOrExpression.cpp
        expressions/LessExpression.cpp
        expressions/LargerExpression.cpp
        expressions/IsEqualExpression.cpp
        expressions/IsNotEqualExpression.cpp

        expressions/InRoundBrExpression.cpp
        expressions/InQBrExpression.cpp

        expressions/LengthExpression.cpp
        expressions/NewExpression.cpp
        expressions/NewArrayExpression.cpp

        expressions/MInvExpression.cpp
        expressions/ThisExpression.cpp

        statement/StatementList.cpp
        statement/PrintlnStatement.cpp
        statement/AssertStatement.cpp

        statement/IfStatement.cpp
        statement/IfElseStatement.cpp
        statement/WhileStatement.cpp
        statement/ReturnStatement.cpp

        statement/LvalueAssignStatement.cpp
        statement/LvalueStatement.cpp

        statement/InCurBrStatement.cpp

        declaration/DeclarationList.cpp
        declaration/ClassDeclaration.cpp
        declaration/ClassDeclarationList.cpp
        declaration/MethodDeclaration.cpp
        declaration/VariableDeclaration.cpp
        declaration/VariableDeclarationList.cpp

        lvalue/IdentifierLvalue.cpp
        lvalue/IdentifierListLvalue.cpp

        visitors/Interpreter.cpp
        visitors/PrintVisitor.cpp
        visitors/Types.cpp
        visitors/InterpreterTypes.cpp
        visitors/SymbolTreeVisitor.cpp
        visitors/TemplateVisitor.cpp

        symbol_table/ScopeLayer.cpp
        symbol_table/ScopeLayerTree.cpp
        symbol_table/Symbol.cpp
        symbol_table/Table.cpp

        objects/Object.cpp
        objects/Integer.cpp
        objects/Class.cpp
        objects/Method.cpp
        objects/Boolean.cpp
        objects/UninitObject.cpp

        Program.cpp
        MainClass.cpp
)

target_include_directories(
        ScopesExecutable PRIVATE ${Visitor_SOURCE_DIR}
)

add_custom_target(
        VisitorTree
        COMMAND dot -Tpng ${Visitor_SOURCE_DIR}/parser.gv -o ${Visitor_SOURCE_DIR}/parser.png

        DEPENDS ${Visitor_SOURCE_DIR}/parser.cpp
)

add_dependencies(ScopesExecutable VisitorTree)