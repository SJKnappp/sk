//
// Created by knapp on 05/08/2020.
//

#include "ass.h"

namespace ass {
std::string gen() {

  // holds each section of data
  std::string text;
  std::vector<std::string> function;
  std::string data;

  init(&text, &function, &data);

  std::string result = finial(&text, &function, &data);

  return result;
}

void init(std::string *text, std::vector<std::string> *body,
          std::string *data) {
  text->append("Section .text\n\tglobal _start");
  // first function will be start
  body->push_back("\n_start");
  data->append("\nSection .data");
}

std::string finial(std::string *text, std::vector<std::string> *function,
                   std::string *data) {
  function->at(0).append("\nmov eax, 1\n\t int0x80");

  std::string body;
  for (int i = 0; i < function->size(); i++)
    body += function->at(i);

  std::string result = *text + body + *data;
}
} // namespace ass

#include "ass.h"
