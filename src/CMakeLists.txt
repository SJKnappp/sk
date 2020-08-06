add_subdirectory(assembly)
add_subdirectory(parser)
add_subdirectory(include)
add_subdirectory(lexer)

add_executable(main
        main.cpp)

target_link_libraries(main
        assembly parser lexer include)