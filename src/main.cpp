#include "main.h"

int main(int argc, char **argv) {

  std::string title;
  if (argc == 1) {
    title = "main.k";
  } else {
    title = argv[1];
  }

  // TODO implement checks on the returned text values
  Result text;
  text = fileInput(text.text, title, "");

  std::vector<std::string> lexed = lex(text.text);
  if (lexed.size() == 0) {
    std::cout << "produced empty lexed file";
    return 100;
  } else {
    std::vector<std::string> lexcopy = lexed;
  }
  std::vector<std::vector<symbolTable>> symbol;

  // start ast tree
  branch start(&lexed, symbol, 0, true);
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

  std::string ass = ass::gen(&start);

  std::ofstream file;
  file.open("asm.asm");
  file << ass;
  file.close();

  //  outputAST(start);

  //  std::cout << text;

  system("nasm -f elf asm.asm -o asm.o");
  system("ld -m elf_i386 -s -o asm asm.o");

  return 0;
}