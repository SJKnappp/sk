//
// Created by knapp on 09/08/2020.
//

#include "tree.h"

returnNode::returnNode(std::vector<std::string> *lexed,
                       std::vector<std::vector<symbolTable>> &symbol,
                       int location) {

  Node *temp = this;
  if (lexed->size() > 1) {
    lexed->erase(lexed->begin());
    if (lexed->front().at(0) == 'i') {
      identifier Iden(lexed->front(), symbol, location);
      std::unique_ptr<Node> ret = std::make_unique<identifier>(Iden);
      val = std::move(ret);
      lexed->erase(lexed->begin());
      state = 0;
    } else if (lexed->front().at(0) == 'n') {
      identifier Iden(lexed->front(), symbol, location);
      std::unique_ptr<Node> ret = std::make_unique<identifier>(Iden);
      val = std::move(ret);
      lexed->erase(lexed->begin());
      state = 0;
    } else if (lexed->front() == "SEMICOLON") {
      lexed->erase(lexed->begin());
    } else {
      lexed = {};
      std::cout << "failed";
    }
  } else {
    state = 23;
  }
  // temp = build(lexed, temp, NULL, false);
}

void returnNode::display(std::string *text, std::string tab, bool top) {
  tab += "\t";
  text->append("\n");
  text->append(tab);
  text->append(this->type());
  if (this->val != nullptr) {
    this->val->display(text, tab);
  }
}
