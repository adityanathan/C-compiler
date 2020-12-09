#include "ast.hpp"
#include <iostream>

AST* createAST(int nodetype, string node_string){
    AST* newast = new AST;
    newast->nodetype = nodetype;
    newast->node_string = node_string;
    return newast;
}

AST* createAST(int nodetype, string node_string, vector<AST*> c){
    AST* newast = new AST;
    newast->nodetype = nodetype;
    newast->node_string = node_string;
    for(auto x: c){
        newast->children.push_back(x);
    }
    return newast;
}

AST* createAST(int nodetype, string node_string, vector<AST*> c, char* val){
    AST* newast = new AST;
    newast->nodetype = nodetype;
    newast->node_string = node_string;
    for(auto x: c){
        newast->children.push_back(x);
    }
    string v(val);
    newast->value = v;
    return newast;
}

void push(AST* node, vector<AST*> v){
    for(auto x: v){
        node->children.push_back(x);
    }
}

void insert(AST* node, vector<AST*> v){
    for(auto it = v.rbegin(); it!=v.rend(); it++){
        node->children.insert(node->children.begin(), *it);
    }
}

void freeAST(AST* root){
    for(auto a: root-> children){
        freeAST(a);
    }
    delete(root);
}

void printAST_helper(AST* root, int height){
    // if(root->nodetype!=3){
        for(int i=0; i<height; i++){
            cout<<"\t";
        }
        cout<<"|-  ";

        if(root->nodetype==0 && !root->value.empty()){
            cout<<root->node_string<<"( "<<root->value<<" )"<<endl;
        } else {
            cout<<root->node_string<<endl;
        }
    // }
    for(auto x: root->children){
        printAST_helper(x, height+1);
    }
}

void printAST(AST* root){
    printAST_helper(root, 0);
}

// Lab 2 Part 2 /////////////////////////////////////////////////////////////////////////


ll_node* createNode(identifier_node* node){
    ll_node* newnode = new ll_node;
    newnode->node = node;
    return newnode;
}

void sym_insert(unordered_map<string, ll_node*>& symbol_table, identifier_node* node){
    ll_node* newnode = createNode(node);
    newnode->next = symbol_table[node->name];
    symbol_table[node->name] = newnode;
    return;
}

void add_to_symtable(unordered_map<string, ll_node*>& symbol_table, identifier_node* node){
    // cout<<endl<<"trying to add "<<node->name<<"\t"<<node->scope_level<<"\t"<<node->type<<" "<<node->pointer_level<<endl;
    if(symbol_table.find(node->name)==symbol_table.end()) {
        symbol_table.insert(make_pair(node->name, createNode(node)));
        return;
    } else if (symbol_table[node->name] == nullptr) {
        sym_insert(symbol_table, node);
        return;
    }
    else if (symbol_table[node->name]->node->scope_level != node->scope_level) {
        sym_insert(symbol_table, node);
        return;
    }

    // You can never insert var,func at same scope level
    if(node->symtype=="func") {
        cout<<"Error: Multiple functions of name '"<<node->name<<"' defined"<<endl;
    }
    else if (node->symtype=="var"){
        cout<<"Error: Multiple variables with same name '"<<node->name<<"' declared in same scope"<<endl;
    }
    return;
}

void scope_exit(unordered_map<string, ll_node*>& symbol_table, int level_to_be_removed) {
    // cout<<endl<<level_to_be_removed<<endl;
    for (auto x: symbol_table) {
        if(x.second != nullptr){
            ll_node* temp = x.second;
            if(temp->node->scope_level == level_to_be_removed) {
                symbol_table[x.first] = temp->next;
                // cout<<endl<<"removing "<<x.first<<" "<<x.second->node->scope_level<<endl;
            }
        }
    }
}

string get_type(AST* node){
    // only for "type" and "pointer"
    string s;
    if(node->children.size() == 0){
        throw string("No return type given for function declaration");
    }
    if(node->children.size() == 1){
        s = node->children[0]->node_string;
    }
    else {
        s = node->children[0]->node_string;
        for(int i=1; i<node->children.size(); i++){
            s = s + ' ' + node->children[i]->node_string;
        }   
    }
    return s;
}

