//
// Created by knapp on 10/07/2020.
//

#ifndef COMPILER_TREE_H
#define COMPILER_TREE_H

//#include <memory>

#include "../main.h"
#include <memory>
#include <stack>

// Base node
class Node {
public:
  Node() {}
  Node *parent = nullptr;
  std::string data = "";
  std::string result = "";
  virtual std::string type() = 0;
  virtual void display(std::string *text, std::string tab,
                       bool top = false) = 0;
};

// stores structrial information
class branch : public Node {
public:
  branch(Node *Parent, std::vector<std::string> *lexed, bool top = false);
  std::vector<std::unique_ptr<Node>> branches; // stores ordered list of nodes
  bool failed;
  void display(std::string *text, std::string tab, bool top = false);

protected:
  std::string type() { return "branch"; }
};

// stores information relating to return values
class returnNode : public Node {
public:
  returnNode(std::vector<std::string> *lexed);
  std::unique_ptr<Node> val = nullptr; // hold identifier or number
  void display(std::string *text, std::string tab, bool top = false);

protected:
  std::string type() { return "returnNode"; }
};

// bass class for branching when theres only 2 directions
// should not be used in base state
class binaryTree : public Node {
public:
  std::unique_ptr<Node> left = nullptr;
  std::unique_ptr<Node> right = nullptr;
  void display(std::string *text, std::string tab, bool top = false);

protected:
  std::string type() { return "binaryTree"; }
};

// creates assignment of varibles
// might combine with identifier as program fleshed out
class assign : public binaryTree {
public:
  assign(std::vector<std::string> *lexed);
  void display(std::string *text, std::string tab, bool top = false);

protected:
  std::string type() { return "assign"; }
};

// stores information about cacluations ie a - b
class binop : public binaryTree {
public:
  binop(std::vector<std::string> *lexed);
  void display(std::string *text, std::string tab, bool top = false);

protected:
  std::string type() { return "binop"; }
};

// used to compare values
class compare : public binaryTree {
public:
  compare(Node *Parent, std::string *Keyword);
  void display(std::string *text, std::string tab, bool top = false);
};

// stores information about numbers
class num : public Node {
public:
  void display(std::string *text, std::string tab, bool top = false);

protected:
  std::string type() { return "Num"; }
};

// sotres information about identifier
class identifier : public Node {
public:
  identifier(std::string flag);

protected:
  std::string type() { return "Num"; }
  void display(std::string *text, std::string tab, bool top = false);
};

void condition(std::vector<std::string> *lexed, Node *current);
Node *build(std::vector<std::string> *lexed, Node *current, Node &ret,
            bool top = false);
#endif // COMPILER_TREE_H
