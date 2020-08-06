add_executable(Test
        testMain.cpp test.cpp
        assembly/defintions.cpp
        parser/defintions.cpp
        lexer/tokensGen.cpp)

target_link_libraries(Test
        assembly parser lexer parser)
