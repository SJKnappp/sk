#include "lexer.h"

std::string tokens(std::string word) {
  std::string Token;
  std::string returnVal = ""; // return variable for num and identifier
  if (word.size() == 0) {
    return "EMPTYFLAG";
  } else if (word == "+") {
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
  } else if (word == "++") {
    return "INC";
  } else if (word == "--") {
    return "DEC";
  } else if (word == "{") {
    return "LCURLY";
  } else if (word == "}") {
    return "RCURLY";
  } else if (word == ";") {
    return "SEMICOLON";
  } else if (word == ".") {
    return "PERIOD";
  } else if (word == ",") {
    return "COMMA";
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
        } else if (word.at(i) >= 48 && word.at(i) <= 57) {
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
  std::string temp;
  bool isIdent = false;
  std::vector<std::string> lexed;

  for (int i = 0; i < src.size(); i++) {

    if ((src.at(i) < 65 || src.at(i) > 90) &&
        (src.at(i) < 97 || src.at(i) > 122) &&
        (src.at(i) < 48 || src.at(i) > 57)) {
      if (src.at(i) == ' ' || src.at(i) == '\n' || src.at(i) == '\t') {

        if (temp != "") {
          std::string result = tokens(temp);
          if (temp != "UNKNOWN") {
            lexed.push_back(result);
            temp = "";
          } else {
            return {};
          }
          temp = "";

          isIdent = false;
        }
        continue;
      }

      if (isIdent == true) {
        isIdent = false;

        std::string result = tokens(temp);
        if (temp != "UNKNOWN") {
          lexed.push_back(result);
          temp = "";
        } else {
          return {};
        }
      }

      temp += src.at(i);

      if (src.at(i) == '=' || src.at(i) == '!' || src.at(i) == '<' ||
          src.at(i) == '>') {
        if (i != src.size() - 1) {
          if (src.at(i + 1) == '=') {
            i += 1;
            temp += src.at(i);
          }
        }
      }

      std::string result = tokens(temp);
      lexed.push_back(result);
      if (result != "UNKOWN") {
        temp = "";
      } else {
        return lexed;
      }
    } else {
      isIdent = true;
      temp += src.at(i);

      if (i == src.size() - 1) {
        std::string result = tokens(temp);
        lexed.push_back(result);
        if (result != "UNKOWN") {
          temp = "";
        } else {
          return lexed;
        }
      }
    }
  }
  return lexed;
}
