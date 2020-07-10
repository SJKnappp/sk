//
// Created by knapp on 10/07/2020.
//

#ifndef COMPILER_TREE_H
#define COMPILER_TREE_H

#include <memory>

#include "main.h"
class Node {
public:
  std::string data;
};

class branch : public Node {
  std::vector<Node *> branches; // stores ordered list of nodes
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

class asign : public binaryTree {};

class binop : public binaryTree {};

class Num : public Node {};

Node sort(std::vector<std::string> lexed);

#endif // COMPILER_TREE_H
