//
// Created by knapp on 06/08/2020.
//

#include "catch.hpp"

TEST_CASE("1: All test cases reside in other .cpp files (empty)",
          "[multi-file:1]") {
  std::string t = "";
  REQUIRE(t == "");
}