//
// Created by knapp on 10/07/2020.
//

#ifndef COMPILER_TREE_H
#define COMPILER_TREE_H

#include <memory>

#include "main.h"
class Node {
public:
  Node();
  Node CreateNode(std::vector<Node> escapePath, std::vector<std::string> lexed);

  std::string data;
  Node *branch;
};

class binaryTree : public Node {
public:
  Node *left;
  Node *right;
};

class operation : public binaryTree {
public:
  std::string token;
};

class Num : public Node {};

Node sort(std::vector<std::string> lexed);

#endif // COMPILER_TREE_H
