//
// Created by knapp on 07/08/2020.
//

#include "fileInput.h"

TEST_CASE(
    "include: test the removePath function correctly removes the end of path") {
  std::string a = "test/best/rest/";
  std::string test = removePath(a);
  REQUIRE(test == "test/best/");
}

TEST_CASE(
    "include: test the removePath function when empty string passed adds ../") {
  std::string a = "";
  std::string test = removePath(a);
  REQUIRE(test == "../");
}

TEST_CASE("include: no termating path with a /") {
  std::string a = "test/best";
  std::string test = removePath(a);
  REQUIRE(test == "1 FAILED");
}