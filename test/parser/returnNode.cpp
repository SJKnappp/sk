//
// Created by knapp on 09/08/2020.
//

#include "parser.h"

TEST_CASE("returnNode: test constructor with empty inputs", "[returnNode]") {
  std::vector<std::string> lexed;
  std::vector<std::vector<symbolTable>> symbol;
  int location = 0;
  returnNode test(&lexed, symbol, location);
  REQUIRE(test.state == 23);
}

TEST_CASE("returnNode: test a vailed lexed with minium requriments",
          "[returnNode]") {
  std::vector<std::string> lexed;
  lexed.push_back("SEMICOLON");
  std::vector<std::vector<symbolTable>> symbol;
  int location = 0;
  returnNode test(&lexed, symbol, location);
  REQUIRE(test.state == 0);
}