//
// Created by knapp on 03/08/2020.
//

#include "symbol.h"

symbolTable::symbolTable(std::string Symbol, std::string Type,
                         std::string Scope) {
  symbol = Symbol;
  type = Type;
  scope = Scope;
}

// search a singe location if a varible exists
bool searchDown(std::vector<std::vector<symbolTable>> table, int location,
                std::string search) {
  if (location >= table.size()) {
    return false;
  }

  for (int i = 0; i < table.at(location).size(); i++) {
    if (table.at(location).at(i).symbol == search) {
      return true;
    }
  }
  return false;
}

// search for function names
bool searchArross(std::vector<std::vector<symbolTable>> table,
                  std::string search) {

  for (int i = 0; i < table.size(); i++) {
    if (table.at(i).at(0).symbol == search) {
      return true;
    }
  }
  return false;
}

bool searchAll(std::vector<std::vector<symbolTable>> table,
               std::string search) {
  for (int i = 0; i < table.size(); i++) {
    for (int j = 0; j < table.at(i).size(); j++) {
      if (table.at(i).at(j).symbol == search) {
        return true;
      }
    }
  }
  return false;
}