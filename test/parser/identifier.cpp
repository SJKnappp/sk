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
  identifier test("iTEST", a, 0);
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
