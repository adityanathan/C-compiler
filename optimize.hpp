#include "ast.hpp"
#include <iostream>

enum valtype {INTV, FLOATV, BOOLV};
struct val {
    bool valid = false;
    valtype type; //int or floats
    int ival = 0;
    float fval = 0.0f;
    bool bval = false;
};

void optimize(AST* root);