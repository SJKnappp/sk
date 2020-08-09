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
  result.state = 0;
  return result;
}

int path(std::string &file, std::string &location) {
  Result result;
  int state = 0;
  int size = file.size();

  if (file == "") {
    state = 1; // no file input
  }

  std::string localPath;
  std::string tempPath;
  for (int i = 0; i < size; i++) {

    switch (file.at(i)) {
    case '/':
      tempPath += '/';
      localPath += tempPath;
      tempPath = "";
      break;
    case '.':
      if (file.at(i + 1) == '.' && file.at(i + 2) == '/') {
        i += 3;
        if (localPath == "") {
          result = removePath(location);
          if (result.state == 0) {
            location = result.text;
          } else {
            return 10;
          }
        }
      }
    default:
      tempPath += file.at(i);
      if (i == size - 1) {
        file = tempPath;
        location += localPath;
      }
      break;
    };
  }

  return state;
}

// recursive function text used to store the text
Result fileInput(std::string text, std::string file, std::string location) {

  Result result;
  int collect;
  std::string relativeLocation = "";

  collect = path(file, location);
  if (collect == 0) {
    file = location + file;
  } else {
  }

  std::string line;

  // take file input from CL
  std::ifstream src(file);

  if (src.is_open()) {
    result.state = 0;
    while (getline(src, line)) {
      // only puts new line if last line is not empty
      if ('\n' != text.back() && !text.empty()) {
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
          Result collect = fileInput(text, Flag, location);
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
    result.state = 10; // unable to open file
    std::cout << "Unable to open file";
    return result; // error cannot open the file
  }

  result.text = text;
  return result;
}