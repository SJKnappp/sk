//
// Created by knapp on 10/07/2020.
//

#ifndef COMPILER_TREE_H
#define COMPILER_TREE_H

#include <memory>

#include "main.h"
class Node {
public:
  Node(std::vector<Node> escapePath, std::vector<std::string> lexed);

  std::string data;
  Node *branch;
};

#endif // COMPILER_TREE_H
