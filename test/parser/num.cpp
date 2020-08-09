//
// Created by knapp on 09/08/2020.
//

#include "parser.h"

TEST_CASE("number: empty intialier", "[number]") {
  num test("");
  REQUIRE(test.data == "");
  REQUIRE(test.state == 23);
}

TEST_CASE("number: vailid idenfier", "[number]") {
  num test("iTEST");
  REQUIRE(test.data == "");
  REQUIRE(test.state == 21);
}

TEST_CASE("number: pass number", "[number]") {
  num test("n123");
  REQUIRE(test.data == "123");
  REQUIRE(test.state == 0);
}

TEST_CASE("number: empty idenfier", "[number]") {
  num test("n");
  REQUIRE(test.data == "");
  REQUIRE(test.state == 21);
}