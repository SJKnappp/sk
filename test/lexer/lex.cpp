//
// Created by knapp on 07/08/2020.
//

#include "lex.h"

TEST_CASE("lex pass list of strings containing mathematical symbols") {
  std::vector<std::string> a = lex("+ - * / ( )");
  std::string store;
  for (int i = 0; i < a.size(); i++)
    store += a.at(i) + " ";
  REQUIRE(store == "PLUS MINUS TIMES SLASH LPAREN RPAREN ");
}

TEST_CASE("lex pass list of strings containing example if") {
  std::vector<std::string> a = lex("if(a < b){ a + b}");
  std::string store;
  for (int i = 0; i < a.size(); i++)
    store += a.at(i) + " ";
  REQUIRE(store == "IFSYM LPAREN ia LSS ib RPAREN LCURLY ia PLUS ib RCURLY ");
}

TEST_CASE("lex pass list of strings containing while loop") {
  std::vector<std::string> a = lex("while(a == 0){a++}");
  std::string store;
  for (int i = 0; i < a.size(); i++)
    store += a.at(i) + " ";
  REQUIRE(store ==
          "WHILESYM LPAREN ia COM n0 RPAREN LCURLY ia PLUS PLUS RCURLY ");
}

TEST_CASE("lex past list of equals types") {
  std::vector<std::string> a = lex("= == != <= >= < >");
  std::string store;
  for (int i = 0; i < a.size(); i++)
    store += a.at(i) + " ";
  REQUIRE(store == "EQL COM NQL LSS GTR LEQ GEQ ");
}

TEST_CASE("lex pass list of strings containing all symbols") {
  std::vector<std::string> a = lex(
      "+ - * / ( ) { } ; . = == != < > <= >= const if while int void return");
  std::string store;
  for (int i = 0; i < a.size(); i++)
    store += a.at(i) + " ";
  REQUIRE(store == "PLUS MINUS TIMES SLASH LPAREN RPAREN LCURLY RCURLY "
                   "SEMICOLON PERIOD EQL COM NQL LSS GTR LEQ GEQ CONSTSYM "
                   "IFSYM WHILE SYM INTSYM VOIDSYM RETURNSYM");
}

TEST_CASE("lex pass list of strings containing all symbols without spaces") {
  std::vector<std::string> a =
      lex("+-*/(){};.=1==1!=1<1>1<=1>=1 const if while int void return");
  std::string store;
  for (int i = 0; i < a.size(); i++)
    store += a.at(i) + " ";
  REQUIRE(store ==
          "PLUS MINUS TIMES SLASH LPAREN RPAREN LCURLY RCURLY "
          "SEMICOLON PERIOD EQL n1 COM n1 NQL n1 LSS n1 GTR n1 "
          "LEQ n1 GEQ n1 CONSTSYM IFSYM WHILESYM INTSYM VOIDSYM RETURNSYM ");
}
