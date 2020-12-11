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
string get_ll_name(string name, int i){
    return name+'.'+to_string(i);
}

ll_node* createNode(identifier_node* node){
    ll_node* newnode = new ll_node;
    newnode->node = node;
    return newnode;
}

void sym_insert(unordered_map<string, ll_node*>& symbol_table, identifier_node* node){
    ll_node* newnode = createNode(node);
    newnode->next = symbol_table[node->name];

    if(symbol_table[node->name]!=nullptr)
        newnode->list_length = symbol_table[node->name]->list_length + 1;
    else
        newnode->list_length = 0;

    newnode->node->llvm_name = get_ll_name(node->name, newnode->list_length);

    symbol_table[node->name] = newnode;
    return;
}

void add_to_symtable(unordered_map<string, ll_node*>& symbol_table, identifier_node* node){
    // cout<<endl<<"trying to add "<<node->name<<"\t"<<node->scope_level<<"\t"<<node->type<<" "<<node->pointer_level<<endl;
    if(symbol_table.find(node->name)==symbol_table.end()) {
        node->llvm_name = get_ll_name(node->name, 0);
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

string convert_type(string type) {
    if(type=="VOID") return "void";
    if(type=="BOOL") return "i1";
    if(type=="CHAR") return "i8";
    if(type=="SHORT") return "i16";
    if(type=="INT") return "i32";
    if(type=="LONG") return "i64";
    if(type=="FLOAT") return "float";
    if(type=="DOUBLE") return "double";
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
        // s = node->children[0]->node_string;
        // for(int i=1; i<node->children.size(); i++){
        //     s = s + ' ' + node->children[i]->node_string;
        // }   
        for(auto x: node->children){
            if(x->node_string != "SIGNED" && x->node_string != "UNSIGNED") {
                s = x->node_string;
                break;
            }
        }   
    }
    return convert_type(s);
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
            if(x->node_string == "ELLIPSIS") {newnode->variadic = true; continue;}
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
        for(auto x: fn_decl->children[1]->children) {
            if(x->node_string == "ELLIPSIS") {newnode->variadic = true; continue;}
            identifier_node* param = cgen(x, symbol_table, scope_level+1);
            newnode->func_args.push_back(param);
        }
    }
    return newnode;
}

string get_register(){
    string s = '\%'+string("e.")+to_string(register_counter);
    register_counter++;
    return s;
}

string get_label(string label){
    string s = label+'.'+to_string(label_counter);
    label_counter++;
    return s;
}

identifier_node* get_sym(AST* node, unordered_map<string, ll_node*>& symtable){
    // precondition = node must have node_string=="ID"
    return symtable[node->value]->node;
}

string get_ll_ptr(identifier_node* node){
    return '\%'+(node->llvm_name)+'.'+string("addr");
}

string get_ll_name(identifier_node* node){
    return '\%'+node->llvm_name;
}

pair<string, string> new_allocate(string type){
    stringstream ss;
    string reg = get_register();
    ss<<reg<<" = alloca "<<type<<"\n";
    return make_pair(reg, ss.str());
}

string allocate(identifier_node* node){
    stringstream ss;
    ss<<get_ll_ptr(node)<<" = alloca "<<node->type<<"\n";
    return ss.str();
}

pair<string,string> load(identifier_node* node){
    // ret = register, llvm_code
    stringstream ss;
    string reg = get_register();
    string type = node->type;
    ss<<reg<<" = load "<<type<<", "<<type<<"* "<<get_ll_ptr(node)<<"\n";
    return make_pair(reg, ss.str());
}

string store(identifier_node* node, string register_val){
    // returns llvm code
    // register_val could be a reg or a val
    stringstream ss;
    string type = node->type;
    ss<<"store "<<type<<" "<<register_val<<", "<<type<<"* "<<get_ll_ptr(node)<<"\n";
    return ss.str();
}

