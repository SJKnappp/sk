//
// Created by knapp on 10/07/2020.
//

#ifndef COMPILER_TREE_H
#define COMPILER_TREE_H

#include <memory>

#include "main.h"
class Node {
public:
  Node *parent;
  std::string data;

protected:
  virtual std::string type() = "";
};

class branch : public Node {
public:
  branch(Node *Parent);
  std::vector<Node *> branches; // stores ordered list of nodes
protected:
  std::string type() = "branch";
};

class binaryTree : public Node {
public:
  Node *left;
  Node *right;

protected:
  std::string type() = "binaryTree";
};

class assign : public binaryTree {
protected:
  std::string type() = "assign";
};

class binop : public binaryTree {
protected:
  std::string type() = "binop";
};

class Num : public Node {
protected:
  std::string type() = "Num";
};

Node sort(std::vector<std::string> lexed);

#endif // COMPILER_TREE_H
