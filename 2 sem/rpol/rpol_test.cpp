#include "rpol.h"
#include "catch.hpp"
#include <string>


Int EvalString(const std::string& s) {
  std::istringstream iss(s);
  return EvalRevPolishExpr(iss);
}

TEST_CASE ("RPol 2+2") {
  REQUIRE(EvalString("+ 2 2") == 4);
}

TEST_CASE ("Rpol subtraction operand order") {
  REQUIRE(EvalString("- 4 2") == 2);
  REQUIRE(EvalString("- 2 4") == -2);
}
