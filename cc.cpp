#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ast.hpp"
#include "c.tab.hpp"


extern "C" int yylex();
int yyparse();
extern "C" FILE *yyin;

static void usage()
{
  printf("Usage: cc <prog.c>\n");
}

int
main(int argc, char **argv)
{
  if (argc != 2) {
    usage();
    exit(1);
  }
  char const *filename = argv[1];
  yyin = fopen(filename, "r");
  assert(yyin);
  int ret = yyparse();

  if (ret==0) printAST(ast_root);

  printf("retv = %d\n", ret);
  exit(0);
}
