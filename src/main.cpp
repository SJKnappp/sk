#include "main.h"

// takes and input from file and can be called recursivly
// error return value 1 too many compiler intrustion input
// 2 can't open file
std::string fileInput(std::string text, std::string file) {

  std::string line;

  // take file input from CL
  std::ifstream src(file);

  if (src.is_open()) {
    while (getline(src, line)) {
      // checks if theres an include statment
      // bool ignore = false;
      std::string include = "include";
      // uses # to note a copiler options
      std::string Flag = "";
      if (line.at(0) == '#') {
        // ignore = true;
        int x = 1;

        std::string Command = "";
        std::string store = "";
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
        std::cout << Flag;
        if (Command == "include") {
          text = fileInput(text, Flag);
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

int main(int argc, char **argv) {
  std::string title;
  if (argc == 1) {
    title = "main.k";
  } else {
    title = argv[1];
  }

  std::string text;
  text = fileInput(text, title);

  std::cout << text;

  return 0;
}