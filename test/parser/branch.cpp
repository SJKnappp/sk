//
// Created by knapp on 09/08/2020.
//

#include "parser.h"

TEST_CASE("branch: pass nullptr to generate an empty branch", "[branch]") {
  std::vector<std::vector<symbolTable>> a;
  branch test(nullptr, a, 0);
  REQUIRE(test.state == 0);
}

TEST_CASE("branch: pass an empty array into constructor", "[branch]") {
  std::vector<std::vector<symbolTable>> a;

  std::vector<symbolTable> symbol;
  std::vector<std::string> lexed;
  branch test(&lexed, a, 0);
  REQUIRE(test.state == 0);
}

TEST_CASE("branch: illegal token passed into function", "[branch]") {
  std::vector<std::vector<symbolTable>> a;

  std::vector<symbolTable> symbol;
  std::vector<std::string> lexed;
  lexed.push_back("");
  lexed.push_back("PLUS");
  branch test(&lexed, a, 0);
  REQUIRE(test.state == 21);
}

TEST_CASE("branch: legal token LCURLY", "[branch]") {
  std::vector<std::vector<symbolTable>> a;

  std::vector<symbolTable> symbol;
  std::vector<std::string> lexed;
  lexed.push_back("");
  lexed.push_back("LCURLY");
  branch test(&lexed, a, 0);
  REQUIRE(test.state == 0);
}
TEST_CASE("branch: legal token RCURLY", "[branch]") {
  std::vector<std::vector<symbolTable>> a;

  std::vector<symbolTable> symbol;
  std::vector<std::string> lexed;
  lexed.push_back("");
  lexed.push_back("RCURLY");
  branch test(&lexed, a, 0);
  REQUIRE(test.state == 0);
}
TEST_CASE("branch: legal token SEMICOLON", "[branch]") {
  std::vector<std::vector<symbolTable>> a;

  std::vector<symbolTable> symbol;
  std::vector<std::string> lexed;
  lexed.push_back("");
  lexed.push_back("SEMICOLON");
  branch test(&lexed, a, 0);
  REQUIRE(test.state == 0);
}
TEST_CASE("branch: legal token IFSYM", "[branch]") {
  std::vector<std::vector<symbolTable>> a;

  std::vector<symbolTable> symbol;
  std::vector<std::string> lexed;
  lexed.push_back("");
  lexed.push_back("IFSYM");
  branch test(&lexed, a, 0);
  REQUIRE(test.state == 0);
}
TEST_CASE("branch: llegal token WHILESYM", "[branch]") {
  std::vector<std::vector<symbolTable>> a;

  std::vector<symbolTable> symbol;
  std::vector<std::string> lexed;
  lexed.push_back("");
  lexed.push_back("WHILESYM");
  branch test(&lexed, a, 0);
  REQUIRE(test.state == 0);
}
TEST_CASE("branch: legal token INTSYM", "[branch]") {
  std::vector<std::vector<symbolTable>> a;

  std::vector<symbolTable> symbol;
  std::vector<std::string> lexed;
  lexed.push_back("");
  lexed.push_back("INTSYM");
  branch test(&lexed, a, 0);
  REQUIRE(test.state == 0);
}
TEST_CASE("branch: legal token VOIDSYM", "[branch]") {
  std::vector<std::vector<symbolTable>> a;
  std::vector<symbolTable> symbol;
  std::vector<std::string> lexed;
  lexed.push_back("");
  lexed.push_back("VOIDSYM");
  branch test(&lexed, a, 0);
  REQUIRE(test.state == 0);
}
TEST_CASE("branch: legal token RETURNSYM", "[branch]") {
  std::vector<std::vector<symbolTable>> a;
  std::vector<symbolTable> symbol;
  std::vector<std::string> lexed;
  lexed.push_back("");
  lexed.push_back("RETURNSYM");
  branch test(&lexed, a, 0);
  REQUIRE(test.state == 0);
}
TEST_CASE("branch: legal token identifier", "[branch]") {
  std::vector<std::vector<symbolTable>> a;
  std::vector<symbolTable> symbol;
  std::vector<std::string> lexed;
  lexed.push_back("");
  lexed.push_back("identifier");
  branch test(&lexed, a, 0);
  REQUIRE(test.state == 0);
}
TEST_CASE("branch: legal token number", "[branch]") {
  std::vector<std::vector<symbolTable>> a;
  std::vector<symbolTable> symbol;
  std::vector<std::string> lexed;
  lexed.push_back("");
  lexed.push_back("number");
  branch test(&lexed, a, 0);
  REQUIRE(test.state == 0);
}