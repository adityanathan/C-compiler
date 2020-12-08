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

vector<AST*> getList(AST* node){
    if (node->nodetype == 3) {
        vector<AST*> v = getList(node->children[0]);
        v.push_back(node->children[1]);
        return v;
    } 
    else {
        return {node};
    }
}

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
    if(symbol_table.find(node->name)==symbol_table.end()) {
        symbol_table.insert(make_pair(node->name, createNode(node)));
        return;
    } else if (symbol_table[node->name]->node == nullptr) {
        sym_insert(symbol_table, node);
        return;
    }
    else if (symbol_table[node->name]->node->scope_level != node->scope_level) {
        sym_insert(symbol_table, node);
        return;
    }

    // inserting in same scope level
    if(node->symtype=="func") {
        // ll_node* list = symbol_table[node->name];
        // vector<string> mynode_args = node->func_arg_types;
        // while(list){
        //     vector<string> node2_args = (list->node)->func_arg_types;
        //     if(mynode_args.size()==node2_args.size()){
        //         int count = 0;
        //         for(int i=0; i<node2_args.size(); i++){
        //             if(mynode_args[i]==node2_args[i]) count++;
        //         }
        //         if (count==node2_args.size()){
        //             cout<<"Error: Multiple functions of name "<<node->name<<" with same signatures defined"<<endl;
        //             break;
        //         }
        //     }
        // }
        cout<<"Error: Multiple functions of name "<<node->name<<" defined"<<endl;
    }
    // You can never insert var at same scope level
    else if (node->symtype=="var"){
        cout<<"Error: Multiple variables with same name "<<node->name<<" declared in same scope"<<endl;
    }
    return;
}

void scope_exit(unordered_map<string, ll_node*>& symbol_table, int level_to_be_removed){

}

void iterate_children(AST* root, unordered_map<string, ll_node*>& symbol_table, int scope_level){
    for(auto x: root->children) {
        check_scope(x, symbol_table, scope_level);
    }
}

void check_scope(AST* root, unordered_map<string, ll_node*>& symbol_table, int scope_level) {
    if(root->node_string=="FUNC"){
        if(root->children.size()==3){
            // Add new node in symtable for function identifier
            identifier_node* newnode = new identifier_node;

            newnode->symtype = "func";

            // Assuming only one return type
            newnode->func_ret_type = (root->children[0])->node_string; //return type

            vector<AST*> param_list;
            // func_arg_types and name
            AST* temp = root->children[1];
            if(temp->node_string == "direct_declarator") {
                newnode->name = temp->children[0]->value;
                param_list = getList(temp->children[1]);

                for(auto x: param_list) {
                    newnode->func_arg_types.push_back((x->children[0])->node_string);
                }
            } else {
                newnode->name = temp->value;
                // func_arg_types is empty
            }

            newnode->scope_level = scope_level;

            // symbol_table[newnode->name] = newnode;
            add_to_symtable(symbol_table, newnode);

            // add new node in symtable for function parameters
            if(!param_list.empty()) {
                for(auto x: param_list) {
                    // identifier_node* var = new identifier_node;
                    // auto temp2 = x->children;
                    // var->symtype = "var";
                    // var->name = temp2[1]->value;
                    // var->type = temp2[0]->node_string;
                    // var->scope_level = scope_level + 1;

                    // add_to_symtable(symbol_table, var);

                    check_scope(x, symbol_table, scope_level+1);
                }
            }
            
            check_scope(root->children[2], symbol_table, scope_level);
            // scope_exit(symbol_table, scope_level);
        }
        else {
            cout<<"Function syntax error: Function can have only one type, one name and one body."<<endl;
        }
    }
    else if (root->node_string=="parameter_declaration") {
        // Not exited on scope exit. Need to be deleted on compound block exit
        // First child = declaration specifer. 
        // Second child = declarator which could be pointer direct_declarator or direct_declarator. 
        // direct_declarator always = ID.
        if(root->children.size()==1) {
            // Just declaration specifiers and no point in recursing so exit.
            return;
        }
        else if (root->children.size()==2) {
            identifier_node* var = new identifier_node;
            var->symtype = "var";

            AST* types = root->children[0];
            var->type = types->node_string;

            AST* id = root->children[1];
            if (id->children.empty()) var->name = id->value;
            else if (id->children.size() == 2){
                var->name = id->children[1]->value;
            }

            var->scope_level = scope_level;

            add_to_symtable(symbol_table, var);
            
            // if (types->children.empty()) {
            //     var->type = types->node_string;
            // }
            // else if (types->children.size()==2) {
            //     for (auto x: types->children){
            //         string temp = x->node_string;
            //         if()
            //     }
            // }

        }

    }
    else if (root->node_string=="compound statement") {
        // Increase scope
        // for(auto x: root->children) {
        //     check_scope(x, symbol_table, scope_level+1);
        // }
        iterate_children(root, symbol_table, scope_level+1);
    }
    else {
        // for(auto x: root->children) {
        //     check_scope(x, symbol_table, scope_level);
        // }
        iterate_children(root, symbol_table, scope_level);
    }
    
}