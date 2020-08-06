add_executable(Test
        testMain.cpp test.cpp
        assembly/defintions.cpp
        parser/defintions.cpp)

target_link_libraries(Test
        assembly parser)
