//
// Created by knapp on 09/08/2020.
//

#include "tree.h"

void binaryTree::display(std::string *text, std::string tab, bool top) {
  tab += "\t";
  text->append("\n");
  text->append(tab);
  text->append(this->type());
}

void binaryTree::assembly(std::string &text, std::vector<std::string> &function,
                          std::string &data,
                          std::vector<std::vector<symbolTable>> &symbol) {}