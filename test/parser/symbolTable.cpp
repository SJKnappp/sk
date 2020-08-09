//
// Created by knapp on 09/08/2020.
//

#include "parser.h"

TEST_CASE("Symbol table", "[symbol]") {
  symbolTable a("a", "b", "c");
  REQUIRE(a.symbol == "a");
  REQUIRE(a.type == "b");
  REQUIRE(a.scope == "c");
}