//
// Created by knapp on 10/07/2020.
//

#include "tree.h"

// builds rules for condital points eg if while etc.
void condition(std::vector<std::string> *lexed, Node *current) {
  bool running = true;
  int i = 0;
  while (running) {
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
    lexed->insert(lexed->begin(), "first");
  }

  Node *temp;
  empty temp2("");
  while (lexed->size() > 0) {
    lexed->erase(lexed->begin());
    if (lexed->empty()) {
      break;
    }

    Node *ret;
    if (lexed->at(0).at(0) == 'i') {
      identifier Iden(lexed->front());
      std::unique_ptr<identifier> ret = std::make_unique<identifier>(Iden);
      std::unique_ptr<Node> Ide = std::move(ret);
      std::string test = Ide->data;
      branches.push_back(std::move(Ide));
    } else if (lexed->front().at(0) == 'n') {
      identifier Iden(lexed->front());
      Node *const temp = &Iden;
      //      branches.push_back(&Iden);
    } else if (lexed->front().at(0) == 'd') {
      if (lexed->front() == "dLCURLY") {
        branch Branch = branch(this, lexed);
        Branch.result = "dada";
        //        branches.push_back(&Branch);
        std::cout << "test";
      } else if (lexed->front() == "dRCURLY") {
        empty Empty("{"); // returns end of branch
      } else if (lexed->front() == "dLPAREN") {
        // needs implemting
        // compare Compare(this, &store);
      } else if (lexed->front() == "dRPAREN") {
      } else if (lexed->front() == "sRETURNSYM") {
        returnNode ReturnNode(lexed);
        //        branches.push_back(&ReturnNode);
      }
    } else if (lexed->front().at(0) == 'c') {
    } else if (lexed->front().at(0) == 's') {
      binop temp = binop(this, &lexed->front());
    }
  }
}

returnNode::returnNode(std::vector<std::string> *lexed) {
  Node *temp = this;
  // temp = build(lexed, temp, NULL, false);
}

binop::binop(Node *Parent, std::string *Keyword) {
  if (Parent != nullptr) {
    parent = Parent;
  }
  data = *Keyword;
}

compare::compare(Node *Parent, std::string *Keyword) {
  if (Parent != nullptr) {
    parent = Parent;
  }
  data = *Keyword;
}

empty::empty(std::string Result) { result = Result; }

identifier::identifier(std::string flag) { data = flag; }