#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>
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

    // for variables and funcs ///////////
    string type;
    int pointer_level; //number of stars
    /////////////////////////////////

    // for funcs only ////////////////////
    vector<identifier_node*> func_args;
    bool variadic = false;
    /////////////////////////////////////
    
};

struct ll_node {
    identifier_node* node;
    ll_node* next=nullptr;
};

extern fstream file;

extern int register_counter;


identifier_node* cgen(AST* root, unordered_map<string, ll_node*>& symtable, int scope_level);