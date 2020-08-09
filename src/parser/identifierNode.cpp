//
// Created by knapp on 09/08/2020.
//

#include "tree.h"

identifier::identifier(std::string flag) {
  try {
    if (flag.at(0) != 'i' || flag.size() <= 1) {
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

void identifier::display(std::string *text, std::string tab, bool top) {
  tab += "\t";
  text->append("\n");
  text->append(tab);
  text->append(this->type());
}