#include "lexer.h"

std::string tokens(std::string word) {
  std::string Token;
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
  } else if (word == ";") {
    return "SEMICOLON";
  } else if (word == ",") {
    return "COMMA";
  } else if (word == ".") {
    return "PERIOD";
  } else if (word == ":=") {
    return "BECOMES";
  } else if (word == "=") {
    return "EQL";
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
  } else if (word == "begin") {
    return "BEGINSYM";
  } else if (word == "call") {
    return "CALLSYM";
  } else if (word == "const") {
    return "CONSTSYM";
  } else if (word == "do") {
    return "DOSYM";
  } else if (word == "end") {
    return "ENDSYM";
  } else if (word == "if") {
    return "IFSYM";
  } else if (word == "odd") {
    return "ODDSYM";
  } else if (word == "procedure") {
    return "PROCSYM";
  } else if (word == "then") {
    return "THENSYM";
  } else if (word == "var") {
    return "VARSYM";
  } else if (word == "while") {
    return "WHILESYM";
  } else {
    bool isIdt = false; // identifer
    bool isNum = false; // number
    std::string returnVal;
    if ((word.at(0) >= 59 && word.at(0) <= 90) ||
        (word.at(0) >= 97 && word.at(0) <= 122)) {
      isIdt = true;
      returnVal += word.at(0);
    } else if (word.at(0) >= 48 && word.at(0) <= 63) {
      isNum = true;
      returnVal += word.at(0);
    } else {
      std::cout << "unkown character " << word.at(0);
      return "UNKNOWN";
    }
    if (word.length() > 0) {
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
    if (src.at(x) == ' ' || src.at(x) == '\n') {
      if (word != "") {
        std::string temp = tokens(word);
        if (temp != "UNKNOWN") {
          lexed.push_back(temp);
        } else {
          return {};
        }
        word = "";
      }
    } else {
      word += src.at(x);
    }
  }

  return lexed;
}
