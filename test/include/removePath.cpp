//
// Created by knapp on 07/08/2020.
//

#include "fileInput.h"

TEST_CASE(
    "include: test the removePath function correctly removes the end of path") {
  std::string a = "test/best/rest/";
  Result test = removePath(a);
  REQUIRE(test.text == "test/best/");
  REQUIRE(test.state == 0);
}

TEST_CASE(
    "include: test the removePath function when empty string passed adds ../") {
  std::string a = "";
  Result test = removePath(a);
  REQUIRE(test.text == "../");
  REQUIRE(test.state == 0);
}

TEST_CASE("include: no termating path with a /") {
  std::string a = "test/best";
  Result test = removePath(a);
  REQUIRE(test.text == "1 FAILED");
  REQUIRE(test.state == 0);
}