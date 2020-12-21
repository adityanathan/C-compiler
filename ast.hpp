#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>
using namespace std;

#ifndef AST_HPP
#define AST_HPP

struct AST {
    int nodetype; //1 - Non Terminal (Has Children), 0 - Terminal, 3 - List, 4 - empty list (3,4 - list always expands to the left)
    string node_string;
    string value;
    vector<AST*> children;
    AST* parent = nullptr;

    vector<AST*> postfix_cgen; // used only when some special code is needed for postfix increment or decrement.

    bool jump_valid = false; // in case of break and continue determine during scope checking if they have an enveloping loop
};

extern AST* ast_root;

struct identifier_node {
    string symtype; //"func" or "var" or "label" or "func_sig"
    string name; // identifier name
    int scope_level;

    // for variables and funcs ///////////
    string type;
    string ll_type;
    int pointer_level = 0; //number of stars
    bool global_var;
    /////////////////////////////////

    // for funcs only ////////////////////
    vector<identifier_node*> func_args;
    bool variadic = false;
    /////////////////////////////////////

    // Lab 2 Part 3 fields //////////////
    string llvm_name;
    /////////////////////////////////////
};

struct ll_node {
    identifier_node* node;
    ll_node* next=nullptr;
    int list_length = 0;
};

// Lab 2 Part 3 /////////////////////////////////////

extern fstream file;

extern int register_counter;
extern int label_counter;
extern int loop_label_counter;
extern unordered_map<string, pair<string,int>> string_constants; // (register name, string constant)
extern string func_ret_type; //stores return type of current function during codegen. (for return statements). WARNING: assuming nested function defns not allowed

AST* createAST(int nodetype, string node_string);
AST* createAST(int nodetype, string node_string, vector<AST*> c);
AST* createAST(int nodetype, string node_string, vector<AST*> c, char* val);

void push(AST* node, vector<AST*> v);
void insert(AST* node, vector<AST*> v);

// void addchild(AST* child);
void freeAST(AST* root);

void printAST(AST* root);

identifier_node* check_scope( AST* root, unordered_map<string, ll_node*>& symbol_table, int scope_level);

identifier_node* cgen(AST* root, unordered_map<string, ll_node*>& symtable, int scope_level);


#endif