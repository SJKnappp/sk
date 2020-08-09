//
// Created by knapp on 09/08/2020.
//

#include "tree.h"
num::num(std::string flag) { data = flag; }

void num::display(std::string *text, std::string tab, bool top) {
  tab += "\t";
  text->append("\n");
  text->append(tab);
  text->append(this->type());
}
