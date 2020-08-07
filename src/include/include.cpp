#include "include.h"

// takes an item off the path
std::string removePath(std::string location) {
  std::string result;
  if (location == "")
    return "../";

  for (int i = 0; i < location.size(); i++) {
    if (location.at(i)) {
    }
  }
  return result
}

// recursive function text used to store the text
std::string fileInput(std::string text, const std::string &file,
                      std::string location) {

  std::string relativeLocation = "";
  for (int i = 0; i < text.size(); i++) {
    std::string localPath;
    std::string tempPath;
    switch (text.at(i)) {
    case '/':
      localPath += tempPath;
      tempPath = "";
      break;
    case '.':
      if (text.at(i + 1) == '.' && text.at(i + 2) == '/') {
        if (localPath == "") {
          location = removePath(location);
        }
      }
      break;
    default:
      break;
    };
  }

  std::string line;

  // take file input from CL
  std::ifstream src(file);

  if (src.is_open()) {
    while (getline(src, line)) {
      // only puts new line if last line is not empty
      if ('\n' != text.back()) {
        // adds new line
        text += '\n';
      }
      if (line.length() == 0) {
        continue;
      }
      // checks if theres an include statment
      // bool ignore = false;
      std::string include = "include";
      // uses # to note a copiler options
      std::string Flag;
      if (line.at(0) == '#') {
        // ignore = true;
        int x = 1;

        std::string Command;
        std::string store;
        bool running = true;
        while (running == true) {
          bool isSpace = false;
          store = "";
          while (isSpace == false) {
            if (line.at(x) == ' ' || line.at(x) == '"' ||
                x == line.length() - 1) {
              isSpace = true;
              if (Command == "" && Flag == "") {
                Command = store;
              } else if (Flag == "") {
                Flag = store;
              } else {
                return "1"; // error value too many complier flag input
              }
            } else {
              if (line.at(x) != ' ' && line.at(x) != '"') {
                store += line.at(x);
              }
            }
            x++;
            if (x == line.length() - 1) {
              running = false;
            }
          }
        }

        if (Command == "include") {
          std::string temp = fileInput(text, Flag, "");
          text += temp;
        } else {
          std::cout << "Compiler flag not recognise";
        }

      } else {
        text.append(line);
      }
    }
    src.close();
  } else {
    std::cout << "Unable to open file";
    return "2"; // error cannot open the file
  }
  src.close();
  return text;
}