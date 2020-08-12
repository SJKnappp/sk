//
// Created by knapp on 09/08/2020.
//

#include "tree.h"
num::num(std::string flag, std::vector<std::vector<symbolTable>> &symbol,
         int location) {
  try {
    if (flag.at(0) != 'n' || flag.size() <= 1) {
      state = 21;
      return;
    }
  } catch (const std::exception &e) {
    state = 23;
    return;
  }

  flag.erase(0, 1);
  data = flag;
  state = 0;
}

void num::display(std::string *text, std::string tab, bool top) {
  tab += "\t";
  text->append("\n");
  text->append(tab);
  text->append(this->type());
}

void assembly(std::string &text) {}
