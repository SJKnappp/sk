//
// Created by knapp on 09/08/2020.
//

#include "tree.h"

identifier::identifier(std::string flag,
                       std::vector<std::vector<symbolTable>> &symbol,
                       int location, bool def, bool function,
                       std::string type) {
  // used try and catch as only test cases call empty flags
  try {
    if (flag.at(0) != 'i' || flag.size() <= 1) {
      state = 21;
      return;
    }
  } catch (const std::exception &e) {
    state = 23;
    return;
  }

  isFunction = function;

  flag.erase(0, 1);
  int exists = false;
  if (def == true) { // is a defintion
    if (function == true) {
      exists = searchArross(symbol, flag);
      if (exists == -1) {
        std::vector<symbolTable> temp;
        // todo add type in incldue
          temp.push_back(symbolTable(flag, type, "g"));
          symbol.push_back(temp);
      }
    } else {
        exists = searchDown(symbol, location, flag);
        if (!exists) {
            symbol.at(location).push_back(symbolTable(flag, type, "l"));
        }
        exists--;
    }
  } else {

  }
    if (exists == -1) {
        data = flag;
        state = 0;
    } else {
        state = 24;
        return;
    }
}

void identifier::display(std::string *text, std::string tab, bool top) {
  tab += "\t";
  text->append("\n");
  text->append(tab);
  text->append(this->type());
}

void identifier::assembly(std::string &text, std::vector<std::string> &function,
                          std::string &data,
                          std::vector<std::vector<symbolTable>> &symbol) {}