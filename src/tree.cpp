//
// Created by knapp on 10/07/2020.
//

#include "tree.h"

// a recursive function to replace sort
Node *build(std::vector<std::string> *lexed, Node *current, bool top) {

  if (lexed->size() == 0) {
    return {};
  }

  if (lexed->at(0).at(0) == 'i') {
    identifier Iden(lexed->front());
    return &Iden;
  } else if (lexed->front().at(0) == 'n') {
    identifier Iden();
  } else if (lexed->front().at(0) == 'd') {
    if (lexed->front() == "dLCURLY") {
      branch Branch = branch(current, lexed);

    } else if (lexed->front() == "dRCURLY") {
      empty Empty("{");
      return &Empty;
    } else if (lexed->front() == "dLPAREN") {
      compare Compare(current, "ds");
      return &Compare;
    } else if (lexed->front() == "dRPAREN") {
      return {};
    } else if (lexed->front() == "sRETURNSYM") {
      returnNode ReturnNode(lexed);
      return {};
    }
  } else if (lexed->front().at(0) == 'c') {
  } else if (lexed->front().at(0) == 's') {
    binop temp = binop(current, &lexed->front());
    return &temp;
  }
  return nullptr;
}

// builds rules for condital points eg if while etc.
void condition(std::vector<std::string> *lexed, Node *current) {
  bool running = true;
  int i = 0;
  while (running == true) {
    if (lexed->at(i) == "dLParen") {
      running = false;
    }
    if (lexed->size() == i) {
      return;
    }
    if (lexed->at(i).at(0) == 'i' || lexed->at(i).at(0)) {
    }

    i++;
  }

  return;
}

branch::branch(Node *Parent, std::vector<std::string> *lexed, bool top) {
  if (!top) {
    parent = Parent;
  } else {
    parent = nullptr;
    data = "top";
  }

  Node *temp;

  while (lexed->size() > 0) {
    temp = build(lexed, this);
    if (temp != nullptr) {
      branches.push_back(temp);
    } else {
      std::cout << "parser failed at flag " << lexed->front();
      failed = true;
      lexed->clear();
    }
    lexed->erase(lexed->begin());
  }
}

returnNode::returnNode(std::vector<std::string> *lexed) {
  Node *temp = this;
  temp = build(lexed, temp);
}

binop::binop(Node *Parent, std::string *Keyword) {
  if (Parent != nullptr) {
    parent = Parent;
  }
  data = *Keyword;
}

compare::compare(Node *Parent, std::string Keyword) {
  if (Parent != nullptr) {
    parent = Parent;
  }
  data = Keyword;
}

empty::empty(std::string Result) { result = Result; }

identifier::identifier(std::string flag) { data = flag; }