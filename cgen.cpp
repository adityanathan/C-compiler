#include "ast.hpp"
#include <iostream>

l_node* createNode(identifier_node* node){
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

identifier_node* cgen_declarator_node(AST* root, string type, unordered_map<string, ll_node*>& symbol_table, int scope_level){
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
        cout<<"a"<<endl;
        for(auto x: fn_decl->children[1]->children) {
            if(x->node_string == "ELLIPSIS") {newnode->variadic = true; continue;}
            identifier_node* param = check_scope(x, symbol_table, scope_level+1);
            cout<<param->name<<endl;
            newnode->func_args.push_back(param);
        }
    }
    return newnode;
}

identifier_node* cgen(AST* root, unordered_map<string, ll_node*>& symtable, int scope_level) {
    if(root->node_string=="FUNC"){
        stringstream ss;
        string type = get_type(root->children[0]);
        identifier_node* newnode = cgen_declarator_node(root->children[1], type, symtable, scope_level);
        ss<<"define "<<type<<" @"<<newnode->name<<"(";
        for(auto x: newnode->func_args){
            ss<<x->type<<" %"<<x->name<<",";
        }
        string temp = ss.str(); temp.pop_back();
        ss<<temp<<") { \n entry: \n";
        file<<ss.str()<<endl;

        add_to_symtable(symtable, newnode);

        cgen(root->children[2], symtable, scope_level);
        if(type == "VOID"){
            file<<"ret void"<<endl;
            file<<"}"<<endl;
        }
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
        add_to_symtable(symtable, newnode);
        return newnode;
    }
    else {
        for(auto x: root->children) {
            cgen(x, symtable, scope_level);
        }
        return nullptr;
    }
}

void evaluate(AST* root, unordered_map<string, ll_node*>& symtable, int scope_level) {

}