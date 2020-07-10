//
// Created by knapp on 10/07/2020.
//

#include "tree.h"

Node::Node(std::vector<Node> escapePath, std::vector<std::string> lexed) {
  if (lexed.size() > 0) {
    data = lexed.front();
    lexed.erase(lexed.begin());
  }
}

Node sort(std::vector<std::string> lexed) {
  std::vector<Node> escapePath = {};
  Node tree = Node(escapePath, lexed);
  return tree;
}
