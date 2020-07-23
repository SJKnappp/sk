//
// Created by knapp on 10/07/2020.
//

#include "tree.h"

// builds rules for conditional points eg if while etc.
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
}

branch::branch(Node *Parent, std::vector<std::string> *lexed, bool top) {
  if (!top) {
    parent = Parent;
  } else {
    parent = nullptr;
    data = "top";
    lexed->insert(lexed->begin(), "first");
  }

  while (lexed->size() > 0) {
    lexed->erase(lexed->begin());
    if (lexed->empty()) {
      break;
    }

    // for tokents not useable from branch trow an error

    if (lexed->front() == "PLUS") {
    } else if (lexed->front() == "MINUS") {  // can only be seen after identifer
    } else if (lexed->front() == "TIMES") {  // or equal as cannot start line
    } else if (lexed->front() == "SLASH") {  //
    } else if (lexed->front() == "LPAREN") { // will be delt with identifer
    } else if (lexed->front() == "RPAREN") { //
    } else if (lexed->front() == "LCURLY") { // creates a new branch node
      std::unique_ptr<branch> Branch =
          std::make_unique<branch>(branch(this, lexed));
      Branch->result = "branch";
      branches.push_back(std::move(Branch));
    } else if (lexed->front() == "RCURLY") { // will be used to end the branch
      break; // exits while loop to end the branch
    } else if (lexed->front() == "SEMICOLON") { // ends a line
    } else if (lexed->front() == "PERIOD") {
    } else if (lexed->front() == "EQL") {
    } else if (lexed->front() == "COM") { // these are not asseble from a
    } else if (lexed->front() == "NQL") { // branch node
    } else if (lexed->front() == "LSS") { // as there are comparsions
    } else if (lexed->front() == "GTR") { //
    } else if (lexed->front() == "LEQ") { //
    } else if (lexed->front() == "GEQ") { //
    } else if (lexed->front() == "CONSTSYM") {
    } else if (lexed->front() == "IFSYM") {
    } else if (lexed->front() == "WHILESYM") {
    } else if (lexed->front() == "INTSYM") {
    } else if (lexed->front() == "VOIDSYM") {
    } else if (lexed->front() == "RETURNSYM") {
      returnNode ReturnNode(lexed);
      std::unique_ptr<Node> ret = std::make_unique<returnNode>(ReturnNode);
      branches.push_back(std::move(ret));
    } else if (lexed->at(0).at(0) == 'i') { // identifer
      identifier Iden(lexed->front());
      std::unique_ptr<Node> ret = std::make_unique<identifier>(Iden);
      branches.push_back(std::move(ret));
    } else if (lexed->front().at(0) == 'n') { // number
      identifier Iden(lexed->front());
      std::unique_ptr<Node> ret = std::make_unique<identifier>(Iden);
      branches.push_back(std::move(ret));
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
