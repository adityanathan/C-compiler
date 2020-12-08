#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

struct AST {
    int nodetype; //1 - Non Terminal (Has Children), 0 - Terminal, 3 - List, 4 - empty list (3,4 - list always expands to the left)
    string node_string;
    string value;
    vector<AST*> children;
};

struct identifier_node {
    string symtype; //"func" or "var"
    string name; // identifier name
    int scope_level;

    // for variables ////////////////
    // string type; // not reliable
    // string qualifier; // not reliable
    /////////////////////////////////

    // for funcs ////////////////////
    int num_args;
    // vector<string> func_arg_types;
    // string func_ret_type;
    /////////////////////////////////
};

struct ll_node {
    identifier_node* node;
    ll_node* next=nullptr;
};

AST* createAST(int nodetype, string node_string);
AST* createAST(int nodetype, string node_string, vector<AST*> c);
AST* createAST(int nodetype, string node_string, vector<AST*> c, char* val);

void push(AST* node, vector<AST*> v);
void insert(AST* node, vector<AST*> v);

// void addchild(AST* child);
void freeAST(AST* root);

void printAST(AST* root);

void check_scope( AST* root, unordered_map<string, ll_node*>& symbol_table, int scope_level);

extern AST* ast_root;