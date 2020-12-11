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

bool find_label(ll_node* list){
    while(list){
        if(list->node->symtype=="label") return true;
        list = list->next;
    }
    return false;
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

void validate_jumps(AST* root){
    // called if while node encountered during scope checking
    // precondition: root must be a loop - while node
    // this function validates all breaks and continues within this loop
    if(root->node_string=="CONTINUE"){
        root->jump_valid = true;
    }
    else if (root->node_string == "BREAK"){
        root->jump_valid = true;
    } else {
        for(auto x: root->children){
            validate_jumps(x);
        }
    }
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
                newnode = process_declarator_node(x, type, symbol_table, scope_level); // Can return either a var or a function (see grammar)
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
    else if (root->node_string=="jump"){
        if(root->children[0]->node_string=="GOTO"){
            string label = root->children[1]->value;
            if (symbol_table.find(label)==symbol_table.end() || symbol_table[label]==nullptr || !find_label(symbol_table[label]) ){
            cout<<"Scope Error: Undefined label - "<<root->value<<endl;
        }
        return nullptr;
        }
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
    else if (root->node_string=="while") {validate_jumps(root);}
    else if (root->node_string == "CONTINUE") {if(!root->jump_valid); throw string("'continue' should be used only inside loops");}
    else if (root->node_string == "BREAK") {if(!root->jump_valid); throw string("'break' should be used only inside loops");}
    else {
        // cout<<"i";
        for(auto x: root->children) {
            check_scope(x, symbol_table, scope_level);
        }
        return nullptr;
    }
}

/////////////////////////////// Lab 2 Part 3 /////////////////////////////////////////////////////////////////////////////////

string print_type(string type, int pointer_level){
    stringstream ss;
    ss<<type;
    for(int i=0; i<pointer_level; i++){
        ss<<"*";
    }
    return ss.str();
}

string print_type(identifier_node* node){
    stringstream ss;
    ss<<node->type;
    for(int i=0; i<node->pointer_level; i++){
        ss<<"*";
    }
    return ss.str();
}

identifier_node* cgen_declarator_node(AST* root, string type, unordered_map<string, ll_node*>& symbol_table, int scope_level){
    // input AST node has to be a declarator node only
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
    cout<<"name - "<<newnode->name<<endl;
    return newnode;
}

string get_register(){
    string s = '\%'+string("e.")+to_string(register_counter);
    register_counter++;
    return s;
}

string get_label(string label, bool get_last_label = false){
    // returns name without % prefix - need to append % if you want to use it with br.
    if(get_last_label) {return label+'.'+to_string(label_counter-1);}
    string s = label+'.'+to_string(label_counter);
    label_counter++;
    return s;
}

string get_loop_label(string label, bool get_last_label = false){
    // returns name without % prefix - need to append % if you want to use it with br.
    if(get_last_label) {return label+'.'+to_string(loop_label_counter-1);}
    string s = label+'.'+to_string(loop_label_counter);
    loop_label_counter++;
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
    else if (temp_d.at(reg.first)>4 && temp_d.at(type2)<=4) cast = "fptosi";
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
    // cout<<"enter"<<endl;
    string root_op = root->node_string;
    string left_type, left_reg, right_type, right_reg;
    cout<<"left enter"<<endl;
    tie(left_type, left_reg) = cgen_expression(root->children[0], symtable, scope_level);
    cout<<"right enter"<<endl;
    tie(right_type, right_reg) = cgen_expression(root->children[1], symtable, scope_level);
    if(left_type != right_type) {
        auto _t2 = type_clash({left_type, left_reg},{right_type, right_reg});
        tie(left_type, left_reg) = _t2.first;
        tie(right_type, right_reg) = _t2.second;
    }
    string result_register = get_register();
    cout<<"recursed"<<endl;
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
        if(left_type == "float" || left_type == "double"){
            unordered_map<string, string> temp_d = {{"+", "fadd"}, {"-","fsub"}, {"*","fmul"}, {"/","fdiv"},{"%","frem"}};
        } else { unordered_map<string, string> temp_d = {{"+", "add"}, {"-","sub"}, {"*","mul"}, {"/","sdiv"},{"%","srem"}}; }
        file<<result_register<<" = "<<temp_d.at(root_op)<<" "<<left_type<<" "<<left_reg<<", "<<right_reg<<"\n";
    }
    // cout<<"exit "<<endl;
    return make_pair(left_type, result_register);
}

pair<string, string> cgen_expression(AST* root, unordered_map<string, ll_node*>& symtable, int scope_level){
    // return type = type, result register
    // meant to handle everything starting from assignment_expression non_terminal because (expression = list of assignment_expression)
    // return the reg name that contains the result of the expression
    // cout<<"cgen expr enter"<<endl;
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
            result = temp; type = id->type;
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
            cond = _t1; _temp = "i1";
        }
        string btrue = get_label("btrue");
        string bfalse = get_label("bfalse", true);
        string bend = get_label("bend", true);
        file<<"br i1 "<<cond<<", "<<"label %"<<btrue<<", label %"<<bfalse<<"\n";

        file<<endl;
        file<<btrue<<":\n";
        string true_type, true_reg;
        tie(true_type, true_reg) = cgen_expression(root->children[1], symtable, scope_level);
        file<<"br label %"<<bend<<"\n";

        file<<endl;
        file<<bfalse<<":\n";
        string false_type, false_reg;
        tie(false_type, false_reg) = cgen_expression(root->children[2], symtable, scope_level);
        file<<"br label %"<<bend<<"\n";

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
            if(type == "float" || type == "double"){
                file<<new_val<<" = fsub "<<type<<" 0, "<<reg<<"\n";
            }
            else { file<<new_val<<" = sub "<<type<<" 0, "<<reg<<"\n"; }
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
        
        ss<<result_reg<<" = "<<"call "<<fn->type<<" @"<<fn->name<<"(";
        string separator = "";
        for(auto x: root->children[1]->children){
            string type, reg;
            tie(type, reg) = cgen_expression(x, symtable, scope_level);
            ss<<separator<<" "<<type<<" "<<reg;
            separator = ",";
        }
        ss<<")\n";
        file<<ss.str();
        return make_pair(fn->type, result_reg);
    }
    else if (root_op == "postfix_expression"){
        // This is wrong. This does normal prefix
        string op = root->children[1]->node_string;
        unordered_map<string, string> temp_d = {{"INC_OP", "add"}, {"DEC_OP","sub"}};
        string type, result;
        if(root->children[0]->node_string != "ID"){
            cout<<"Error: increment and decrement operators can only be applied to identifiers"<<endl;
            return cgen_expression(root->children[0], symtable, scope_level);
        }
        identifier_node* id = get_sym(root->children[0], symtable);
        pair<string,string> temp = load(id);
        file<<temp.second;

        string old_val = temp.first;
        string new_val = get_register();
        file<<new_val<<" = "<<temp_d[op]<<" "<<id->type<<" "<<old_val<<", "<<"1"<<"\n";
        file<<store(id, new_val);
        return make_pair(id->type, new_val);
    }
    else if (root_op == "I_CONSTANT"){
        string value = root->value;
        string reg = get_register();
        file<<reg<<" = add i32 0, "<<value<<"\n";
        return make_pair("i32", reg);
    }
    else if (root_op == "F_CONSTANT"){
        string value = root->value;
        string reg = get_register();
        file<<reg<<" = fadd float 0.0, "<<value<<"\n";
        return make_pair("float", reg);
    }
    else if (root_op == "STRING_LITERAL"){
        string str = root->value;
        str.insert(str.size()-1,"\\0A\\00");
        string s = '@'+string("str.")+to_string(register_counter);
        register_counter++;
        string_constants[s] = str;

        int sz = str.size()+2-2;
        string type = "[ "+to_string(sz)+" x i8 ]";

        file<<"i8* getelementptr inbounds ("<<type<<", "<<type<<"* "<<s<<", i64 0, i64 0)";

        return make_pair(type, s); // should never be used.
    }
    // cout<<"cgen expr exit"<<endl;
}

