//
// Created by knapp on 07/08/2020.
//

// TODO get expected results in tests impleented/

#include "fileInput.h"

TEST_CASE("include: check that empty string breaks correctly") {
  std::string a = "";
  std::string text = "";
  std::string result = fileInput(text, a, "");
  REQUIRE(result == "2");
}

TEST_CASE("include: checks that non existent file reported correctly") {
  std::string a = "noExist.k";
  std::string text = "";
  std::string result = fileInput(text, a, "");
  REQUIRE(result == "2 noExists.k");
}

TEST_CASE("include: loads an empty file") {
  std::string a = "test/include/empty.k";
  std::string text = "";
  std::string result = fileInput(text, a, "");
  REQUIRE(result == "");
}

TEST_CASE("include: loads a valid file with a bad include") {
  std::string a = "test/include/badInclude.k";
  std::string text = "";
  std::string result = fileInput(text, a, "");
  REQUIRE(result == "2 badInclude.k");
}

TEST_CASE("include: check that a simple file is correctly included") {
  std::string a = "test/include/simple.k";
  std::string text = "";
  std::string result = fileInput(text, a, "");
  REQUIRE(result == "\nint main(){\nreturn 0;\n}");
}

TEST_CASE("include: check that a include file from a directory to another") {
  std::string a = "test/include/includeFow.k";
  std::string text = "";
  std::string result = fileInput(text, a, "");
  REQUIRE(result == "");
}

TEST_CASE("include: check that a include file from a previous directory") {
  std::string a = "test/include/testhold/includeBack.k";
  std::string text = "";
  std::string result = fileInput(text, a, "");
  REQUIRE(result == "");
}

TEST_CASE("include: a simple ") {
  std::string a = "test/include/include/simple.k";
  std::string text = "";
  std::string result = fileInput(text, a, "");
  REQUIRE(result == "");
}