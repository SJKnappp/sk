#include "main.h"

// takes and input from file and can be called recursivly
std::string fileInput(std::string text, std::string file) {

  std::string line;

  // take file input from CL
  std::ifstream src(file);

  if (src.is_open()) {
    while (getline(src, line)) {
      // checks if theres an include statment
      bool ignore = false;
      std::string include = "include";
      for (int x = 0; x < include.length(); x++) {
        if (line.at(x) == include.at(x)) {
        } else {
          break;
        }
        if (x == include.length() - 1) {
          ignore = true;
        }
      }

      // checks to add line to string
      if (ignore == false) {
        text.append(line);
      } else {
        std::cout << "placeholder";
        // text = fileInput(text, file);
      }
    }
    src.close();
  } else {
    std::cout << "Unable to open file";
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