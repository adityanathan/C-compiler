#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
using namespace std;

struct AST {
    int nodetype; //1 - Non Terminal (Has Children), 0 - Terminal, 3 - List, 4 - empty list (3,4 - list always expands to the left)
    string node_string;
    string value;
    vector<AST*> children;
};

struct identifier_node {
    string symtype; //"func" or "var" or "label" or "func_sig"
    string name; // identifier name
    int scope_level;

    // for variables and funcs ////////////////
    string type;
    int pointer_level; //number of stars
    /////////////////////////////////

    // for funcs only ////////////////////
    vector<identifier_node*> func_args;
    bool variadic = false;
    /////////////////////////////////
};

// Lab 2 Part 3 /////////////////////////////////////

extern fstream file;

struct ll_node {
    identifier_node* node;
    ll_node* next=nullptr;
};

struct cgen_node {
    string symtype;
    string name;

    // For variables ////////////////
    pair<string,int> type;
    string value;
    /////////////////////////////////

    // the int in the pair for types is to indicate pointer level.
    // It is supposed to be 0 by default.

    // for funcs ////////////////////
    pair<string,int> func_ret_type;
    vector<pair<string,int>> func_arg_types;
    /////////////////////////////////
};

struct list_node {
    cgen_node* node;
    list_node* next=nullptr;
};

AST* createAST(int nodetype, string node_string);
AST* createAST(int nodetype, string node_string, vector<AST*> c);
AST* createAST(int nodetype, string node_string, vector<AST*> c, char* val);

void push(AST* node, vector<AST*> v);
void insert(AST* node, vector<AST*> v);

// void addchild(AST* child);
void freeAST(AST* root);

void printAST(AST* root);

identifier_node* check_scope( AST* root, unordered_map<string, ll_node*>& symbol_table, int scope_level);

void codegen();

extern AST* ast_root;