string bitcast(pair<string, string> reg, string type2){
    // input - (type1, register_name1) , type2 => typecast to type2
    // return register with typecasted result
    unordered_map<string, int> temp_d = {{"i1", 0}, {"i8", 1}, {"i16", 2}, {"i32", 3}, {"i64", 4}, {"float", 5}, {"double", 7}};
    string cast;
    if(temp_d.at(reg.first)<=4 && temp_d.at(type2)<=4){
        if(temp_d.at(reg.first) > temp_d.at(type2)) cast = "trunc"; 
        else cast = "sext";
    } else if (temp_d.at(reg.first)<=4 && temp_d.at(type2)>4) cast = "sitofp";
    else if (temp_d.at(reg.first)>4 && temp_d.at(type2)>=4) cast = "fptosi";
    else {
        if(temp_d.at(reg.first) > temp_d.at(type2)) cast = "fptrunc"; 
        else cast = "fpext";
    }

    stringstream ss;
    string new_reg = get_register();
    ss<<new_reg<<" = "<<cast<<" "<<reg.first<<" "<<reg.second<<" to "<<type2<<"\n";
    file<<ss.str();
    return new_reg;
}

pair<pair<string, string>, pair<string, string>> type_clash(pair<string, string> reg1, pair<string, string> reg2){
    // Expected to print code itself
    // first string = type, second string = reg_name
    unordered_map<string, int> temp_d = {{"i1", 0}, {"i8", 1}, {"i16", 2}, {"i32", 3}, {"i64", 4}, {"float", 5}, {"double", 7}};
    if(temp_d.at(reg1.first)>temp_d.at(reg2.first)){
        string _t = bitcast(reg2, reg1.first);
        return {reg1, {reg1.first, _t}};
    }
    else {
        string _t = bitcast(reg1, reg2.first);
        return {{reg2.first, _t}, reg2};
    }
}

pair<string, string> cgen_expression(AST* root, unordered_map<string, ll_node*>& symtable, int scope_level);

pair<string, string> cgen_binary_exp(AST* root, unordered_map<string, ll_node*>& symtable, int scope_level){
    // Precondition = root_op must be a binary expression
    string root_op = root->node_string;
    string left_type, left_reg, right_type, right_reg;
    tie(left_type, left_reg) = cgen_expression(root->children[0], symtable, scope_level);
    tie(right_type, right_reg) = cgen_expression(root->children[1], symtable, scope_level);
    if(left_type != right_type) {
        auto _t2 = type_clash({left_type, left_reg},{right_type, right_reg});
        tie(left_type, left_reg) = _t2.first;
        tie(right_type, right_reg) = _t2.second;
    }
    string result_register = get_register();
    if(root_op == "OR_OP" || root_op == "|") {
        // assumption = for or_op type is i1. Typing not implemented.
        file<<result_register<<" = "<<"or "<<left_type<<" "<<left_reg<<", "<<right_reg<<"\n";
        if(root_op == "OR_OP" && left_type!="i1"){
            string _t3 = bitcast({left_type, result_register}, "i1");
            result_register = _t3; left_type = "i1";
        }
    }
    else if(root_op == "AND_OP" || root_op == "&") {
        file<<result_register<<" = "<<"and "<<left_type<<" "<<left_reg<<", "<<right_reg<<"\n";
        if(root_op == "AND_OP" && left_type!="i1"){
            string _t3 = bitcast({left_type, result_register}, "i1");
            result_register = _t3; left_type = "i1";
        }
    }
    else if(root_op == "^") {
        file<<result_register<<" = "<<"xor "<<left_type<<" "<<left_reg<<", "<<right_reg<<"\n";       
    }
    else if(root_op == "NE_OP" || root_op == "EQ_OP" || root_op == "GE_OP" || root_op == "LE_OP" || root_op == ">" || root_op == "<") {
        unordered_map<string, string> temp_d = {{"NE_OP", "ne"}, {"EQ_OP","eq"}, {"GE_OP", "sge"}, {"LE_OP", "sle"}, {">", "sgt"}, {"<", "slt"}};
        file<<result_register<<" = "<<"icmp "<<temp_d.at(root_op)<<" "<<left_type<<" "<<left_reg<<", "<<right_reg<<"\n";
        return make_pair("i1", result_register);
    }
    else if(root_op == "RIGHT_OP" || root_op == "LEFT_OP"){
        unordered_map<string, string> temp_d = {{"RIGHT_OP", "lshr"}, {"LEFT_OP","shl"}};
        file<<result_register<<" = "<<temp_d.at(root_op)<<" "<<left_type<<" "<<left_reg<<", "<<right_reg<<"\n";
    }
    else if(root_op == "+" || root_op == "-" ||root_op == "*" || root_op == "/" || root_op == "%") {
        unordered_map<string, string> temp_d = {{"+", "add"}, {"-","sub"}, {"*","mul"}, {"/","sdiv"},{"%","srem"}};
        file<<result_register<<" = "<<temp_d.at(root_op)<<" "<<left_type<<" "<<left_reg<<", "<<right_reg<<"\n";
    }
    return make_pair(left_type, result_register);
}

