//
// Created by knapp on 06/08/2020.
//

#include "tokensGen.h"
#include "../catch.hpp"

TEST_CASE("Token case +") {
  std::string t = tokens("+");
  REQUIRE(t == "PLUS");
}
TEST_CASE("Token case -") {
  std::string t = tokens("-");
  REQUIRE(t == "MINUS");
}
TEST_CASE("Token case *") {
  std::string t = tokens("*");
  REQUIRE(t == "TIMES");
}
TEST_CASE("Token case /") {
  std::string t = tokens("/");
  REQUIRE(t == "SLASH");
}
TEST_CASE("Token case (") {
  std::string t = tokens("(");
  REQUIRE(t == "LPAREN");
}
TEST_CASE("Token case )") {
  std::string t = tokens(")");
  REQUIRE(t == "RPAREN");
}
TEST_CASE("Token case {") {
  std::string t = tokens("{");
  REQUIRE(t == "LCURLY");
}
TEST_CASE("Token case }") {
  std::string t = tokens("}");
  REQUIRE(t == "RCURLY");
}
TEST_CASE("Token case ;") {
  std::string t = tokens(";");
  REQUIRE(t == "SEMICOLON");
}
TEST_CASE("Token case .") {
  std::string t = tokens(".");
  REQUIRE(t == "PERIOD");
}
TEST_CASE("Token case =") {
  std::string t = tokens("=");
  REQUIRE(t == "EQL");
}
TEST_CASE("Token case ==") {
  std::string t = tokens("==");
  REQUIRE(t == "COM");
}
TEST_CASE("Token case !=") {
  std::string t = tokens("!=");
  REQUIRE(t == "NQL");
}
TEST_CASE("Token case <") {
  std::string t = tokens("<");
  REQUIRE(t == "LSS");
}
TEST_CASE("Token case >") {
  std::string t = tokens(">");
  REQUIRE(t == "GTR");
}
TEST_CASE("Token case <=") {
  std::string t = tokens("<=");
  REQUIRE(t == "LEQ");
}
TEST_CASE("Token case >=") {
  std::string t = tokens(">=");
  REQUIRE(t == "GEQ");
}
TEST_CASE("Token case const") {
  std::string t = tokens("const");
  REQUIRE(t == "CONSTSYM");
}
TEST_CASE("Token case if") {
  std::string t = tokens("if");
  REQUIRE(t == "IFSYM");
}
TEST_CASE("Token case while") {
  std::string t = tokens("while");
  REQUIRE(t == "WHILESYM");
}
TEST_CASE("Token case int") {
  std::string t = tokens("int");
  REQUIRE(t == "INTSYM");
}
TEST_CASE("Token case void") {
  std::string t = tokens("void");
  REQUIRE(t == "VOIDSYM");
}
TEST_CASE("Token case return") {
  std::string t = tokens("return");
  REQUIRE(t == "RETURNSYM");
}
TEST_CASE("Token case identifier") {
  std::string a = tokens("test");
  std::string b = tokens("a1t");
  std::string c = tokens("z11");
  std::string d = tokens("d=_");
  REQUIRE(a == "itest");
  REQUIRE(b == "ia1t");
  REQUIRE(c == "iz11");
  REQUIRE(d == "UNKOWN");
}
TEST_CASE("Token case number") {
  std::string t = tokens("123");
  std::string a = tokens("1a");
  std::string b = tokens("1+");
  REQUIRE(t == "n123");
  REQUIRE(a == "FAILED");
  REQUIRE(b == "FAILED");
}
TEST_CASE("Token case empty") {
  std::string t = tokens("");
  REQUIRE(t == "EMPTYFLAG");
}