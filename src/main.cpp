#include "main.h"

int main(int argc, char **argv) {
  std::string title;
  if (argc == 1) {
    title = "main.k";
  } else {
    title = argv[1];
  }

  std::string text;
  text = fileInput(text, title);

  std::vector<std::string> lexed = lex(text);
  branch start(nullptr, true);
  //  sort(lexed);
  build(&lexed, &start, true);

  //  std::cout << text;

  return 0;
}