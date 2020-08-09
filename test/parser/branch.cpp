//
// Created by knapp on 09/08/2020.
//

#include "parser.h"

TEST_CASE("branch: pass nullptr to generate an empty branch", "[branch]") {
  branch test(nullptr, <#initializer #>, 0);
  REQUIRE(test.state == 0);
}

TEST_CASE("branch: pass an empty array into constructor", "[branch]") {
  std::vector<symbolTable> symbol;
  std::vector<std::string> lexed;
  branch test(&lexed, <#initializer #>, 0);
  REQUIRE(test.state == 0);
}

TEST_CASE("branch: illegal token passed into function", "[branch]") {
  std::vector<symbolTable> symbol;
  std::vector<std::string> lexed;
  lexed.push_back("");
  lexed.push_back("PLUS");
  branch test(&lexed, <#initializer #>, 0);
  REQUIRE(test.state == 21);
}

TEST_CASE("branch: legal token LCURLY", "[branch]") {
  std::vector<symbolTable> symbol;
  std::vector<std::string> lexed;
  lexed.push_back("");
  lexed.push_back("LCURLY");
  branch test(&lexed, <#initializer #>, 0);
  REQUIRE(test.state == 0);
}
TEST_CASE("branch: legal token RCURLY", "[branch]") {
  std::vector<symbolTable> symbol;
  std::vector<std::string> lexed;
  lexed.push_back("");
  lexed.push_back("RCURLY");
  branch test(&lexed, <#initializer #>, 0);
  REQUIRE(test.state == 0);
}
TEST_CASE("branch: legal token SEMICOLON", "[branch]") {
  std::vector<symbolTable> symbol;
  std::vector<std::string> lexed;
  lexed.push_back("");
  lexed.push_back("SEMICOLON");
  branch test(&lexed, <#initializer #>, 0);
  REQUIRE(test.state == 0);
}
TEST_CASE("branch: legal token IFSYM", "[branch]") {
  std::vector<symbolTable> symbol;
  std::vector<std::string> lexed;
  lexed.push_back("");
  lexed.push_back("IFSYM");
  branch test(&lexed, <#initializer #>, 0);
  REQUIRE(test.state == 0);
}
TEST_CASE("branch: llegal token WHILESYM", "[branch]") {
  std::vector<symbolTable> symbol;
  std::vector<std::string> lexed;
  lexed.push_back("");
  lexed.push_back("WHILESYM");
  branch test(&lexed, <#initializer #>, 0);
  REQUIRE(test.state == 0);
}
TEST_CASE("branch: legal token INTSYM", "[branch]") {
  std::vector<symbolTable> symbol;
  std::vector<std::string> lexed;
  lexed.push_back("");
  lexed.push_back("INTSYM");
  branch test(&lexed, <#initializer #>, 0);
  REQUIRE(test.state == 0);
}
TEST_CASE("branch: legal token VOIDSYM", "[branch]") {
  std::vector<symbolTable> symbol;
  std::vector<std::string> lexed;
  lexed.push_back("");
  lexed.push_back("VOIDSYM");
  branch test(&lexed, <#initializer #>, 0);
  REQUIRE(test.state == 0);
}
TEST_CASE("branch: legal token RETURNSYM", "[branch]") {
  std::vector<symbolTable> symbol;
  std::vector<std::string> lexed;
  lexed.push_back("");
  lexed.push_back("RETURNSYM");
  branch test(&lexed, <#initializer #>, 0);
  REQUIRE(test.state == 0);
}
TEST_CASE("branch: legal token identifier", "[branch]") {
  std::vector<symbolTable> symbol;
  std::vector<std::string> lexed;
  lexed.push_back("");
  lexed.push_back("identifier");
  branch test(&lexed, <#initializer #>, 0);
  REQUIRE(test.state == 0);
}
TEST_CASE("branch: legal token number", "[branch]") {
  std::vector<symbolTable> symbol;
  std::vector<std::string> lexed;
  lexed.push_back("");
  lexed.push_back("number");
  branch test(&lexed, <#initializer #>, 0);
  REQUIRE(test.state == 0);
}