//
// Created by knapp on 09/08/2020.
//

#include "parser.h"

TEST_CASE("Identifier: empty intialier") {
  identifier test("");
  REQUIRE(test.data == "");
  REQUIRE(test.state == 0);
}