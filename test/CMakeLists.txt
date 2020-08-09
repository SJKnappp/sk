add_executable(Test
        testMain.cpp test.cpp
        assembly/defintions.cpp
        parser/defintions.cpp parser/symbolTable.cpp
        lexer/tokensGen.cpp lexer/lex.cpp
        include/fileInput.cpp include/removePath.cpp include/path.cpp)

target_link_libraries(Test
        assembly parser lexer parser include)
