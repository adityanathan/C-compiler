#include "ast.hpp"
#include <iostream>
// #include <unordered_map>
// #include <pair>

#ifndef OPTIMIZE_HPP
#define OPTIMIZE_HPP

enum valtype {INTV, FLOATV, BOOLV};
struct val {
    bool valid = false;
    valtype type;
    int ival = 0;
    float fval = 0.0f;
    bool bval = false;
};

struct sym_node {
    string name;
    int scope_level;
    bool valid = false;

    valtype type;
    int ival = 0;
    float fval = 0.0f;
    bool bval = false;
};

struct sll_node {
    sym_node* node;
    sll_node* next = nullptr;
};

void optimize(AST* root);

#endif