pair<string, string> cgen_expression(AST* root, unordered_map<string, ll_node*>& symtable, int scope_level){
    // return type = type, result register
    // meant to handle everything starting from assignment_expression non_terminal because (expression = list of assignment_expression)
    // return the reg name that contains the result of the expression
    string root_op = root->node_string;
    if(root_op=="expression"){
        pair<string, string> temp;
        for(auto x: root->children){
            temp = cgen_expression(x, symtable, scope_level);
        }
        return temp;
    }
    else if (root_op=="assignment"){
        // assuming lval = ID
        // returns assigned value
        if(root->children[0]->node_string != "ID") {
            cout<<"Error: assignment requires lvalue to be an identifier"<<endl;
            return cgen_expression(root->children[1], symtable, scope_level);
        }
        identifier_node* id = get_sym(root->children[0], symtable);
        string type, result;
        tie(type, result) = cgen_expression(root->children[1], symtable, scope_level);
        if(type!=id->type) {
            string temp = bitcast(make_pair(type, result), id->type);
            result = temp;
        }
        file<<store(id, result);
        return make_pair(id->type, result);
    }
    else if (root_op=="ID"){
        identifier_node* id = get_sym(root, symtable);
        pair<string,string> temp = load(id);
        file<<temp.second;
        return make_pair(id->type, temp.first);
    }
    else if (root_op=="?:"){
        string _temp, cond;
        tie(_temp, cond) = cgen_expression(root->children[0], symtable, scope_level);
        if(_temp!="i1"){
            string _t1 = bitcast({_temp, cond}, "i1");
            cond = _t1;
        }
        string btrue = get_label("btrue");
        string bfalse = get_label("bfalse");
        string bend = get_label("bend");
        file<<"br i1 "<<cond<<", "<<"label "<<btrue<<", label "<<bfalse<<"\n";

        file<<endl;
        file<<btrue<<":\n";
        string true_type, true_reg;
        tie(true_type, true_reg) = cgen_expression(root->children[1], symtable, scope_level);

        file<<endl;
        file<<bfalse<<":\n";
        string false_type, false_reg;
        tie(false_type, false_reg) = cgen_expression(root->children[2], symtable, scope_level);

        file<<endl;
        file<<bend<<":\n";
        if(false_type != true_type) {
            auto _t2 = type_clash({true_type, true_reg},{false_type, false_reg});
            tie(true_type, true_reg) = _t2.first;
            tie(false_type, false_reg) = _t2.second;
        }
        string result_register = get_register();
        file<<result_register<<" = "<<"phi "<<true_type<<" [ "<<true_reg<<", "<<btrue<<" ], "<<" [ "<<false_reg<<", "<<bfalse<<" ]"<<"\n";
        return make_pair(true_type, result_register);
    }
    else if (root_op=="OR_OP" || root_op=="AND_OP" || root_op=="|" || root_op=="^"
            || root_op=="&" || root_op=="EQ_OP" || root_op=="NE_OP" || root_op=="GE_OP" 
            || root_op=="LE_OP" || root_op==">" || root_op=="<" || root_op=="LEFT_OP" 
            || root_op=="RIGHT_OP" || root_op=="+" || root_op=="-" || root_op=="%" || root_op=="/" || root_op=="*"
            ) 
    {
        return cgen_binary_exp(root, symtable, scope_level);
    }
    else if (root_op == "unary_expression"){
        string unary_op = root->children[0]->node_string;
        if(unary_op == "INC_OP" || unary_op =="DEC_OP"){
            unordered_map<string, string> temp_d = {{"INC_OP", "add"}, {"DEC_OP","sub"}};
            string type, result;
            if(root->children[1]->node_string != "ID"){
                cout<<"Error: increment and decrement operators can only be applied to identifiers"<<endl;
                return cgen_expression(root->children[1], symtable, scope_level);
            }
            identifier_node* id = get_sym(root->children[1], symtable);
            pair<string,string> temp = load(id);
            file<<temp.second;

            string old_val = temp.first;
            string new_val = get_register();
            file<<new_val<<" = "<<temp_d[root_op]<<" "<<id->type<<" "<<old_val<<", "<<"1"<<"\n";
            file<<store(id, new_val);
            return make_pair(id->type, new_val);
        }
        else if (unary_op == "&"){
            if(root->children[1]->node_string != "ID"){
                cout<<"Error: & operator can only be applied to identifiers"<<endl;
                return cgen_expression(root->children[1], symtable, scope_level);
            }
            identifier_node* id = get_sym(root->children[1], symtable);
            return make_pair(id->type, get_ll_ptr(id));
        }
        else if (unary_op == "*"){
            if(root->children[1]->node_string != "ID"){
                cout<<"Error: * operator can only be applied to identifiers"<<endl;
                return cgen_expression(root->children[1], symtable, scope_level);
            }
            identifier_node* id = get_sym(root->children[1], symtable);
            pair<string, string> temp = load(id);
            file<<temp.second;
            return make_pair(id->type, temp.first);
        }
        else if (unary_op == "+"){
            return cgen_expression(root->children[1], symtable, scope_level);
        }
        else if (unary_op == "-"){
            string type, reg;
            tie(type, reg) = cgen_expression(root->children[1], symtable, scope_level);
            string new_val = get_register();
            file<<new_val<<" = sub "<<type<<" 0, "<<reg<<"\n";
            return make_pair(type, new_val);
        }
        else if (unary_op == "~" || unary_op == "!") {
            string type, reg;
            tie(type, reg) = cgen_expression(root->children[1], symtable, scope_level);
            if(unary_op == "!" && type != "i1") {
                string _t3 = bitcast({type, reg}, "i1");
                reg = _t3;
                type = "i1";
            }
            string new_val = get_register();
            file<<new_val<<" = xor "<<type<<" "<<reg<<", -1"<<"\n";
            return make_pair(type, new_val);
        }
    }
    else if (root_op == "fn_call"){
        stringstream ss;
        string result_reg = get_register();
        identifier_node* fn = get_sym(root->children[0], symtable);
        
        ss<<"call "<<fn->type<<" @"<<fn->name<<"(";
        string separator = "";
        for(auto x: root->children[1]->children){
            string type, reg;
            tie(type, reg) = cgen_expression(x, symtable, scope_level);
            ss<<separator<<" "<<type<<" "<<reg;
            separator = ",";
        }
        ss<<")\n";
        file<<ss.str();
    }
    else if (root_op == "postfix_expression"){

    }
    else if (root_op == "I_CONSTANT"){
        string value = root->value;
        string reg = get_register();
        file<<reg<<" = add i64 0, "<<value<<"\n";
        return make_pair("i64", reg);
    }
    else if (root_op == "F_CONSTANT"){
        string value = root->value;
        string reg = get_register();
        file<<reg<<" = fadd double 0.0, "<<value<<"\n";
        return make_pair("double", reg);
    }
    else if (root_op == "STRING_LITERAL"){
        string str = root->value;
        string s = '@'+string("str.")+to_string(register_counter);
        register_counter++;
        string_constants[s] = str;
    }
}

