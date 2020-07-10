#include "lexer.h"

// prefix s for math symbol
// i identifier
// n number
// d droped ie (){} which ast dose not need
// c condition
// s symbol

std::string tokens(std::string word) {
  std::string Token;
  if (word == "+") {
    return "sPLUS";
  } else if (word == "-") {
    return "sMINUS";
  } else if (word == "*") {
    return "sTIMES";
  } else if (word == "/") {
    return "sSLASH";
  } else if (word == "(") {
    return "dLPAREN";
  } else if (word == ")") {
    return "dRPAREN";
  } else if (word == "{") {
    return "dLCURLY";
  } else if (word == "}") {
    return "dRCURLY";
  } else if (word == ";") {
    return "dSEMICOLON";
  } else if (word == ",") {
    return "dCOMMA";
  } else if (word == ".") {
    return "sPERIOD";
  } else if (word == "=") {
    return "cEQL";
  } else if (word == "!=") {
    return "cNQL";
  } else if (word == "<") {
    return "cLSS";
  } else if (word == ">") {
    return "cGTR";
  } else if (word == "<=") {
    return "cLEQ";
  } else if (word == ">=") {
    return "cGEQ";
  } else if (word == "const") {
    return "sCONSTSYM";
  } else if (word == "if") {
    return "sIFSYM";
  } else if (word == "then") {
    return "sTHENSYM";
  } else if (word == "var") {
    return "sVARSYM";
  } else if (word == "while") {
    return "sWHILESYM";
  } else {
    bool isNum = false;    // number
    std::string returnVal; // return varible
    if ((word.at(0) >= 59 && word.at(0) <= 90) ||
        (word.at(0) >= 97 && word.at(0) <= 122)) { // checks that a-zA-Z
      returnVal += 'n';
      returnVal += word.at(0);
    } else if (word.at(0) >= 48 && word.at(0) <= 63) { // checks that 0-9
      isNum = true;
      returnVal += 'i';
      returnVal += word.at(0);
    } else { // returns failed varible
      std::cout << "unkown character " << word.at(0);
      return "UNKNOWN";
    }
    if (word.length() > 0) { // checks that string is not empty
      for (int i = 1; i < word.length(); i++) {
        if ((word.at(i) >= 59 && word.at(i) <= 90) ||
            (word.at(i) >= 97 && word.at(i) <= 122) && isNum == false) {
          returnVal += word.at(i);
        } else if (word.at(0) >= 48 && word.at(0) <= 63) {
          returnVal += word.at(i);
        } else {
          std::cout << "unkown character " << word.at(i);
          return "UNKNOWN";
        }
      }
    }
  }
  return word;
}

std::vector<std::string> lex(std::string src) {
  std::string word;
  std::vector<std::string> lexed;
  for (int x = 0; x < src.length(); x++) {
    if (src.at(x) == ' ' || src.at(x) == '\n' || src.at(x) == '\t') {
      if (word != "") {
        std::string temp = tokens(word);
        if (temp != "UNKNOWN") {
          lexed.push_back(temp);
        } else {
          return {};
        }
        word = "";
      }
    } else if ((src.at(x) < 59 || src.at(x) > 90) &&
               (src.at(x) < 97 || src.at(x) > 122) &&
               (src.at(x) < 48 || src.at(x) > 63)) {
      std::string temp;
      if (word.length() > 0) {
        temp = tokens(word);
        if (temp == "UNKNOWN") {
          return {};
        }
        lexed.push_back(temp);
      }
      word = "";
      temp = "";
      temp += src.at(x);
      temp = tokens(temp);
      if (temp == "UNKNOWN") {
        return {};
      }
      lexed.push_back(temp);
    } else {
      word += src.at(x);
    }
  }
  std::cout << "test";
  return lexed;
}
