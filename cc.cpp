#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ast.hpp"
#include "c.tab.hpp"
#include <iostream>


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
  // At this point ast_root gives me the AST.
  if (ret==0) printAST(ast_root);

  // Lab 2 Part 2 /////////////////////////////////////
  if(ret==0){
    unordered_map<string, ll_node*> symbol_table;
    check_scope(ast_root, symbol_table, 0);

    // for(auto x: symbol_table){
    //   ll_node* list = x.second;
    //   cout<<x.first<<"\t";
    //   while(list){
    //     cout<<list->node->scope_level<<"\t";
    //     list=list->next;
    //   }
    //   cout<<endl;
    // }
  }

  ////////////////////////////////////////////////////
  printf("retv = %d\n", ret);
  exit(0);
}
