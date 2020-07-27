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
      std::unique_ptr<assign> ret = std::make_unique<assign>(assign(lexed));
      branches.push_back(std::move(ret));
    } else if (lexed->front() == "VOIDSYM") {
    } else if (lexed->front() == "RETURNSYM") {
      // returnNode ReturnNode(lexed);
      std::unique_ptr<Node> ret =
          std::make_unique<returnNode>(returnNode(lexed));
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
  lexed->erase(lexed->begin());
  if (lexed->size() > 0) {
    if (lexed->front().at(0) == 'i') {
      identifier Iden(lexed->front());
      std::unique_ptr<Node> ret = std::make_unique<identifier>(Iden);
      val = std::move(ret);
    } else if (lexed->front().at(0) == 'n') {
      identifier Iden(lexed->front());
      std::unique_ptr<Node> ret = std::make_unique<identifier>(Iden);
      val = std::move(ret);
    } else if (lexed->front() == "SEMICOLON") {
    } else {
      lexed = {};
      std::cout << "failed";
    }
  }
  // temp = build(lexed, temp, NULL, false);
}

binop::binop(std::vector<std::string> *lexed) {
  //
  std::vector<std::string> list;
  for (int i = 0; i < lexed->size(); i++) {
    if (lexed->at(i).at(0) == 'n') {

    } else if (lexed->at(i).at(0) == 'i') {

    } else if (lexed->at(i) == "PLUS") {
    } else if (lexed->at(i) == "MINUS") {
    } else if (lexed->at(i) == "TIMES") {
    } else if (lexed->at(i) == "SLASH") {
    } else if (lexed->at(i) == "LPAREN") {
    } else if (lexed->at(i) == "RPAREN") {
    }
  }
}

compare::compare(Node *Parent, std::string *Keyword) {
  if (Parent != nullptr) {
    parent = Parent;
  }
  data = *Keyword;
}

identifier::identifier(std::string flag) { data = flag; }

assign::assign(std::vector<std::string> *lexed) {
  std::vector<std::string> generated;

  std::string type = lexed->front();
  lexed->erase(lexed->begin());

  std::string Name = lexed->front();
  lexed->erase(lexed->begin());

  if (lexed->front() == "SEMICOLON") {
    return;
  } else if (lexed->front() != "EQL") {
    std::cout << "found unexpected symbole";
    lexed = {};
    return;
  }

  bool running = true;
  int i = 0;
  while (running) {
    if (lexed->at(i) == "SEMICOLON") {
      running = false;
    } else {
      generated.push_back(lexed->at(i));
    }
    lexed->erase(lexed->begin());
  }

  if (generated.size() == 1) {
    std::cout << "expected an identifier";
    return;
  }

  if (Name.at(0) == 'i') {
    std::unique_ptr<identifier> var =
        std::make_unique<identifier>(identifier(Name));
    left = std::move(var);
  }

  std::unique_ptr<identifier> var;
  switch (generated.size() == 0) {
  case 0:
    std::cout << "expected statment after equals sign";
    break;
  case 1:
    var = std::make_unique<identifier>(identifier(generated.at(0)));
    break;
  default:
    binop(*generated);
    break;
  }
}