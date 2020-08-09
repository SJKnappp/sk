//
// Created by knapp on 09/08/2020.
//

#include "tree.h"

returnNode::returnNode(std::vector<std::string> *lexed) {
  Node *temp = this;
  lexed->erase(lexed->begin());
  if (lexed->size() > 0) {
    if (lexed->front().at(0) == 'i') {
      identifier Iden(lexed->front());
      std::unique_ptr<Node> ret = std::make_unique<identifier>(Iden);
      val = std::move(ret);
      lexed->erase(lexed->begin());
    } else if (lexed->front().at(0) == 'n') {
      identifier Iden(lexed->front());
      std::unique_ptr<Node> ret = std::make_unique<identifier>(Iden);
      val = std::move(ret);
      lexed->erase(lexed->begin());
    } else if (lexed->front() == "SEMICOLON") {
      lexed->erase(lexed->begin());
    } else {
      lexed = {};
      std::cout << "failed";
    }
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
