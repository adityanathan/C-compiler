

vector<AST*> getList(AST* node){
    // if (node->nodetype == 3) {
    //     vector<AST*> v = getList(node->children[0]);
    //     v.push_back(node->children[1]);
    //     return v;
    // } 
    // else {
    //     return {node};
    // }

    //dfs
}

string concat_types(AST* node){
    // only for "type" and "pointer"
    string s;
    if(node->children.size() == 0){
        s = "";
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
    cout<<endl<<"trying to add "<<node->name<<endl;
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
                // cout<<endl<<"removing "<<x.first<<endl;
            }
        }
    }
}

bool find_var(AST* root, unordered_map<string, ll_node*>& symbol_table, int scope_level, bool is_decl = false) {
    // the bool return type is to check if parameter_declaration occurs within declaration. (Eg. hello_world.c)
    // false if not found. true if parameter_declaration found.

    // is_decl tells me if this is a declaration or a function

    if (root->node_string=="ID"){
        identifier_node* var = new identifier_node;
        var->symtype = "var";
        var->name = root->value;
        var->scope_level = scope_level;

        add_to_symtable(symbol_table, var);
        return false;
    } 
    else if (root->node_string == "=") {
        // in case of variable declaration - left side is lval. only lval needs to be added to symtable. rval will only be some expr.
        return find_var(root->children[0], symbol_table, scope_level, is_decl);
    }
    else if (root->node_string == "parameter_declaration") {
        if(!is_decl){
            for(auto x: root->children) {
                find_var(x, symbol_table, scope_level, is_decl);
            }
        }
        return true;
    }
    else {
        bool res = false;
        for(auto x: root->children) {
            bool flag = find_var(x, symbol_table, scope_level, is_decl);
            res = res || flag;
        }
        return res;
    }
}

void check_scope(AST* root, unordered_map<string, ll_node*>& symbol_table, int scope_level) {
    if(root->node_string=="FUNC"){
        // cout<<"a";
        // Add new node in symtable for function identifier
        identifier_node* newnode = new identifier_node;

        newnode->symtype = "func";

        AST* temp = root->children[1];
        if(temp->node_string == "direct_declarator" || temp->node_string == "declarator") {
            
            if(temp->node_string == "declarator") {
                temp = temp->children[1];
            }

            newnode->name = temp->children[0]->value;
            
            vector<AST*> param_list = getList(temp->children[1]);

            // add new nodes in symtable for function parameters
            if(!param_list.empty()) {
                for(auto x: param_list) {
                    check_scope(x, symbol_table, scope_level+1);
                }
            }
        }
        else {
            newnode->name = temp->value;
        }
        
        newnode->scope_level = scope_level;

        add_to_symtable(symbol_table, newnode);

        check_scope(root->children[2], symbol_table, scope_level);
    }
    else if (root->node_string == "parameter_declaration") {
        // cout<<"b1 ";
        find_var(root, symbol_table, scope_level);
    }
    else if (root->node_string == "declaration") {
        // cout<<"b2 ";
        for(auto x: root->children) {
            bool flag = find_var(x, symbol_table, scope_level, true);
            if(!flag) {
                // Means this is a function signature because parameter declaration was found within
                check_scope(x, symbol_table, scope_level);
            }
        }
    }
    else if (root->node_string=="labeled_statement") {
        // cout<<"c";
        find_var(root->children[0], symbol_table, scope_level);
        check_scope(root->children[1], symbol_table, scope_level);
    }
    else if (root->node_string=="ID") {
        // cout<<"d";
        if(symbol_table.find(root->value)==symbol_table.end() || symbol_table[root->value]==nullptr){
            cout<<"Scope Error: Undefined - "<<root->value<<endl;
        }
    }
    else if (root->node_string=="while") {
        // cout<<"e";
        check_scope(root->children[0], symbol_table, scope_level);
        if(root->children[1]->node_string=="compound_statement"){
            check_scope(root->children[1], symbol_table, scope_level);
        }
        else {
            check_scope(root->children[1], symbol_table, scope_level+1);
            scope_exit(symbol_table, scope_level+1);
        }
    }
    else if (root->node_string=="ifte") {
        // cout<<"f";
        int num_children = root->children.size();
        check_scope(root->children[0], symbol_table, scope_level);
        for(int i=1; i<num_children; i++){
            if(root->children[i]->node_string=="compound_statement"){
                check_scope(root->children[i], symbol_table, scope_level);
            }
            else {
                check_scope(root->children[i], symbol_table, scope_level+1);
                scope_exit(symbol_table, scope_level+1);
            }
        }
    }
    else if (root->node_string=="fn_call") {
        // cout<<"g";
        string fn2_name = root->children[0]->value;
        if(symbol_table.find(fn2_name)==symbol_table.end()){
            cout<<"Scope Error: Undefined fn call - "<<fn2_name<<endl;
        }

        for(auto x: root->children) {
            check_scope(x, symbol_table, scope_level);
        }

    }
    else if (root->node_string=="compound_statement") {
        // Increase scope
        // cout<<"h";
        for(auto x: root->children) {
            check_scope(x, symbol_table, scope_level+1);
        }
        scope_exit(symbol_table, scope_level+1);
    }
    else {
        // cout<<"i";
        for(auto x: root->children) {
            check_scope(x, symbol_table, scope_level);
        }
    }
    
}



// //////////////////////////////////////////////////////////////////

if(root->node_string=="FUNC"){
        // cout<<"a";
        // Add new node in symtable for function identifier
        identifier_node* newnode = new identifier_node;

        newnode->symtype = "func";

        // invariant for func - first child = type, second child = declarator, third_child = compound_statement
        newnode->type = get_type(root->children[0]);

        AST* declarator_node = root->children[1];
        newnode->pointer_level = declarator_node->children[0]->children.size();

        AST* fn_decl = declarator_node->children[1];
        newnode->name = fn_decl->children[0]->value;

        for(auto x: fn_decl->children[1]->children) {
            identifier_node* param = check_scope(x, symbol_table, scope_level+1);
            newnode->func_args.push_back(param);
        }
        
        newnode->scope_level = scope_level;

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
        for(auto x: root->children) {
            // bool flag = find_var(x, symbol_table, scope_level, true);
            // if(!flag) {
                // Means this is a function signature because parameter declaration was found within
                check_scope(x, symbol_table, scope_level);
            // }
        }
        identifier_node* newnode = new identifier_node;
    }