//
// Created by knapp on 10/07/2020.
//

#ifndef COMPILER_TREE_H
#define COMPILER_TREE_H

//#include <memory>

#include "main.h"
#include <stack>

class Node {
public:
  Node() {}
  Node *parent = nullptr;
  std::string data = "";
  std::string result = "";
};

class empty : public Node {
public:
  empty(std::string Result);

protected:
  virtual std::string type() { return "empty"; }
};

class branch : public Node {
public:
  branch(Node *Parent, std::vector<std::string> *lexed, bool top = false);
  std::vector<Node *> branches; // stores ordered list of nodes
  bool failed;

protected:
  std::string type() { return "branch"; }
};

class returnNode : public Node {
public:
  returnNode(std::vector<std::string> *lexed);
  Node *val;

protected:
  std::string type() { return "returnNode"; }
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

class compare : public binaryTree {
public:
  compare(Node *Parent, std::string *Keyword);
};

class num : public Node {
protected:
  std::string type() { return "Num"; }
};

class identifier : public Node {
public:
  identifier(std::string flag);

protected:
  std::string type() { return "Num"; }
};

void condition(std::vector<std::string> *lexed, Node *current);
Node *build(std::vector<std::string> *lexed, Node *current, Node &ret,
            bool top = false);
#endif // COMPILER_TREE_H
