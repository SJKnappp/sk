//
// Created by knapp on 09/08/2020.
//

#include "parser.h"

TEST_CASE("searchDown: with vaild search", "[search]") {
  std::vector<std::vector<symbolTable>> a;
  std::vector<symbolTable> temp;
  a.push_back(temp);
  symbolTable b("a", "", "");
  symbolTable c("b", "", "");
  symbolTable d("c", "", "");

  a.at(0).push_back(b);
  a.at(0).push_back(c);
  a.at(0).push_back(d);

  bool result = searchDown(a, 0, "a");
  REQUIRE(result == true);
}

TEST_CASE("searchDown: invailid location search", "[search]") {
  std::vector<std::vector<symbolTable>> a;
  std::vector<symbolTable> temp;
  a.push_back(temp);
  symbolTable b("a", "", "");
  symbolTable c("b", "", "");
  symbolTable d("c", "", "");

  a.at(0).push_back(b);
  a.at(0).push_back(c);
  a.at(0).push_back(d);

  bool result = searchDown(a, 1, "d");
  REQUIRE(result == false);
}
TEST_CASE("searchDown: without search term", "[search]") {
  std::vector<std::vector<symbolTable>> a;
  std::vector<symbolTable> temp;
  a.push_back(temp);
  symbolTable b("a", "", "");
  symbolTable c("b", "", "");
  symbolTable d("c", "", "");

  a.at(0).push_back(b);
  a.at(0).push_back(c);
  a.at(0).push_back(d);

  bool result = searchDown(a, 0, "d");
  REQUIRE(result == false);
}

TEST_CASE("searchAccros: with vaild search", "[search]") {
  std::vector<std::vector<symbolTable>> a;
  std::vector<symbolTable> temp;
  symbolTable b("a", "", "");
  temp.push_back(b);
  a.push_back(temp);
  symbolTable c("b", "", "");
  temp.empty();
  temp.push_back(c);
  a.push_back(temp);
  symbolTable d("c", "", "");
  temp.empty();
  temp.push_back(c);
  a.push_back(temp);

  bool result = searchArross(a, "a");
  REQUIRE(result == true);
}

TEST_CASE("searchAccros: with invaild search", "[search]") {
  std::vector<std::vector<symbolTable>> a;
  std::vector<symbolTable> temp;
  symbolTable b("a", "", "");
  temp.push_back(b);
  a.push_back(temp);
  symbolTable c("b", "", "");
  temp.empty();
  temp.push_back(c);
  a.push_back(temp);
  symbolTable d("c", "", "");
  temp.empty();
  temp.push_back(c);
  a.push_back(temp);

  bool result = searchArross(a, "d");
  REQUIRE(result == false);
}

TEST_CASE("searchAll: with vaild search", "[search]") {
  std::vector<std::vector<symbolTable>> a;
  std::vector<symbolTable> temp;
  symbolTable b("a", "", "");
  temp.push_back(b);
  a.push_back(temp);
  symbolTable c("b", "", "");
  temp.empty();
  temp.push_back(c);
  a.push_back(temp);
  symbolTable d("c", "", "");
  temp.empty();
  temp.push_back(c);
  a.push_back(temp);

  bool result = searchAll(a, "a");
  REQUIRE(result == true);
}

TEST_CASE("searchAll: with invaild search", "[search]") {
  std::vector<std::vector<symbolTable>> a;
  std::vector<symbolTable> temp;
  symbolTable b("a", "", "");
  temp.push_back(b);
  a.push_back(temp);
  symbolTable c("b", "", "");
  temp.empty();
  temp.push_back(c);
  a.push_back(temp);
  symbolTable d("c", "", "");
  temp.empty();
  temp.push_back(c);
  a.push_back(temp);

  bool result = searchAll(a, "d");
  REQUIRE(result == false);
}
