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