// Precondition: Input node must have node_string == "declarator"
identifier_node* process_declarator_node(AST* root, string type, unordered_map<string, ll_node*>& symbol_table, int scope_level){
    identifier_node* newnode = new identifier_node;
    newnode->pointer_level = root->children[0]->children.size();
    newnode->scope_level = scope_level;
    newnode->type = type;

    AST* direct_declarator_node = root->children[1];
    // direct_declarator could be a var or a func
    if(direct_declarator_node->node_string=="ID"){
        newnode->symtype="var";
        newnode->name=direct_declarator_node->value;
    }
    else if (direct_declarator_node->node_string=="fn_declaration"){
        newnode->symtype="func";
        AST* fn_decl = direct_declarator_node;
        newnode->name=fn_decl->children[0]->value;
        for(auto x: fn_decl->children[1]->children) {
            identifier_node* param = check_scope(x, symbol_table, scope_level+1);
            newnode->func_args.push_back(param);
        }
    }
    return newnode;
}

identifier_node* check_scope(AST* root, unordered_map<string, ll_node*>& symbol_table, int scope_level) {
    if(root->node_string=="FUNC"){
        // cout<<"a";
        // // invariant for func - first child = type, second child = declarator, third_child = compound_statement
        string type = get_type(root->children[0]);
        identifier_node* newnode = process_declarator_node(root->children[1], type, symbol_table, scope_level);

        add_to_symtable(symbol_table, newnode);

        check_scope(root->children[2], symbol_table, scope_level);
        return nullptr;
    }
    else if (root->node_string == "parameter_declaration") {
        // cout<<"b1 ";
        identifier_node* newnode = new identifier_node;
        newnode->symtype = "var";
        newnode->type = get_type(root->children[0]);
        AST* declarator_node = root->children[1];
        newnode->pointer_level = declarator_node->children[0]->children.size();
        newnode->name = declarator_node->children[1]->value;
        newnode->scope_level = scope_level;
        add_to_symtable(symbol_table, newnode);
        return newnode;
    }
    else if (root->node_string == "declaration") {
        // cout<<"b2 ";
        string type = get_type(root->children[0]);
        AST* init_declarator = root->children[1];
        for(auto x: init_declarator->children) {
            identifier_node* newnode;
            if(x->node_string=="="){
                newnode = process_declarator_node(x->children[0], type, symbol_table, scope_level);
            }
            else{
                newnode = process_declarator_node(x, type, symbol_table, scope_level);
                if(newnode->symtype == "func"){
                    scope_exit(symbol_table, scope_level+1); // To remove the function args from scope. Since it has no compound statement
                }   
            }
            add_to_symtable(symbol_table, newnode); 
        }
        return nullptr;
    }

    else if (root->node_string=="labeled_statement") {
        // cout<<"c";
        identifier_node* newnode = new identifier_node;
        newnode->symtype = "label";
        newnode->name = root->children[0]->value;
        newnode->scope_level = scope_level;
        add_to_symtable(symbol_table, newnode);

        check_scope(root->children[1], symbol_table, scope_level);
        return nullptr;
    }
    else if (root->node_string=="ID") {
        // cout<<"d";
        if(symbol_table.find(root->value)==symbol_table.end() || symbol_table[root->value]==nullptr){
            cout<<"Scope Error: Undefined - "<<root->value<<endl;
        }
        return nullptr;
    }
    else if (root->node_string=="compound_statement") {
        for(auto x: root->children) {
            check_scope(x, symbol_table, scope_level+1);
        }
        scope_exit(symbol_table, scope_level+1);
        return nullptr;
    }
    else {
        // cout<<"i";
        for(auto x: root->children) {
            check_scope(x, symbol_table, scope_level);
        }
        return nullptr;
    }
}

/////////////////////////////// Lab 2 Part 3 ////////////////////////////////

void codegen(AST* root, unordered_map<string, list_node*>& symtable, int scope_level) {
    
}

void evaluate(AST* root, unordered_map<string, list_node*>& symtable, int scope_level) {

}