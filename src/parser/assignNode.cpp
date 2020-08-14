//
// Created by knapp on 09/08/2020.
//

#include "tree.h"

// symbol table generated by assign
assign::assign(std::vector<std::string> *lexed,
               std::vector<std::vector<symbolTable>> &symbol, int location) {

  std::vector<std::string> generated;

  if (lexed->size() <= 2) {
    state = 23;
    return;
  }

  std::string type = lexed->front();
  lexed->erase(lexed->begin());

  std::string Name = lexed->front();
  lexed->erase(lexed->begin());

  bool function = 0; // 0 false 1 intialised 2 unintialed
  int varible = 0;

  if (lexed->front() == "EQL") {
    varible = 1;
  } else if (lexed->front() == "SEMICOLON") {
    varible = 2;
  } else if (lexed->front() == "LPAREN") {
    function = true;
  } else {
    state = 25;
    return;
  }

  lexed->erase(lexed->begin());

  if (Name.at(0) == 'i') {
    std::unique_ptr<identifier> var = std::make_unique<identifier>(
        identifier(Name, symbol, location, true, function, type));
    if (var->state == 0) {
      left = std::move(var);
    } else {
      state = var->state;
      return;
    }

  } else if (Name.size() == 0) {
    state = 23;
    return;
  }

  if (varible == 2) {
    state = 0;
    return;
  }

  bool running = true;
  std::vector<std::string> temp;
  while (running) {
    std::string tmp;
    if (varible == 1) {
      if (lexed->front() == "PLUS") {
        temp.push_back(lexed->front());
      } else if (lexed->front() == "MINUS") {
        temp.push_back(lexed->front());
      } else if (lexed->front() == "TIMES") {
        temp.push_back(lexed->front());
      } else if (lexed->front() == "SLASH") {
        temp.push_back(lexed->front());
      } else if (lexed->front() == "LPAREN") {
        temp.push_back(lexed->front());
      } else if (lexed->front() == "RPAREN") {
        temp.push_back(lexed->front());
      } else if (lexed->front().at(0) == 'i') {
        temp.push_back(lexed->front());
      } else if (lexed->front().at(0) == 'n') {
        temp.push_back(lexed->front());
      } else if (lexed->front() == "SEMICOLON") {
        running = false;
      }
      lexed->erase(lexed->begin());
    } else if (function == true) {
      if (lexed->front() == "INTSYM") {
        temp.push_back(lexed->front());
      } else if (lexed->front() == "COMMA") {
        temp.push_back(lexed->front());
      } else if (lexed->front().at(0) == 'i') {
        temp.push_back(lexed->front());
      } else if (lexed->front() == "RPAREN") {
        lexed->erase(lexed->begin());
        if (lexed->size() > 1) {
          if (lexed->front() == "LCURLY") {
            lexed->erase(lexed->begin());
            running = false;
            break;
          }
        } else {
          state = 23;
          return;
        }
      } else {
        state = 21;
        return;
      }
      lexed->erase(lexed->begin());
    } else {
      state = 25;
      return;
    }
  }

  if (lexed->size() == 0) {
    state = 0;
    return;
  }

  if (function == true) {

    location = symbol.size() - 1;
    std::unique_ptr<branch> var =
        std::make_unique<branch>(branch(lexed, symbol, location));
    lexed->erase(lexed->begin());
    right = std::move(var);
    state = right->state;
  }

  if (varible == 1) {
    if (temp.size() == 1) {
      if (temp.at(0).at(0) == 'i') {
        std::unique_ptr<identifier> var = std::make_unique<identifier>(
            identifier(temp.at(0), symbol, location));
        right = std::move(var);
        return;
      } else if (temp.at(0).at(0) == 'n') {
        std::unique_ptr<num> var =
            std::make_unique<num>(num(temp.at(0), symbol, location));
        right = std::move(var);
        return;
      }
    }
    std::unique_ptr<binop> var =
        std::make_unique<binop>(binop(&temp, symbol, location));
    right = std::move(var);
    state = right->state;
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

void assign::assembly(std::string &text, std::vector<std::string> &function,
                      std::string &data,
                      std::vector<std::vector<symbolTable>> &symbol) {

  if (left == nullptr) {
    return;
  }

  std::string temp;
  if (left->isFunction == true) {
    int size;
    int location = searchArross(symbol, left->data);
    if (location == -1) {
      state = 27;
      return;
    }

    for (int i = 0; i < symbol.at(location).size(); i++) {
      if (symbol.at(location).at(i).type == "INTSYM") {
        size += 4;
      }
    }

    temp += "\n_" + left->data + ":";
    temp += "\n\tpush rbp\n\tmov rbp, rsp";
    temp += "\n\tsub rsp, " + std::to_string(size);

    // end of statment
    if (left->data == "start") {
      temp += "\n\tmov eax, 1\n\tint 0x80";
    } else {
      temp += "\n\tpop rbp\n\tret";
    }
  }

  if (right != nullptr)
    right->assembly(text, function, data, symbol);

  function.push_back(temp);
}