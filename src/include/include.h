//
// Created by knapp on 10/07/2020.
//

#ifndef COMPILER_INCLUDE_H
#define COMPILER_INCLUDE_H
#include "../main.h"

struct Result {
  std::string text;
  int state;
};

Result fileInput(std::string text, const std::string &file,
                 std::string location = "");

// remove an item off the path
Result removePath(std::string location);

#endif // COMPILER_INCLUDE_H
