//
// Created by knapp on 10/07/2020.
//

#include "tree.h"

Node sort(std::vector<std::string> lexed) {
  std::vector<Node> escapePath = {};
  Node tree = branch(nullptr);
  std::vector<Node *> branchstack;
  branchstack.push_back(&tree);
  for (int i = 0; i < lexed.size(); i++) {

    if (lexed.front().at(0) == 'i') {
    } else if (lexed.front().at(0) == 'n') {
    } else if (lexed.front().at(0) == 'd') {
      if (lexed.front() == "dLCURLY") {
        binaryTree();
      } else if (lexed.front() == "dRCURLY") {
      }
    } else if (lexed.front().at(0) == 'c') {
    } else if (lexed.front().at(0) == 's') {
    }
  }
  std::cout << tree.data;

  return tree;
}

operation::operation() {}
branch::branch(Node *Parent) {
  if (parent != nullptr) {
    parent = Parent;
  }
  data = "";
}
