//
// Created by knapp on 10/07/2020.
//

#include "tree.h"
Node::Node() { data = "root"; }

Node Node::CreateNode(std::vector<Node> escapePath,
                      std::vector<std::string> lexed) {
  if (lexed.size() > 0) {
    data = lexed.front();
    lexed.erase(lexed.begin());
  }
}

Node sort(std::vector<std::string> lexed) {
  std::vector<Node> escapePath = {};
  Node tree = Node();
  for (int i = 0; i < lexed.size(); i++) {
    if (lexed.front().at(0) == 'i') {
    } else if (lexed.front().at(0) == 'n') {
    } else if (lexed.front().at(0) == 'd') {
      if (lexed.front() == "dPRAREN" || lexed.front() == "dLCURLY") {
      }
    } else if (lexed.front().at(0) == 'c') {
    } else if (lexed.front().at(0) == 's') {
    }
  }
  std::cout << tree.data;

  return tree;
}
