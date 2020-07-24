//
// Created by knapp on 23/07/2020.
//

#include "tree.h"

void branch::display(std::string *text, std::string tab, bool top) {

  std::string store = "";

  for (int x = 0; x < this->branches.size(); x++) {
    this->branches.at(x)->display(text, tab);
    store += "\n";
  }

  if (top == true) {
    std::ofstream file;
    file.open("ast.txt");
    file << store;
    file.close();
  }
}

void returnNode::display(std::string *text, std::string tab, bool top) {
  tab += "\t";
  std::string temp = *text;
  temp += "\n";
  temp += this->data;
  text = &temp;
  if (this->val != nullptr) {
    this->val->display(text, tab);
  }
}
void binaryTree::display(std::string *text, std::string tab, bool top) {
  tab += "\t";
}
void assign::display(std::string *text, std::string tab, bool top) {
  tab += "\t";
}
void binop::display(std::string *text, std::string tab, bool top) {
  tab += "\t";
}
void compare::display(std::string *text, std::string tab, bool top) {
  tab += "\t";
}
void num::display(std::string *text, std::string tab, bool top) { tab += "\t"; }
void identifier::display(std::string *text, std::string tab, bool top) {
  tab += "\t";
}