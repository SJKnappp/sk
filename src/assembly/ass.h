//
// Created by knapp on 05/08/2020.
//

#ifndef COMPILER_ASS_H
#define COMPILER_ASS_H

#include "../parser/tree.h"

// namespace contains all assembly file building commands
namespace ass {
std::string gen();
void init(std::string *text, std::vector<std::string> *boby, std::string *data);
std::string finial(std::string *text, std::vector<string> *body,
                   std::string *data);
} // namespace ass

#endif // COMPILER_ASS_H
