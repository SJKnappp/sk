//
// Created by knapp on 23/07/2020.
//

#include "tree.h"

void branch::display(std::string *text, std::string tab, bool top) {

  if (top == false) {
    tab += "\t";
    text->append("\n");
  }

  std::string store = "";
  text->append(tab);
  text->append(this->type());
  for (int x = 0; x < this->branches.size(); x++) {
    this->branches.at(x)->display(text, tab);
  }

  if (top == true) {
    std::ofstream file;
    file.open("ast.txt");
    file << *text;
    file.close();
  }
}

void returnNode::display(std::string *text, std::string tab, bool top) {
  tab += "\t";
  text->append("\n");
  text->append(tab);
  text->append(this->type());
  if (this->val != nullptr) {
    this->val->display(text, tab);
  }
}
void binaryTree::display(std::string *text, std::string tab, bool top) {
  tab += "\t";
  text->append("\n");
  text->append(tab);
  text->append(this->type());
}
void assign::display(std::string *text, std::string tab, bool top) {
  tab += "\t";
  text->append("\n");
  text->append(tab);
  text->append(this->type());
  if (this->left != nullptr) {
    this->left->display(text, tab);
  }
  if (this->right != nullptr) {
    this->right->display(text, tab);
  }
}
void binop::display(std::string *text, std::string tab, bool top) {
  tab += "\t";
  text->append("\n");
  text->append(tab);
  text->append(this->type());
}
void compare::display(std::string *text, std::string tab, bool top) {
  tab += "\t";
  text->append("\n");
  text->append(tab);
  text->append(this->type());
}
void num::display(std::string *text, std::string tab, bool top) {
  tab += "\t";
  text->append("\n");
  text->append(tab);
  text->append(this->type());
}
void identifier::display(std::string *text, std::string tab, bool top) {
  tab += "\t";
  text->append("\n");
  text->append(tab);
  text->append(this->type());
}