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

branch::branch(Node *Parent, std::vector<symbolTable> *symbol,
               std::vector<std::string> *lexed, bool top) {
  if (!top) {
    parent = Parent;
  } else {
    parent = nullptr;
    data = "top";
    lexed->insert(lexed->begin(), "first");
  }
  lexed->erase(lexed->begin());
  while (lexed->size() > 0) {
    //    lexed->erase(lexed->begin());
    if (lexed->empty()) {
      break;
    }

    // for tokens not usable from branch trow an error

    if (lexed->front() == "PLUS") {
    } else if (lexed->front() == "MINUS") {  // can only be seen after identifer
    } else if (lexed->front() == "TIMES") {  // or equal as cannot start line
    } else if (lexed->front() == "SLASH") {  //
    } else if (lexed->front() == "LPAREN") { // will be delt with identifer
    } else if (lexed->front() == "RPAREN") { //
    } else if (lexed->front() == "LCURLY") { // creates a new branch node
      std::vector<symbolTable> temp = {};
      std::unique_ptr<branch> Branch =
          std::make_unique<branch>(branch(this, &temp, lexed));
      Branch->result = "branch";
      branches.push_back(std::move(Branch));
    } else if (lexed->front() == "RCURLY") { // will be used to end the branch
      break; // exits while loop to end the branch
    } else if (lexed->front() == "SEMICOLON") { // ends a line
      lexed->erase(lexed->begin());
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
  bool numExpected = true;
  bool firstNum = true;
  bool firstExpresion = true;

  std::vector<std::string> listLeft;
  std::vector<std::string> listRight;

  if (lexed->size() == 3) {
    if (lexed->at(0).at(0) == 'i' || lexed->at(0).at(0) == 'n') {
      std::unique_ptr<identifier> var =
          std::make_unique<identifier>(identifier(lexed->at(0)));
      left = std::move(var);
    } else {
    }
    if (lexed->at(1) == "PLUS" || lexed->at(1) == "MINUS" ||
        lexed->at(1) == "TIMES" || lexed->at(1) == "SLASH" ||
        lexed->at(1) == "LPAREN" || lexed->at(1) == "RPAREN") {
      data = lexed->at(1);
    } else {
    }
    if (lexed->at(2).at(0) == 'i' || lexed->at(2).at(0) == 'n') {
      std::unique_ptr<identifier> var =
          std::make_unique<identifier>(identifier(lexed->at(2)));
      right = std::move(var);
    } else {
    }
    return;
  }

  for (int i = 0; i < lexed->size(); i++) {
    if (lexed->at(0).at(0) == 'i' || lexed->at(0).at(0) == 'n') {
      if (numExpected == true) {
        numExpected = false;
        if (firstNum == true) {
          firstNum = false;
        } else {
          listRight.push_back(lexed->at(i));
        }
      }
    } else if (lexed->at(1) == "PLUS" || lexed->at(1) == "MINUS" ||
               lexed->at(1) == "TIMES" || lexed->at(1) == "SLASH" ||
               lexed->at(1) == "LPAREN" || lexed->at(1) == "RPAREN") {
      if (numExpected == false) {
        numExpected = true;
        if (firstExpresion) {
          firstExpresion = false;
          data = lexed->at(i);
        } else {
          listRight.push_back(lexed->at(i));
        }
      }
      if (i == lexed->size()) {
        std::cout << "found unexpected symbol at end of expression";
        return;
      } else if (i == 0) {
        std::cout << "found unexpected symbol at start of expression";
        return;
      }
    }
  }
  std::unique_ptr<binop> var = std::make_unique<binop>(binop(&listLeft));
  right = std::move(var);
}

compare::compare(Node *Parent, std::string *Keyword) {
  if (Parent != nullptr) {
    parent = Parent;
  }
  data = *Keyword;
}

identifier::identifier(std::string flag) { data = flag; }

num::num(std::string flag) { data = flag; }

assign::assign(std::vector<std::string> *lexed) {

  std::vector<std::string> generated;

  std::string type = lexed->front();
  lexed->erase(lexed->begin());

  std::string Name = lexed->front();
  lexed->erase(lexed->begin());

  if (Name.at(0) == 'i') {
    std::unique_ptr<identifier> var =
        std::make_unique<identifier>(identifier(Name));
    left = std::move(var);
  }

  if (lexed->front() == "SEMICOLON") {

    return;
  } else if (lexed->front() != "EQL" && lexed->front() != "LPAREN") {
    std::cout << "found unexpected symbole";
    lexed = {};
    return;
  }

  lexed->erase(lexed->begin());

  int caseState = 0; // 0-failed 1-varible 2-function
  bool running = true;
  int i = 0;
  while (running) {
    if (lexed->at(i) == "SEMICOLON") {
      running = false;
      caseState = 1;
    } else if (lexed->at(i) == "RPAREN") {
      running = false;
      caseState = 2;
    } else {
      generated.push_back(lexed->at(i));
    }
    lexed->erase(lexed->begin());
  }

  if (generated.size() == 0 && caseState == 1) {
    std::cout << "expected an identifier";
    return;
  }

  switch (generated.size()) {
  case 0:
    std::cout << "expected statment after equals sign";
    break;
  case 1:
    if (generated.at(0).at(0) == 'i') {
      std::unique_ptr<identifier> var;
      var = std::make_unique<identifier>(identifier(generated.at(0)));
      right = std::move(var);
    } else if (generated.at(0).at(0) == 'n') {
      std::unique_ptr<num> var;
      var = std::make_unique<num>(num(generated.at(0)));
      right = std::move(var);
    }
    break;
  default:
    binop(*generated);
    break;
  }
}