identifier_node* cgen(AST* root, unordered_map<string, ll_node*>& symtable, int scope_level) {
    if(root->node_string=="FUNC"){
        stringstream ss;
        string type = get_type(root->children[0]);
        identifier_node* newnode = cgen_declarator_node(root->children[1], type, symtable, scope_level);
        add_to_symtable(symtable, newnode);
        
        ss<<"define "<<type<<" @"<<newnode->name<<"(";
        string separator = "";
        for(auto x: newnode->func_args){
            ss<<separator<<x->type<<" "<<get_ll_name(x);
            separator = ", ";
        }
        ss<<") { \nentry: \n"; 
        file<<ss.str();

        // allocating space for parameters
        for(auto x: newnode->func_args){
            file<<allocate(x);
            file<<store(x, get_ll_name(x));
        }


        cgen(root->children[2], symtable, scope_level);
        
        if(type == "void"){
            file<<"ret void"<<endl;
        }
        else {
            // safety net
            file<<"ret "<<type<<" undef"<<endl;
        }
        file<<"}"<<endl;
        
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
    else if (root->node_string=="compound_statement") {
        for(auto x: root->children) {
            cgen(x, symtable, scope_level+1);
        }
        scope_exit(symtable, scope_level+1);
        return nullptr;
    }
    else if (root->node_string=="expression") {
        cgen_expression(root, symtable, scope_level);
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