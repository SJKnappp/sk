add_subdirectory(assembly)
add_subdirectory(parser)

add_executable(main
        main.cpp include.cpp lexer.cpp)

target_link_libraries(main assembly)
target_link_libraries(main parser)