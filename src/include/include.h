//
// Created by knapp on 10/07/2020.
//

#ifndef COMPILER_INCLUDE_H
#define COMPILER_INCLUDE_H
#include "../main.h"
std::string fileInput(std::string text, const std::string &file,
                      std::string location = "");

// remove an item off the path
std::string removePath(std::string location);

#endif // COMPILER_INCLUDE_H
