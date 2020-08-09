//
// Created by knapp on 07/08/2020.
//

#include "fileInput.h"

TEST_CASE("include: check that empty string breaks correctly") {
  std::string a = "";
  std::string text = "";
  Result result = fileInput(text, a, "");
  REQUIRE(result.state == 10);
}

TEST_CASE("include: checks that non existent file reported correctly") {
  std::string a = "noExist.k";
  std::string text = "";
  Result result = fileInput(text, a, "");
  REQUIRE(result.state == 10);
}

TEST_CASE("include: loads an empty file") {
  std::string a = "test/include/empty.k";
  std::string text = "";
  Result result = fileInput(text, a, "");
  REQUIRE(result.text == "");
  REQUIRE(result.state == 0);
}

TEST_CASE("include: loads a valid file with a bad include") {
  std::string a = "test/include/badInclude.k";
  std::string text = "";
  Result result = fileInput(text, a, "");
  REQUIRE(result.state == 10);
}

TEST_CASE("include: check that a simple file is correctly included") {
  std::string a = "test/include/simple.k";
  std::string text = "";
  Result result = fileInput(text, a, "");
  REQUIRE(result.text == "int main(){\nreturn 0;\n}");
  REQUIRE(result.state == 0);
}

TEST_CASE("include: check that a include file from a directory to another") {
  std::string a = "test/include/includeFoward.k";
  std::string text = "";
  Result result = fileInput(text, a, "");
  REQUIRE(result.text == "");
  REQUIRE(result.state == 0);
}

TEST_CASE("include: check that a include file from a previous directory") {
  std::string a = "test/include/testhold/includeBack.k";
  std::string text = "";
  Result result = fileInput(text, a, "");
  REQUIRE(result.text == "");
  REQUIRE(result.state == 0);
}