#include "lexer.h"

std::string tokens(std::string word) {
  std::string Token;
  std::string returnVal = ""; // return varible for num and identifer
  if (word == "+") {
    return "PLUS";
  } else if (word == "-") {
    return "MINUS";
  } else if (word == "*") {
    return "TIMES";
  } else if (word == "/") {
    return "SLASH";
  } else if (word == "(") {
    return "LPAREN";
  } else if (word == ")") {
    return "RPAREN";
  } else if (word == "{") {
    return "LCURLY";
  } else if (word == "}") {
    return "RCURLY";
  } else if (word == ";") {
    return "SEMICOLON";
  } else if (word == ".") {
    return "PERIOD";
  } else if (word == "=") {
    return "EQL";
  } else if (word == "==") {
    return "COM";
  } else if (word == "!=") {
    return "NQL";
  } else if (word == "<") {
    return "LSS";
  } else if (word == ">") {
    return "GTR";
  } else if (word == "<=") {
    return "LEQ";
  } else if (word == ">=") {
    return "GEQ";
  } else if (word == "const") {
    return "CONSTSYM";
  } else if (word == "if") {
    return "IFSYM";
  } else if (word == "while") {
    return "WHILESYM";
  } else if (word == "int") {
    return "INTSYM";
  } else if (word == "void") {
    return "VOIDSYM";
  } else if (word == "return") {
    return "RETURNSYM";
  } else {
    bool isNum = false; // number

    // 65-90 A-Z
    // 97-122 a-z
    // 48-57 0-9

    if ((word.at(0) >= 65 && word.at(0) <= 90) ||
        (word.at(0) >= 97 && word.at(0) <= 122)) { // checks that a-zA-Z
      returnVal += 'i';
      returnVal += word.at(0);
    } else if (word.at(0) >= 48 && word.at(0) <= 57) { // checks that 0-9
      isNum = true;
      returnVal += 'n';
      returnVal += word.at(0);
    } else { // returns failed varible
      std::cout << "unkown character " << word.at(0);
      return "UNKNOWN";
    }
    if (word.length() > 0) { // checks that string is not empty
      for (int i = 1; i < word.length(); i++) {
        int a = word.at(i);
        char b = word.at(i);
        if ((word.at(i) >= 65 && word.at(i) <= 90) ||
            (word.at(i) >= 97 && word.at(i) <= 122) && isNum == false) {
          returnVal += word.at(i);
        } else if (word.at(0) >= 48 && word.at(0) <= 57) {
          returnVal += word.at(i);
        } else {
          std::cout << "unkown character " << word.at(i);
          return "UNKNOWN";
        }
      }
    }
  }
  return returnVal;
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
    } else if ((src.at(x) < 65 || src.at(x) > 90) &&
               (src.at(x) < 97 || src.at(x) > 122) &&
               (src.at(x) < 48 || src.at(x) > 57)) {
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
  return lexed;
}
