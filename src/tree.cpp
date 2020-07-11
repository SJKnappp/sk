//
// Created by knapp on 10/07/2020.
//

#include "tree.h"

void sort(std::vector<std::string> lexed) {
  std::vector<Node *> keypoint; // holds key peints to be used once i.e if while
  std::vector<Node *> escapePath = {}; // gets to keypoints ie branch nodes i.e
                                       // {
  std::vector<Node *> path =
      {}; // holds route to get to point for all node might be not needed

  {
    branch tree = branch(nullptr, true);
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
      }
    } else if (lexed.at(i).at(0) == 'c') {
    } else if (lexed.at(i).at(0) == 's') {
      std::cout << lexed.at(i);
      binop temp = binop(path.back(), lexed.at(i));
      path.push_back(&temp);
    }
  }
  std::cout << path.back()->data;

  //  return tree;
}

branch::branch(Node *Parent, bool top) {
  if (top == false) {
    parent = Parent;
  } else {
    parent = NULL;
    data = "top";
  }
}

binop::binop(Node *Parent, std::string Keyword) {
  if (Parent != NULL) {
    parent = Parent;
  }
  data = Keyword;
}
