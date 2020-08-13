//
// Created by knapp on 05/08/2020.
//

#include "ass.h"

namespace ass {
std::string gen(branch *base, std::vector<std::vector<symbolTable>> &symbol) {

  // holds each section of data
  std::string text;
  std::vector<std::string> function;
  std::string data;

  init(&text, &function, &data);

  base->assembly(text, function, data, symbol);

  std::string result = finial(&text, &function, &data);

  return result;
}

void init(std::string *text, std::vector<std::string> *body,
          std::string *data) {
  text->append("Section .text\n\tglobal _start");
}

std::string finial(std::string *text, std::vector<std::string> *function,
                   std::string *data) {

  std::string body;
  for (int i = 0; i < function->size(); i++)
    body += function->at(i);

  std::string result = *text + body + *data;

  return result;
}
} // namespace ass

#include "ass.h"
