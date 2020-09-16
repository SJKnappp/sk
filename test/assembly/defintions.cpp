//
// Created by knapp on 06/08/2020.
//

#include "assembly.h"

TEST_CASE("Empty ast generation correctly builds the minimum assembly",
          "[multi-file:2]") {
    std::vector<std::vector<symbolTable>> symbol = {};
    std::string t = ass::gen(nullptr, symbol);
    REQUIRE(t == "Section .text\n\tglobal _start");
}

TEST_CASE("assembly file is correctly initiated", "[multi-file:2]") {
  std::string text, data;
  std::vector<std::string> body;
  ass::init(&text, &body, &data);
  std::string temp = text + body.at(0) + data;
  REQUIRE(temp == "Section .text\n\tglobal _start\n_start\nSection .data");
}