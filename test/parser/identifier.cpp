//
// Created by knapp on 09/08/2020.
//

#include "parser.h"

TEST_CASE("Identifier: empty intialier") {
  identifier test("");
  REQUIRE(test.data == "");
  REQUIRE(test.state == 21);
}

TEST_CASE("Identifier: vailid idenfier") {
  identifier test("iTEST");
  REQUIRE(test.data == "TEST");
  REQUIRE(test.state == 0);
}

TEST_CASE("Identifier: pass number") {
  identifier test("n123");
  REQUIRE(test.data == "");
  REQUIRE(test.state == 21);
}

TEST_CASE("Identifier: empty idenfier") {
  identifier test("i");
  REQUIRE(test.data == "");
  REQUIRE(test.state == 21);
}
