project(InfixNotation)

set(CMAKE_CXX_STANDARD 17)

add_library(lib SHARED infix.cpp)

add_executable(test_infix
        infix_test.cpp
        infix_test_main.cpp
        )

target_link_libraries(test_infix lib)
                                             
