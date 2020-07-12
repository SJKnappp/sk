//
// Created by knapp on 10/07/2020.
//

#ifndef COMPILER_TREE_H
#define COMPILER_TREE_H

#include <memory>

#include "main.h"
class Node {
public:
  Node *parent = nullptr;
  std::string data = "";

protected:
  virtual std::string type() = 0;
};

class branch : public Node {
public:
  branch(Node *Parent, bool top = false);
  std::vector<Node *> branches; // stores ordered list of nodes
protected:
  std::string type() { return "branch"; }
};

class binaryTree : public Node {
public:
  Node *left;
  Node *right;

protected:
  std::string type() { return "binaryTree"; }
};

class assign : public binaryTree {
protected:
  std::string type() { return "assign"; }
};

class binop : public binaryTree {
public:
  binop(Node *Parent, std::string *Keyword);

protected:
  std::string type() { return "binop"; }
};

class Num : public Node {
protected:
  std::string type() { return "Num"; }
};

void sort(std::vector<std::string> lexed);
Node *build(std::vector<std::string> copy, Node *current, bool top = false);
#endif // COMPILER_TREE_H
