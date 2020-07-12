//
// Created by knapp on 10/07/2020.
//

#include "tree.h"

// a recursive function to replace sort
Node *build(std::vector<std::string> *lexed, Node *current, bool top) {
  if (!top) {
    lexed->erase(lexed->begin());
  } else {
    branch top = current;
    Node *temp;
    lexed->insert(lexed->begin(), "s");
    while (lexed->size() > 0) {
      temp = build(*lexed, &top);
      if (temp != nullptr) {
        top.branches.push_back(temp);
      } else {
        std::cout << "parser failed at flag " << lexed->front();
        return {};
      }
    }
  }

  if (lexed->size() == 0) {
    return {};
  }

  if (lexed->at(0).at(0) == 'i') {
  } else if (lexed->front().at(0) == 'n') {
  } else if (lexed->front().at(0) == 'd') {
    if (lexed->front() == "dLCURLY") {
      branch Branch = branch(current);
      bool closed = false;
      while (closed == false) {

        Node *Temp = build(*lexed, &Branch);
        if (&Temp == nullptr) {
          closed = true;
          //          pass;
        }
        Branch.branches.push_back(Temp);
      }

    } else if (lexed->front() == "dRCURLY") {
      return {};
    }
  } else if (lexed->front().at(0) == 'c') {
  } else if (lexed->front().at(0) == 's') {
    std::cout << lexed->front();
    binop temp = binop(current, &lexed->front());
    lexed->erase(lexed->begin());
    build(*lexed, current);
  }
  return nullptr;
}

branch::branch(Node *Parent, bool top) {
  if (!top) {
    parent = Parent;
  } else {
    parent = nullptr;
    data = "top";
  }
}

binop::binop(Node *Parent, std::string *Keyword) {
  if (Parent != nullptr) {
    parent = Parent;
  }
  data = *Keyword;
}
