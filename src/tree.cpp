//
// Created by knapp on 10/07/2020.
//

#include "tree.h"

void sort(std::vector<std::string> lexed) {
  std::vector<Node *> keypoint; // holds key peints to be used once i.e if while
  std::vector<Node *> escapePath = {}; // gets to keypoints branch nodes i.e {
  // holds route to get to point for all node might be not needed
  std::vector<Node *> path = {};
  Node *current;

  {
    branch tree = branch(nullptr, true);
    current = &tree;
    escapePath.push_back(&tree);
    path.push_back(&tree);
  }
  for (int i = 0; i < lexed.size(); i++) {

    if (lexed.at(i).at(0) == 'i') {
    } else if (lexed.at(i).at(0) == 'n') {
    } else if (lexed.at(i).at(0) == 'd') {
      if (lexed.at(i) == "dLCURLY") {
        Node *old = path.back();
        branch temp = branch(path.back());
        escapePath.push_back(&temp);
        path.push_back(&temp);
      } else if (lexed.at(i) == "dRCURLY") {
        current = escapePath.back();
        escapePath.pop_back();
      }
    } else if (lexed.at(i).at(0) == 'c') {
    } else if (lexed.at(i).at(0) == 's') {
      std::cout << lexed.at(i);
      binop temp = binop(path.back(), &lexed.at(i));
      path.push_back(&temp);
    }
  }
  std::cout << path.back()->data;

  //  return tree;
}

Node *build(std::vector<std::string> lexed,
            Node *current) { // a recursive function to replace sort

  if (lexed.size() == 0) {
    return {};
  }

  if (lexed.front().at(0) == 'i') {
  } else if (lexed.front().at(0) == 'n') {
  } else if (lexed.front().at(0) == 'd') {
    if (lexed.front() == "dLCURLY") {
      branch Branch = branch(current);
      bool closed = false;
      while (closed == false) {
        lexed.erase(lexed.begin());
        Node *Temp = build(lexed, &Branch);

        Branch.branches.push_back(Temp);
      }

    } else if (lexed.front() == "dRCURLY") {
      return {};
    }
  } else if (lexed.front().at(0) == 'c') {
  } else if (lexed.front().at(0) == 's') {
    std::cout << lexed.front();
    binop temp = binop(current, &lexed.front());
    lexed.erase(lexed.begin());
    build(lexed, current);
  }
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
