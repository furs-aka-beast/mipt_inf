project(InfixNotation)

set(CMAKE_CXX_STANDARD 17)

add_library(rlib SHARED infix.cpp)

add_executable(test_infix
        infix_not_tests.cpp
        )

target_link_libraries(test_infix lib)
                                             
