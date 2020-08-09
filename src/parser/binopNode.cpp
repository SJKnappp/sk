//
// Created by knapp on 09/08/2020.
//

#include "tree.h"

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
void binop::display(std::string *text, std::string tab, bool top) {
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
