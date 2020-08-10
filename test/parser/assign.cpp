//
// Created by knapp on 09/08/2020.
//

#include "parser.h"

TEST_CASE("assign: pass empty variables into assign", "[assign]") {
  std::vector<std::vector<symbolTable>> a;
  std::vector<std::string> lexed;
  assign test(&lexed, a, 0);
  REQUIRE(test.state == 23);
}
TEST_CASE("assign: with non empty lexed", "[assign]") {
  std::vector<std::vector<symbolTable>> a;
  std::vector<std::string> lexed;
  lexed.push_back("");
  assign test(&lexed, a, 0);
  REQUIRE(test.state == 23);
}
// todo add better test to check result
TEST_CASE("assign: test function generation", "[assign]") {
  std::vector<std::vector<symbolTable>> a;
  std::vector<std::string> lexed;
  lexed.push_back("int");
  lexed.push_back("itest");
  lexed.push_back("LPAREN");
  lexed.push_back("RPAREN");
  lexed.push_back("LCURLY");
  assign test(&lexed, a, 0);
  REQUIRE(test.state == 0);
  REQUIRE(test.left->state == 0);
}
TEST_CASE("assign: pass a non allowed function generation", "[assign]") {
  std::vector<std::vector<symbolTable>> a;
  std::vector<std::string> lexed;
  lexed.push_back("int");
  lexed.push_back("test");
  lexed.push_back("LPAREN");
  lexed.push_back("LCURLY");
  assign test(&lexed, a, 0);
  REQUIRE(test.state == 23);
}
// todo
TEST_CASE("assign: pass varible without assignment", "[assign]") {
  std::vector<std::vector<symbolTable>> a;
  std::vector<std::string> lexed;
  lexed.push_back("int");
  lexed.push_back("test");
  lexed.push_back("SEMICOLON");
  assign test(&lexed, a, 0);
  REQUIRE(test.state == 23);
}
TEST_CASE("assign: test that a variable is generated correctly", "[assign]") {
  std::vector<std::vector<symbolTable>> a;
  std::vector<std::string> lexed;
  lexed.push_back("int");
  lexed.push_back("test");
  lexed.push_back("=");
  lexed.push_back("0");
  lexed.push_back("SEMICOLON");
  assign test(&lexed, a, 0);
  REQUIRE(test.state == 0);
}
// todo
TEST_CASE("assign: pass a bad variable definition", "[assign]") {
  std::vector<std::vector<symbolTable>> a;
  std::vector<std::string> lexed;
  lexed.push_back("int");
  lexed.push_back("test");
  lexed.push_back("=");
  lexed.push_back("SEMICOLON");
  assign test(&lexed, a, 0);
  REQUIRE(test.state == 23);
}
