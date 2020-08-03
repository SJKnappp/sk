//
// Created by knapp on 03/08/2020.
//

#ifndef COMPILER_SYMBOL_H
#define COMPILER_SYMBOL_H

#include <string>

class symbolTable {
public:
  symbolTable(std::string Symbol, std::string Type, std::string Scope);
  std::string symbol;
  std::string type;
  std::string scope;
};

#endif // COMPILER_SYMBOL_H
