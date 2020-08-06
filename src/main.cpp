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
  std::vector<std::string> lexcopy = lexed;
  std::vector<symbolTable> symbol;

  //
  branch start(nullptr, &symbol, &lexed, true);
  bool isDisplay = true;

  if (isDisplay == true) {
    std::string text;
    start.display(&text, std::string(), true);
  }
  //  std::unique_ptr<Node> ret = std::make_unique<branch>(start);
  //  std::string test = start.branches()[0]->data;
  if (start.failed == true) {
    return 1;
  }

  std::string ass = ass::gen();

  //  outputAST(start);

  //  std::cout << text;

  return 0;
}