identifier_node* cgen(AST* root, unordered_map<string, ll_node*>& symtable, int scope_level) {
    if(root->node_string=="FUNC"){
        cout<<"a"<<endl;
        stringstream ss;
        string type = get_type(root->children[0]);
        identifier_node* newnode = cgen_declarator_node(root->children[1], type, symtable, scope_level);
        add_to_symtable(symtable, newnode);
        
        func_ret_type = newnode->type;

        ss<<"define "<<newnode->type<<" @"<<newnode->name<<"(";
        string separator = "";
        for(auto x: newnode->func_args){
            ss<<separator<<x->type<<" "<<get_ll_name(x);
            separator = ", ";
        }
        if(newnode->variadic) ss<<", ...";
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
            file<<"ret "<<type<<" undef"<<endl; // safety net
        }
        file<<"}\n"<<endl;
    }
    else if (root->node_string == "parameter_declaration") {
        cout<<"b"<<endl;
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
    else if (root->node_string == "declaration"){
        cout<<"c"<<endl;
        string type = get_type(root->children[0]);
        AST* init_declarator = root->children[1];
        for(auto x: init_declarator->children) {
            identifier_node* newnode;
            if(x->node_string=="="){
                string rval_type, rval_reg;
                tie(rval_type, rval_reg) = cgen_expression(x->children[1], symtable, scope_level); // rval is an assignment_expression
                newnode = cgen_declarator_node(x->children[0], type, symtable, scope_level); // returns the LHS variable - definitely a var
                add_to_symtable(symtable, newnode); // needs to be added before so that llvm_name is properly defined for alloca and store
                if(newnode->type != rval_type){
                    string _t3 = bitcast({rval_type, rval_reg}, newnode->type);
                    rval_reg = _t3;
                    rval_type = newnode->type;
                }
                file<<allocate(newnode);
                file<<store(newnode, rval_reg);
            }
            else{
                newnode = cgen_declarator_node(x, type, symtable, scope_level);
                add_to_symtable(symtable, newnode); // needs to be added before so that llvm_name is properly defined for alloca and store
                if(newnode->symtype == "func"){
                    scope_exit(symtable, scope_level+1); // To remove the function args from scope. Since it has no compound statement
                    
                    stringstream ss;
                    ss<<"declare "<<newnode->type<<" @"<<newnode->name<<"(";
                    string separator = "";
                    for(auto x: newnode->func_args){
                        ss<<separator<<x->type<<" "<<get_ll_name(x);
                        separator = ", ";
                    }
                    if(newnode->variadic) ss<<", ...";
                    ss<<")\n"; 
                    file<<ss.str();
                } 
                else if (newnode->symtype == "var") {
                    file<<allocate(newnode);
                }
            } 
        }
    }
    else if (root->node_string=="labeled_statement") {
        cout<<"d"<<endl;
        identifier_node* newnode = new identifier_node;
        newnode->symtype = "label";
        newnode->name = root->children[0]->value;
        newnode->scope_level = scope_level;
        add_to_symtable(symtable, newnode);

        // override default llvm_name
        string llvm_label = get_label(newnode->name);
        newnode->llvm_name = llvm_label;

        file<<"br label %"<<llvm_label<<"\n"; //end prev basic block
        file<<llvm_label<<":\n"; // start new basic block

        cgen(root->children[1], symtable, scope_level);
    }
    else if (root->node_string == "ifte"){
        cout<<"e"<<endl;
        string btrue = get_label("btrue");
        string bfalse = get_label("bfalse", true);
        string bend = get_label("bend", true);
        
        string _temp, cond;
        tie(_temp, cond) = cgen_expression(root->children[0], symtable, scope_level);
        if(_temp!="i1"){
            string _t1 = bitcast({_temp, cond}, "i1");
            cond = _t1; _temp = "i1";
        }
        if(root->children.size()>2){
            file<<"br i1 "<<cond<<", "<<"label %"<<btrue<<", label %"<<bfalse<<"\n";
        } else {
            file<<"br i1 "<<cond<<", "<<"label %"<<btrue<<", label %"<<bend<<"\n";
        }

        file<<endl;
        file<<btrue<<":\n";
        cgen(root->children[1], symtable, scope_level);
        file<<"br label %"<<bend<<"\n";

        if(root->children.size()>2){
            file<<endl;
            file<<bfalse<<":\n";
            cgen(root->children[2], symtable, scope_level);
            file<<"br label %"<<bend<<"\n";
        }

        file<<endl;
        file<<bend<<":\n";
    }
    else if (root->node_string == "while"){
        cout<<"f"<<endl;
        // check condition, body, end_loop
        string cond_label = get_loop_label("while_condition");
        string body_label = get_loop_label("while_body", true);
        string end_label = get_loop_label("while_end", true);

        file<<"br label %"<<cond_label<<"\n"; //end previous basic block

        file<<endl;
        file<<cond_label<<":\n";
        string _temp, cond;
        tie(_temp, cond) = cgen_expression(root->children[0], symtable, scope_level);
        if(_temp!="i1"){
            string _t1 = bitcast({_temp, cond}, "i1");
            cond = _t1; _temp = "i1";
        }
        file<<"br i1 "<<cond<<", "<<"label %"<<body_label<<", label %"<<end_label<<"\n";

        file<<endl;
        file<<body_label<<":\n";
        cgen(root->children[1], symtable, scope_level);
        file<<"br label %"<<cond_label<<"\n";

        file<<endl;
        file<<end_label<<":\n";
    }
    else if (root->node_string == "jump"){
        cout<<"g"<<endl;
        // will always have atleast one child
        string op = root->children[0]->node_string;
        if(op == "GOTO"){
            string id = root->children[1]->value;
            ll_node* list = symtable[id];
            string branch_name;
            while(list){
                if(list->node->symtype=="label"){
                    branch_name = list->node->llvm_name;
                }
                list = list->next;
            }
            // Guaranteed to get a label because scope checking done.
            file<<"br label %"<<branch_name<<"\n";
        }
        else if (op == "CONTINUE"){
            string cond_label = get_loop_label("while_condition", false);
            file<<"br label %"<<cond_label<<"\n";
        }
        else if (op == "BREAK"){
            string end_label = get_loop_label("while_end", true);
            file<<"br label %"<<end_label<<"\n";
        }
        else if (op == "RETURN"){
            if(root->children.size()==1){
                if(func_ret_type == "void"){
                    file<<"ret void\n";
                }
                else {
                    file<<"ret "<<func_ret_type<<" undef\n";
                }
            } else {
                string type, reg;
                tie(type, reg) = cgen_expression(root->children[1], symtable, scope_level);
                if(func_ret_type!=type){
                    string _t1 = bitcast({type, reg}, func_ret_type);
                    reg = _t1; type = func_ret_type;
                }
                file<<"ret "<<func_ret_type<<" "<<reg<<"\n";
            }
        }
    }
    else if (root->node_string=="compound_statement") {
        cout<<"h"<<endl;
        for(auto x: root->children) {
            cgen(x, symtable, scope_level+1);
        }
        scope_exit(symtable, scope_level+1);
    }
    else if (root->node_string=="expression") {
        cout<<"j"<<endl;
        cgen_expression(root, symtable, scope_level);
    }
    else {
        cout<<"k"<<endl;
        for(auto x: root->children) {
            cgen(x, symtable, scope_level);
        }
    }
    return nullptr;
}

