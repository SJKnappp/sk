//
// Created by knapp on 09/08/2020.
//

#include "parser.h"

TEST_CASE("branch: pass nullptr to generate an empty branch", "[branch]") {
  branch test(nullptr, nullptr);
  REQUIRE(test.state == 0);
}

TEST_CASE("branch: pass an empty array into constructor", "[branch]") {
  std::vector<symbolTable> symbol;
  std::vector<std::string> lexed;
  branch test(&symbol, &lexed);
  REQUIRE(test.state == 0);
}