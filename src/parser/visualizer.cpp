//
// Created by knapp on 23/07/2020.
//

#include "tree.h"
void branch::display() {

  std::string tab = "";
  std::string store = "";
  for (int x = 0; x < this->branches.size(); x++) {
    store += "\n";
    store += this->branches.at(x)->data;
  }
  std::ofstream file;
  file.open("ast.txt");
  file << store;
  file.close();
}
