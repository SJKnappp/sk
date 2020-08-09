//
// Created by knapp on 09/08/2020.
//

#include "tree.h"

branch::branch(std::vector<std::string> *lexed,
               std::vector<std::vector<symbolTable>> &symbol, int location,
               bool top) {
  state = 0;
  if (!top) {
  } else {
    data = "top";
    lexed->insert(lexed->begin(), "first");
  }

  if (lexed == nullptr || lexed->empty()) {
    return;
  }

  lexed->erase(lexed->begin());
  while (lexed->size() > 0) {
    //    lexed->erase(lexed->begin());
    if (lexed->empty()) {
      break;
    }

    // for tokens not usable from branch trow an error
    if (lexed->front() == "PLUS" || lexed->front() == "MINUS" ||
        lexed->front() == "TIMES" || lexed->front() == "SLASH" ||
        lexed->front() == "LPAREN" || lexed->front() == "RPAREN" ||
        lexed->front() == "PERIOD" || lexed->front() == "EQL" ||
        lexed->front() == "COM" || lexed->front() == "NQL" ||
        lexed->front() == "LSS" || lexed->front() == "GTR" ||
        lexed->front() == "LEQ" || lexed->front() == "GEQ") {
      state = 21;
      std::cout << lexed->front() << " token not reconised";
      return;
    } else if (lexed->front() == "LCURLY") { // creates a new branch node
      std::vector<symbolTable> temp = {};
      std::unique_ptr<branch> Branch =
          std::make_unique<branch>(branch(lexed, symbol, 0));
      Branch->result = "branch";
      branches.push_back(std::move(Branch));
    } else if (lexed->front() == "RCURLY") { // will be used to end the branch
      break; // exits while loop to end the branch
    } else if (lexed->front() == "SEMICOLON") { // ends a line
      lexed->erase(lexed->begin());
    } else if (lexed->front() == "CONSTSYM") {
      // todo
      state = 22;
      return;
    } else if (lexed->front() == "IFSYM") {
      // todo
      state = 22;
      return;
    } else if (lexed->front() == "WHILESYM") {
      // todo
      state = 22;
      return;
    } else if (lexed->front() == "INTSYM") {
      std::unique_ptr<assign> ret =
          std::make_unique<assign>(assign(lexed, symbol, location));
      branches.push_back(std::move(ret));
      if (branches.back()->state != 0) {
        state = branches.back()->state;
        return;
      }
    } else if (lexed->front() == "VOIDSYM") {
      // todo
      state = 22;
      return;
    } else if (lexed->front() == "RETURNSYM") {
      // returnNode ReturnNode(lexed);
      std::unique_ptr<Node> ret =
          std::make_unique<returnNode>(returnNode(lexed));
      branches.push_back(std::move(ret));
    } else if (lexed->at(0).at(0) == 'i') { // identifer
      identifier Iden(lexed->front());
      std::unique_ptr<Node> ret = std::make_unique<identifier>(Iden);
      branches.push_back(std::move(ret));
      lexed->erase(lexed->begin());
    } else if (lexed->front().at(0) == 'n') { // number
      identifier Iden(lexed->front());
      std::unique_ptr<Node> ret = std::make_unique<identifier>(Iden);
      lexed->erase(lexed->begin());
      branches.push_back(std::move(ret));
    } else {
      state = 22;
      return;
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