//
// Created by knapp on 09/08/2020.
//

#include "tree.h"

assign::assign(std::vector<std::string> *lexed,
               std::vector<std::vector<symbolTable>> &symbol, int location) {

  std::vector<std::string> generated;

  std::string type = lexed->front();
  lexed->erase(lexed->begin());

  if (lexed->empty()) {
    state = 23;
    return;
  }

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
      var = std::make_unique<num>(num(generated.at(0), symbol, location));
      right = std::move(var);
    }
    break;
  default:
    binop(*generated);
    break;
  }
}

void assign::display(std::string *text, std::string tab, bool top) {
  tab += "\t";
  text->append("\n");
  text->append(tab);
  text->append(this->type());
  if (this->left != nullptr) {
    this->left->display(text, tab);
  }
  if (this->right != nullptr) {
    this->right->display(text, tab);
  }
}