//
// Created by knapp on 09/08/2020.
//

#include "parser.h"

TEST_CASE("binop: passes empty variables into the constructor", "[binop]") {
  std::vector<std::string> lexed;
  std::vector<std::vector<symbolTable>> symbol;
  int location = 0;
  binop test(&lexed, symbol, location);
  REQUIRE(test.state == 23);
}

TEST_CASE("binop: passes minimium requirment for constructor", "[binop]") {
  std::vector<std::string> lexed;
  std::vector<std::vector<symbolTable>> symbol;
  int location = 0;
  lexed.push_back("iTest");
  lexed.push_back("PLUS");
  lexed.push_back("iRest");
  binop test(&lexed, symbol, location);
  REQUIRE(test.state == 0);
}

TEST_CASE("binop: passes illegal symbol constructor", "[binop]") {
  std::vector<std::string> lexed;
  std::vector<std::vector<symbolTable>> symbol;
  int location = 0;
  lexed.push_back("MINUS");
  lexed.push_back("PLUS");
  lexed.push_back("iRest");
  binop test(&lexed, symbol, location);
  REQUIRE(test.state == 21);
}

TEST_CASE("binop: passes two plus for constructor", "[binop]") {
  std::vector<std::string> lexed;
  std::vector<std::vector<symbolTable>> symbol;
  int location = 0;
  lexed.push_back("iTest");
  lexed.push_back("PLUS");
  lexed.push_back("iRest");
  lexed.push_back("PLUS");
  lexed.push_back("iback");
  binop test(&lexed, symbol, location);
  REQUIRE(test.state == 0);
}
