//
// Created by knapp on 09/08/2020.
//

#include "parser.h"

TEST_CASE("Identifier: empty intialier") {
  std::vector<std::vector<symbolTable>> a;
  identifier test("", a, 0);
  REQUIRE(test.data == "");
  REQUIRE(test.state == 23);
}

TEST_CASE("Identifier: vailid idenfier") {
  std::vector<std::vector<symbolTable>> a;
    identifier test("iTEST", a, 0, true);
  REQUIRE(test.data == "TEST");
  REQUIRE(test.state == 0);
}

TEST_CASE("Identifier: pass number") {
  std::vector<std::vector<symbolTable>> a;
  identifier test("n123", a, 0);
  REQUIRE(test.data == "");
  REQUIRE(test.state == 21);
}

TEST_CASE("Identifier: empty idenfier") {
  std::vector<std::vector<symbolTable>> a;
  identifier test("i", a, 0);
  REQUIRE(test.data == "");
  REQUIRE(test.state == 21);
}

TEST_CASE("Identifier: test generates function correctly", "[include]") {
  std::vector<std::vector<symbolTable>> a;
  identifier test("iStart", a, 0, true, true);
  REQUIRE(test.state == 0);
}

TEST_CASE("Identifier: test repeated function not generated", "[include]") {
  std::vector<std::vector<symbolTable>> a;
  identifier test("iStart", a, 0, true, true);
  identifier test1("iStart", a, 0, true, true);
  REQUIRE(test.state == 0);
  REQUIRE(test1.state == 24);
}

TEST_CASE("Identifier: test varible generated", "[include]") {
  std::vector<std::vector<symbolTable>> a;
  std::vector<symbolTable> b;
  b.push_back(symbolTable("", "", ""));
  a.push_back(b);
  identifier test("iStart", a, 0, true, false);
  identifier test1("iStart", a, 0, true, false);
  REQUIRE(test.state == 0);
  REQUIRE(test1.state == 24);
}
TEST_CASE("Identifier: test repeated varible not generated", "[include]") {
  std::vector<std::vector<symbolTable>> a;
  std::vector<symbolTable> b;
  b.push_back(symbolTable("", "", ""));
  a.push_back(b);
  identifier test("iStart", a, 0, true, false);
  identifier test1("iStart", a, 0, true, false);
  REQUIRE(test.state == 0);
  REQUIRE(test1.state == 24);
}
