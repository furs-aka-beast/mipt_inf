#include"infix.h"
#include"infix.cpp"
#include"catch.hpp"
#include<string>

Int EvalString(const std::string& s) {
  std::istringstream iss(s);
  return InfixNotation(iss);
}

TEST_CASE ("1 + 1"){
    REQUIRE(EvalString("1 + 1") == 2);
}

TEST_CASE ("Substraction") {
    REQUIRE(EvalString("8 - 3 - 5") == 0);
    REQUIRE(EvalString("9 - 11 - 3") == -5);
}

TEST_CASE("Mixed operations") {
    REQUIRE(EvalString("8 * 2 - 6 * 1 + 10") == 20);
    REQUIRE(EvalString("    8/4 + 2 * 4") == 10);
}

TEST_CASE("Cases with paranthes") {
    REQUIRE(EvalString("(3 + (4 + 2)*2) / 3 ") == 5);
    REQUIRE(EvalString("(6 / (5 - 3) + 4) * (1 + 1)       ") == 14);
};

