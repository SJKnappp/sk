#include "include.h"

// takes an item off the path
Result removePath(std::string location) {
  Result result;
  if (location == "") {
    result.text = "../";
    result.state = 0;
    return result;
  }

  std::string hold;
  for (int i = 0; i < location.size(); i++) {
    if (location.at(i) == '/') {
      if (i == location.size() - 1) {
        break;
      } else {
        hold += "/";
        result.text += hold;
        hold = "";
      }
    } else if (i == location.size() - 1) {
      result.state = 1;
      return result; // not termated by /
    } else {
      hold += location.at(i);
    }
  }
  return result;
}

Result path(std::string text, std::string location) {
  Result result;

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
          result = removePath(location);
          if (result.state == 0) {
            location = result.text;
          } else {
            result.text = location;
            result.state = 10; // error code for failed removePath function
            return result;
          }
        }
      }
      break;
    default:
      break;
    };
  }

  return result;
}

// recursive function text used to store the text
Result fileInput(std::string text, std::string &file, std::string location) {

  Result result;
  Result collect;
  std::string relativeLocation = "";

  collect = path(text, location);

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

                result.text = location;
                result.state = 1; // error value too many complier flag input
                return result;
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
          Result collect = fileInput(text, Flag, "");
          if (collect.state == 0) {
            text += collect.text;
          } else {
            return collect;
          }
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
    return result; // error cannot open the file
  }

  return result;
}