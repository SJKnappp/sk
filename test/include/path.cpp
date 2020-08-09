//
// Created by knapp on 07/08/2020.
//

#include "fileInput.h"

TEST_CASE("include: path input empty lcoation and file") {
  std::string file = "";
  std::string location = "";
  int result = path(file, location);
  REQUIRE(file == "");
  REQUIRE(location == "");
  REQUIRE(result == 1);
}

TEST_CASE("include: path empty location and ../ file location") {
  std::string file = "../noExist.k";
  std::string location = "";

  int result = path(file, location);
  REQUIRE(file == "noExist.k");
  REQUIRE(location == "../");
  REQUIRE(result == 0);
}
