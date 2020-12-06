#include <string>
#include <vector>
using namespace std;

struct AST {
    int nodetype; //1 - Non Terminal (Has Children), 0 - Terminal, 3 - List, 4 - empty list
    string node_string;
    string value;
    vector<AST*> children;
};

AST* createAST(int nodetype, string node_string);
AST* createAST(int nodetype, string node_string, vector<AST*> c);
AST* createAST(int nodetype, string node_string, vector<AST*> c, char* val);

void push(AST* node, vector<AST*> v);
void insert(AST* node, vector<AST*> v);

// void addchild(AST* child);
void freeAST(AST* root);

void printAST(AST* root);

extern AST* ast_root;