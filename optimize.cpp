#include "optimize.hpp"

using namespace std;

unordered_map<string, sll_node*> sym_table;

void var_substitution(AST* root, int scope_level);

void constant_folding(AST* root);

void dead_code_removal(AST* root);

void prune_tree(AST* root);

void optimize(AST* root) {
    prune_tree(root);
    // var_substitution(root, 0);
    constant_folding(root);
    dead_code_removal(root);
}

// Prune Tree /////////////////////////////////////////////////////

void alter_postfix(AST* root) {
    if(root->node_string=="postfix_expression"){
        AST* runner = root;
        while(runner->node_string!="expression") runner = runner->parent;
        
        AST* temp = createAST(1, "unary_expression", {root->children[1], root->children[0]});
        runner->postfix_cgen.push_back(temp);
    }
}

void prune_tree(AST* root) {
    alter_postfix(root);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

///// optimizations /////////////////////////////////////////////////////////////////////////////////////


//////////////////// constant folding ///////////////////////////////////////////////////////////

AST* create_from_val(val* node){
    // cout<<"enter"<<endl;
    if(node->valid){
        AST* temp = new AST;
        if(node->type == INTV){
            temp = createAST(0, "I_CONSTANT", {});
            temp->value = to_string(node->ival);
            // cout<<to_string(node->ival)<<endl;
        } else if (node->type == FLOATV) {
            temp = createAST(0, "F_CONSTANT", {});
            temp->value = to_string(node->fval);
            // cout<<to_string(node->fval)<<endl;
        } else {
            temp = createAST(0, "BOOL", {});
            if(node->bval) temp->value = "TRUE";
            else temp->value = "FALSE";
            // cout<<to_string(node->bval)<<endl;
        }
        // cout<<"exit"<<endl;
        return temp;
    }
    // cout<<"opt_failed"<<endl;
    return createAST(0, "OPT_FAILED", {});
}

val* create_dummy(){
    val* temp = new val;
    temp->valid = false;
    return temp;
}

val* evaluate(AST* root) {    
    string root_op = root->node_string;

    if(root_op=="expression"){
        val* temp;
        bool reduce;
        for(auto x: root->children){
            temp = evaluate(x);
            reduce = reduce && temp->valid;
        }
        if(reduce){
            *root = *(create_from_val(temp));
        }
        return temp;
    }
    else if (root_op == "cast_expression"){
        // cout<<"a"<<endl;
        val* temp = evaluate(root->children[1]);
        if(temp->valid){
            *(root->children[1]) = *create_from_val(temp);
        }
        return create_dummy();
    }
    else if (root_op=="assignment"){
        val* res = evaluate(root->children[1]);
        if(res->valid){
            AST* newnode = create_from_val(res);
            *(root->children[1]) = *(createAST(root->nodetype, root->node_string, {root->children[0], newnode}));
        }
        return create_dummy();
    }
    else if (root_op=="?:"){
        val* cond = evaluate(root->children[0]);
        if(cond->valid) {
            if(cond->bval){
                val* btrue = evaluate(root->children[1]);
                if(btrue->valid) *root = *create_from_val(btrue);
                return btrue;
            } else {
                val* bfalse = evaluate(root->children[2]);
                if(bfalse->valid) *root = *create_from_val(bfalse);
                return bfalse;
            }
        }
        return cond;
    }
    else if(root_op=="OR_OP" || root_op=="AND_OP" || root_op=="|" || root_op=="^"
            || root_op=="&" || root_op=="EQ_OP" || root_op=="NE_OP" || root_op=="GE_OP" 
            || root_op=="LE_OP" || root_op==">" || root_op=="<" || root_op=="LEFT_OP" 
            || root_op=="RIGHT_OP" || root_op=="+" || root_op=="-" || root_op=="%" || root_op=="/" || root_op=="*")
    {
        val* left = evaluate(root->children[0]); val* right = evaluate(root->children[1]);
        if(left->valid && right->valid){
            val* res = new val; res->valid = true;
            if (root_op=="OR_OP") {
                res->type = BOOLV; res->bval = left->bval || right->bval;
            }
            else if (root_op=="AND_OP") {
                res->type = BOOLV; res->bval = left->bval && right->bval;
            }
            else if (root_op=="|") {
                res->type = INTV; res->ival = left->ival | right->ival;   
            }
            else if (root_op=="^") {
                res->type = INTV; res->ival = left->ival ^ right->ival;
            }
            else if (root_op=="&") {
                res->type = INTV; res->ival = left->ival & right->ival;
            }
            else if (root_op=="EQ_OP") {
                res->type = BOOLV; 
                // res->bval = left->ival == right->ival;
                if (left->type == INTV ) { res->bval = left->ival == right->ival;}
                else if (left->type == FLOATV ) { res->bval = left->fval == right->fval;}
                else return create_dummy();
            }
            else if (root_op=="NE_OP") {
                res->type = BOOLV; 
                // res->bval = left->ival != right->ival;
                if (left->type == INTV ) { res->bval = left->ival != right->ival;}
                else if (left->type == FLOATV ) { res->bval = left->fval != right->fval;}
                else return create_dummy();
            }
            else if (root_op=="GE_OP") {
                res->type = BOOLV; 
                // res->bval = left->ival >= right->ival;
                if (left->type == INTV ) { res->bval = left->ival >= right->ival;}
                else if (left->type == FLOATV ) { res->bval = left->fval >= right->fval;}
                else return create_dummy();
            }
            else if (root_op=="LE_OP") {
                res->type = BOOLV; 
                // res->bval = left->ival <= right->ival;
                if (left->type == INTV ) { res->bval = left->ival <= right->ival;}
                else if (left->type == FLOATV ) { res->bval = left->fval <= right->fval;}
                else return create_dummy();
            }
            else if (root_op==">") {
                res->type = BOOLV; 
                // res->bval = left->ival > right->ival;
                if (left->type == INTV ) { res->bval = left->ival > right->ival;}
                else if (left->type == FLOATV ) { res->bval = left->fval > right->fval;}
                else return create_dummy();
            }
            else if (root_op=="<") {
                res->type = BOOLV; 
                // res->bval = left->ival < right->ival;
                if (left->type == INTV ) { res->bval = left->ival < right->ival;}
                else if (left->type == FLOATV ) { res->bval = left->fval < right->fval;}
                else return create_dummy();
            }
            else if (root_op=="LEFT_OP") {
                res->type = INTV; res->ival = left->ival << right->ival;
            }
            else if (root_op=="RIGHT_OP") {
                res->type = INTV; res->ival = left->ival >> right->ival;
            }
            else if (root_op=="+") {
                if (left->type == INTV ) {res->type = INTV; res->ival = left->ival + right->ival;}
                else if (left->type == FLOATV ) {res->type = FLOATV; res->fval = left->fval + right->fval;}
                else return create_dummy();
            }
            else if (root_op=="-") {
                if (left->type == INTV ) {res->type = INTV; res->ival = left->ival - right->ival;}
                else if (left->type == FLOATV ) {res->type = FLOATV; res->fval = left->fval - right->fval;}
                else return create_dummy();
            }
            else if (root_op=="%") {
                if (left->type == INTV ) {res->type = INTV; res->ival = left->ival % right->ival;}
                else return create_dummy();
            }
            else if (root_op=="/") {
                if (left->type == INTV ) {res->type = INTV; res->ival = left->ival / right->ival;}
                else if (left->type == FLOATV ) {res->type = FLOATV; res->fval = left->fval / right->fval;}
                else return create_dummy();
                
            }
            else if (root_op=="*") {
                if (left->type == INTV ) {res->type = INTV; res->ival = left->ival * right->ival;}
                else if (left->type == FLOATV ) {res->type = FLOATV; res->fval = left->fval * right->fval;}
                else return create_dummy();
            }
            else return create_dummy();
            *root = *create_from_val(res);
            return res;
        }
        return create_dummy();
    } 
    else if (root_op == "unary_expression"){
        string unary_op = root->children[0]->node_string;
        val* right = evaluate(root->children[1]);
        if(right->valid){
            if (unary_op == "+"){
                *root = *create_from_val(right);
            }
            else if (unary_op == "-"){
                if(right->type == INTV) right->ival = -right->ival;
                else if (right->type == FLOATV) right->fval = -right->fval;
                else return create_dummy();
                *root = *create_from_val(right);
            }
            else if (unary_op == "~") {
                if(right->type == INTV) right->ival = ~right->ival;
                *root = *create_from_val(right);
            }
            else return create_dummy();
            
            return right;
        }
        else return create_dummy();
    }
    else if (root_op == "I_CONSTANT"){
        // cout<<"b"<<endl;
        val* temp = new val;
        temp->valid = true;
        temp->type = INTV;
        temp->ival = stoi(root->value);
        // cout<<"c"<<endl;
        return temp;
    }
    else if (root_op == "F_CONSTANT"){
        val* temp = new val;
        temp->valid = true;
        temp->type = FLOATV;
        temp->fval = stof(root->value);
        return temp;
    }
    else {
        for(auto x: root->children){
            evaluate(x);
        }
        return create_dummy();
    }
}

void constant_folding(AST* root){
    // the two places where expressions start off is with an expression node or the rval of assignment (no expression node)
    if(root->node_string == "expression"){
        for(auto x: root->children) {
            evaluate(x);
        }
    }
    else if(root->node_string == "="){
        val* temp = evaluate(root->children[1]);
        if (temp->valid) root->children[1] = {create_from_val(temp)};
    }
    else {
        for(auto x: root->children){
            constant_folding(x);
        }
    }
}

void dead_code_removal(AST* root){
    if(root->node_string == "ifte"){
        AST* cond = root->children[0]->children[0];
        // cout<<"Before: "<<root->node_string<<endl;
        if(cond->node_string == "BOOL"){
            if(cond->value=="TRUE"){
                // cout<<"A1"<<endl;
                *root = *root->children[1];
                // cout<<"B1"<<endl;
            }
            else {
                // cout<<root->children.size()<<endl;
                if(root->children.size()>2){
                    // cout<<"A2"<<endl;
                    *root = *root->children[2];
                    // cout<<"B2"<<endl;
                }
                else {
                    // cout<<"A3"<<endl;
                    *root = *createAST(0, "NO_OP", {});
                    // cout<<"B3"<<endl;
                }
            }
        }
        // cout<<"After: "<<root->node_string<<endl;
    }
    else if (root->node_string == "while"){
        AST* cond = root->children[0]->children[0];
        if(cond->node_string == "BOOL"){
            if(cond->value=="FALSE"){
                *root = *(createAST(0, "NO_OP", {}));
            }
        }
    }
    else {
        for(auto x: root->children){
            dead_code_removal(x);
        }
    }
    return;
}


////////////// variable substitution ////////////////////////////////////////////////////////////////////

sll_node* createNode(sym_node* node){
    sll_node* newnode = new sll_node;
    newnode->node = node;
    return newnode;
}

void sym_insert(sym_node* node){
    sll_node* newnode = createNode(node);
    newnode->next = sym_table[node->name];
    sym_table[node->name] = newnode;
    return;
}

void add_to_symtable(sym_node* node){
    // cout<<"adding "<<node->name<<endl;
    if(sym_table.find(node->name)==sym_table.end())
        sym_table.insert(make_pair(node->name, createNode(node)));
    else if (sym_table[node->name] == nullptr)
        sym_insert(node);
    else if (sym_table[node->name]->node->scope_level != node->scope_level)
        sym_insert(node);
    return;
}

void scope_exit(int level_to_be_removed) {
    // cout<<" removing level "<<level_to_be_removed<<endl;
    for (auto x: sym_table) {
        if(x.second != nullptr){
            sll_node* temp = x.second;
            if(temp->node->scope_level == level_to_be_removed) {
                // cout<<"removing "<<x.first<<endl;
                sym_table[x.first] = temp->next;
            }
        }
    }
}

sym_node* create_dummy_sym(string name, int scope_level) {
    sym_node* node = new sym_node;
    node->name = name;
    node->scope_level = scope_level;
    return node;
}

void assign_val (sym_node* node, val* value){
    node->valid = value->valid;
    node->type = value->type;
    node->ival = value->ival;
    node->fval = value->fval;
    node->bval = value->bval;
}

bool verify_key(string key){
    if(sym_table.find(key) == sym_table.end() || sym_table[key]==nullptr ) return false;
    return true;
}

val* evaluate(AST* root);

bool replace_var_node(AST* root){
    if (root->node_string == "ID"){
        if(verify_key(root->value)){
            sym_node* node = sym_table[root->value]->node;

            // cout<<"trying to replace "<<root->value<<endl;
            if(node->valid){
                AST* temp = new AST;
                if(node->type == INTV){
                    temp = createAST(0, "I_CONSTANT", {});
                    temp->value = to_string(node->ival);
                } else if (node->type == FLOATV) {
                    temp = createAST(0, "F_CONSTANT", {});
                    temp->value = to_string(node->fval);
                } else {
                    temp = createAST(0, "BOOL", {});
                    if(node->bval) temp->value = "TRUE";
                    else temp->value = "FALSE";
                }
                *root = *temp;
                return true;
            } else {
                return false;
            }
        }
        else {
            return false;
        }
    }
    else {
        bool temp = true;
        for (auto x: root->children) {
            bool _t = replace_var_node(x);
            temp = _t && temp;

        }
        return temp;
    }
}

string find_var_name(AST* root){
    if(root->node_string == "ID") return root->value;
    else {
        for(auto x: root->children) {
            string temp = find_var_name(x);
            if(temp != "") return temp;
        }
    }
    return "";
}

void var_substitution(AST* root, int scope_level){
    // the two places where expressions start off is with an expression node or the rval of assignment (no expression node)
    // objective = replace all the variables that you can possibly replace
    // cout<<"enter"<<endl;
    if (root->node_string == "declaration") {
        // cout<<"a"<<endl;
        AST* init_declarator = root->children[1];

        for(auto x: init_declarator->children) {
            sym_node* newnode;

            if(x->node_string=="="){
                AST* declarator = x->children[0];
                AST* expr = x->children[1];
                int pointer_level = declarator->children[0]->children.size();
                if(declarator->children[1]->node_string=="ID" && pointer_level == 0){
                    newnode = new sym_node;
                    newnode->scope_level = scope_level;
                    newnode->name=declarator->children[1]->value;
                    if(replace_var_node(expr)){
                        assign_val(newnode, evaluate(expr));
                    }
                    else{
                        newnode->valid = false;
                    }
                    add_to_symtable(newnode);
                }
            }
            else {
                if(x->children[1]->node_string=="ID"){
                    AST* declarator = x;
                    newnode = new sym_node;
                    newnode->scope_level = scope_level;
                    newnode->name=declarator->children[1]->value;
                    newnode->valid = false;
                    add_to_symtable(newnode);
                }
            } 
        }
    }
    else if (root->node_string == "assignment") {
        // cout<<"b"<<endl;
        AST* lval = root->children[0];
        AST* rval = root->children[1];
        if(replace_var_node(rval) && lval->node_string == "ID" && verify_key(lval->value)) {
            assign_val(sym_table[lval->value]->node, evaluate(rval));
        }
        else {
            string name = find_var_name(lval);
            if(verify_key(lval->value)){
                sym_table[name]->node->valid = false;
            }
        }
    }
    else if (root->node_string == "expression") {
        // cout<<"c"<<endl;
        replace_var_node(root);
    }
    // scope increments
    else if (root->node_string=="FUNC"){
        // cout<<"d"<<endl;
        AST* param_list = root->children[1]->children[1]->children[1];
        for(auto x: param_list->children){
            sym_node* newnode = new sym_node;
            newnode->valid = false;
            newnode->name = x->children[1]->children[1]->value;
            newnode->scope_level = scope_level+1;
            add_to_symtable(newnode);
        }
        var_substitution(root->children[2], scope_level);
    }
    else if (root->node_string=="compound_statement") {
        // cout<<"e"<<endl;
        for(auto x: root->children) {
            var_substitution(x, scope_level+1);
        }
        scope_exit(scope_level+1);
    }
    else {
        // cout<<"f"<<endl;
        for(auto x: root->children){
            var_substitution(x, scope_level);
        }
    }
    // cout<<"exit"<<endl;
}
