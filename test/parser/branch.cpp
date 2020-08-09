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

TEST_CASE("branch: illegal token passed into function") {
  std::vector<symbolTable> symbol;
  std::vector<std::string> lexed;
  lexed.push_back("");
  lexed.push_back("PLUS");
  branch test(&symbol, &lexed);
  REQUIRE(test.state == 21);
}

TEST_CASE("branch: legal token LCURLY") {
  std::vector<symbolTable> symbol;
  std::vector<std::string> lexed;
  lexed.push_back("");
  lexed.push_back("LCURLY");
  branch test(&symbol, &lexed);
  REQUIRE(test.state == 0);
}
TEST_CASE("branch: legal token RCURLY") {
  std::vector<symbolTable> symbol;
  std::vector<std::string> lexed;
  lexed.push_back("");
  lexed.push_back("RCURLY");
  branch test(&symbol, &lexed);
  REQUIRE(test.state == 0);
}
TEST_CASE("branch: legal token SEMICOLON") {
  std::vector<symbolTable> symbol;
  std::vector<std::string> lexed;
  lexed.push_back("");
  lexed.push_back("SEMICOLON");
  branch test(&symbol, &lexed);
  REQUIRE(test.state == 0);
}
TEST_CASE("branch: llegal token IFSYM") {
  std::vector<symbolTable> symbol;
  std::vector<std::string> lexed;
  lexed.push_back("");
  lexed.push_back("IFSYM");
  branch test(&symbol, &lexed);
  REQUIRE(test.state == 0);
}
TEST_CASE("branch: llegal token WHILESYM") {
  std::vector<symbolTable> symbol;
  std::vector<std::string> lexed;
  lexed.push_back("");
  lexed.push_back("WHILESYM");
  branch test(&symbol, &lexed);
  REQUIRE(test.state == 0);
}
TEST_CASE("branch: legal token INTSYM") {
  std::vector<symbolTable> symbol;
  std::vector<std::string> lexed;
  lexed.push_back("");
  lexed.push_back("INTSYM");
  branch test(&symbol, &lexed);
  REQUIRE(test.state == 0);
}
TEST_CASE("branch: legal token VOIDSYM") {
  std::vector<symbolTable> symbol;
  std::vector<std::string> lexed;
  lexed.push_back("");
  lexed.push_back("VOIDSYM");
  branch test(&symbol, &lexed);
  REQUIRE(test.state == 0);
}
TEST_CASE("branch: legal token RETURNSYM") {
  std::vector<symbolTable> symbol;
  std::vector<std::string> lexed;
  lexed.push_back("");
  lexed.push_back("RETURNSYM");
  branch test(&symbol, &lexed);
  REQUIRE(test.state == 0);
}
TEST_CASE("branch: legal token identifier") {
  std::vector<symbolTable> symbol;
  std::vector<std::string> lexed;
  lexed.push_back("");
  lexed.push_back("identifier");
  branch test(&symbol, &lexed);
  REQUIRE(test.state == 0);
}
TEST_CASE("branch: legal token number") {
  std::vector<symbolTable> symbol;
  std::vector<std::string> lexed;
  lexed.push_back("");
  lexed.push_back("number");
  branch test(&symbol, &lexed);
  REQUIRE(test.state == 0);
}