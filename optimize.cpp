#include "optimize.hpp"

using namespace std;

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
            // root->children = {create_from_val(temp)};
            root = create_from_val(temp);
            // create_from_val(temp); //noop;
        }
        return temp;
    }
    else if (root_op=="assignment"){
        val* res = evaluate(root->children[1]);
        if(res->valid){
            AST* newnode = create_from_val(res);
            root->children[1] = createAST(root->nodetype, root->node_string, {root->children[0], newnode});
        }
        return create_dummy();
    }
    else if (root_op=="?:"){
        val* cond = evaluate(root->children[0]);
        if(cond->valid) {
            if(cond->bval){
                val* btrue = evaluate(root->children[1]);
                if(btrue->valid) root = create_from_val(btrue);
                return btrue;
            } else {
                val* bfalse = evaluate(root->children[2]);
                if(bfalse->valid) root = create_from_val(bfalse);
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
                res->type = BOOLV; res->bval = left->ival == right->ival;
            }
            else if (root_op=="NE_OP") {
                res->type = BOOLV; res->bval = left->ival != right->ival;
            }
            else if (root_op=="GE_OP") {
                res->type = BOOLV; res->bval = left->ival >= right->ival;
            }
            else if (root_op=="LE_OP") {
                res->type = BOOLV; res->bval = left->ival <= right->ival;
            }
            else if (root_op==">") {
                res->type = BOOLV; res->bval = left->ival > right->ival;
            }
            else if (root_op=="<") {
                res->type = BOOLV; res->bval = left->ival < right->ival;
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
            // cout<<"a1"<<endl;
            root = create_from_val(res);
            return res;
        }
    } 
    else if (root_op == "unary_expression"){
        string unary_op = root->children[0]->node_string;
        val* right = evaluate(root->children[1]);
        if(right->valid){
            if (unary_op == "+"){
                root = create_from_val(right);
            }
            else if (unary_op == "-"){
                if(right->type == INTV) right->ival = -right->ival;
                else if (right->type == FLOATV) right->fval = -right->fval;
                else return create_dummy();
                root = create_from_val(right);
            }
            else if (unary_op == "~") {
                if(right->type == INTV) right->ival = ~right->ival;
                root = create_from_val(right);
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
    return create_dummy();
}

void constant_folding(AST* root){
    if(root->node_string == "expression"){
        val* temp = evaluate(root);
        if (temp->valid) root->children = {create_from_val(temp)};
    } else {
        for(auto x: root->children){
            constant_folding(x);
        }
    }
}

// void dead_code_removal(AST* root){

// }

void optimize(AST* root) {
    constant_folding(root);
}