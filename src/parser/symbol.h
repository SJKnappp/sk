//
// Created by knapp on 03/08/2020.
//

#ifndef COMPILER_SYMBOL_H
#define COMPILER_SYMBOL_H

#include <string>
#include "vector"

class symbolTable {
public:
  symbolTable(std::string Symbol, std::string Type, std::string Scope);
  std::string symbol;
  std::string type;
  std::string scope;
};

bool searchDown(std::vector<std::vector<symbolTable>> table, int location,
                std::string search);
bool searchArross(std::vector<std::vector<symbolTable>> table,
                  std::string search);
bool searchAll(std::vector<std::vector<symbolTable>> table,
               std::string search);

#endif // COMPILER_SYMBOL_H
