//
// Created by knapp on 09/08/2020.
//

#include "parser.h"

TEST_CASE("number: empty initialiser", "[number]") {
  std::vector<std::vector<symbolTable>> a;
  num test("", a, 0);
  REQUIRE(test.data == "");
  REQUIRE(test.state == 23);
}

TEST_CASE("number: valid identifier", "[number]") {
  std::vector<std::vector<symbolTable>> a;
  num test("iTEST", a, 0);
  REQUIRE(test.data == "");
  REQUIRE(test.state == 21);
}

TEST_CASE("number: pass number", "[number]") {
  std::vector<std::vector<symbolTable>> a;
  num test("n123", a, 0);
  REQUIRE(test.data == "123");
  REQUIRE(test.state == 0);
}

TEST_CASE("number: empty identifier", "[number]") {
  std::vector<std::vector<symbolTable>> a;
  num test("n", a, 0);
  REQUIRE(test.data == "");
  REQUIRE(test.state == 21);
}