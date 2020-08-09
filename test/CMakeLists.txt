add_executable(Test
        testMain.cpp test.cpp
        assembly/defintions.cpp
        parser/defintions.cpp parser/symbolTable.cpp
        lexer/tokensGen.cpp lexer/lex.cpp
        include/fileInput.cpp include/removePath.cpp include/path.cpp parser/node.cpp parser/branch.cpp parser/returnNode.cpp parser/binaryTree.cpp parser/assign.cpp parser/binop.cpp parser/compare.cpp parser/num.cpp parser/identifier.cpp parser/search.cpp)

target_link_libraries(Test
        assembly parser lexer parser include)
