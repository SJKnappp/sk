//
// Created by knapp on 09/08/2020.
//

#include "tree.h"

branch::branch(std::vector<symbolTable> *symbol,
               std::vector<std::string> *lexed, bool top) {
  if (!top) {
  } else {
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
          std::make_unique<branch>(branch(&temp, lexed));
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
      lexed->erase(lexed->begin()); // temp
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

void branch::display(std::string *text, std::string tab, bool top) {

  if (top == false) {
    tab += "\t";
    text->append("\n");
  }

  std::string store = "";
  text->append(tab);
  text->append(this->type());
  for (int x = 0; x < this->branches.size(); x++) {
    this->branches.at(x)->display(text, tab);
  }

  if (top == true) {
    std::ofstream file;
    file.open("ast.txt");
    file << *text;
    file.close();
  }
}