project(RevPolNotation)

set(CMAKE_CXX_STANDARD 17)

add_library(rpoleval SHARED rpol.cpp)

add_executable(test_rev_pol
	rpol_test.cpp
	rpol_test_main.cpp
	)

target_link_libraries(test_rev_pol rpoleval)