//
// Created by knapp on 03/08/2020.
//

#ifndef COMPILER_SYMBOL_H
#define COMPILER_SYMBOL_H

#include <iostream>
#include <string>
#include <vector>

class symbolTable {
public:
  symbolTable(std::string Symbol, std::string Type, std::string Scope);
  std::string symbol; // name
  std::string type;   //
  std::string scope;  // "l" local "g" global
};

bool searchDown(std::vector<std::vector<symbolTable>> table, int location,
                std::string search);
int searchArross(std::vector<std::vector<symbolTable>> table,
                 std::string search);
bool searchAll(std::vector<std::vector<symbolTable>> table, std::string search);

#endif // COMPILER_SYMBOL_H
