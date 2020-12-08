%{
#include <cstdio>
#include <iostream>

#include "ast.hpp"
using namespace std;

// stuff from flex that bison needs to know about:
extern "C" int yylex();
int yyparse();
extern "C" FILE *yyin;
 
void yyerror(const char *s);

// #define AST struct AST

AST* ast_root;

%}

%union{
	AST* a;
	char* s;
}
%token	<s> IDENTIFIER I_CONSTANT F_CONSTANT STRING_LITERAL FUNC_NAME SIZEOF

%token	<s> PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token	<s> AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token	<s> SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token	<s> XOR_ASSIGN OR_ASSIGN
%token	<s> TYPEDEF_NAME

%token	<s> TYPEDEF EXTERN STATIC AUTO REGISTER INLINE
%token	<s> CONST RESTRICT VOLATILE
%token	<s> BOOL CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE VOID
%token	<s> COMPLEX IMAGINARY 
%token	<s> STRUCT UNION ENUM ELLIPSIS

%token	<s> CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%token	<s> ALIGNAS ALIGNOF ATOMIC GENERIC NORETURN STATIC_ASSERT THREAD_LOCAL

%type <a> primary_expression constant string postfix_expression
%type <a> argument_expression_list unary_expression unary_operator multiplicative_expression
%type <a> additive_expression shift_expression relational_expression equality_expression and_expression
%type <a> exclusive_or_expression inclusive_or_expression logical_and_expression logical_or_expression
%type <a> conditional_expression assignment_expression expression
%type <a> declaration declaration_specifiers init_declarator_list init_declarator type_specifier type_qualifier
%type <a> declarator direct_declarator pointer type_qualifier_list parameter_type_list parameter_list
%type <a> parameter_declaration initializer initializer_list statement
%type <a> labeled_statement compound_statement block_item_list block_item expression_statement selection_statement
%type <a> iteration_statement jump_statement new_start translation_unit external_declaration function_definition

// %start translation_unit
%start new_start
%%

primary_expression
	: IDENTIFIER 	{ $$ = createAST(0, "ID", {}, $1); }
	| constant
	| string
	| '(' expression ')'		{ $$ = $2; }
	;

constant
	: I_CONSTANT		{ $$ = createAST(0, "I_CONSTANT", {}, $1); }		/* includes character_constant */
	| F_CONSTANT		{ $$ = createAST(0, "F_CONSTANT", {}, $1); }
	;

string
	: STRING_LITERAL		{ $$ = createAST(0, "STR_LITERAL", {}, $1); }
	| FUNC_NAME				{ $$ = createAST(0, "FN_NAME"); }
	;

postfix_expression
	: primary_expression										
	| postfix_expression '(' ')'								{ $$ = createAST(1, "fn_call", {$1}); }
	| postfix_expression '(' argument_expression_list ')' 		{ $$ = createAST(1, "fn_call", {$1, $3}); }
	| postfix_expression INC_OP									{ AST* inc = createAST(0, "INC_OP"); $$ = createAST(1, "postfix_expression", {$1, inc}); }
	| postfix_expression DEC_OP									{ AST* dec = createAST(0, "DEC_OP"); $$ = createAST(1, "postfix_expression", {$1, dec}); }
	;

argument_expression_list
	: assignment_expression										{ $$ = createAST(3, "argument_expression_list", {$1}); }
	| argument_expression_list ',' assignment_expression		{ $$ = createAST(3, "argument_expression_list", {$1, $3}); }
	;

unary_expression
	: postfix_expression				
	| INC_OP unary_expression			{ AST* inc = createAST(0, "INC_OP"); $$ = createAST(1, "unary_expression", {inc, $2}); }
	| DEC_OP unary_expression			{ AST* dec = createAST(0, "DEC_OP"); $$ = createAST(1, "unary_expression", {dec, $2}); }
	| unary_operator unary_expression	{ $$ = createAST(1, "unary expression", {$1, $2}); }
	;

unary_operator
	: '&'	{$$ = createAST(0, "&");}
	| '*'	{$$ = createAST(0, "*");}
	| '+'	{$$ = createAST(0, "+");}
	| '-'	{$$ = createAST(0, "-");}
	| '~'	{$$ = createAST(0, "~");}
	| '!'	{$$ = createAST(0, "!");}
	;

multiplicative_expression
	: unary_expression
	| multiplicative_expression '*' unary_expression		{ $$ = createAST(1, "*", {$1, $3}); }
	| multiplicative_expression '/' unary_expression		{ $$ = createAST(1, "/", {$1, $3}); }
	| multiplicative_expression '%' unary_expression		{ $$ = createAST(1, "%", {$1, $3}); }
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression			{ $$ = createAST(1, "+", {$1, $3}); }
	| additive_expression '-' multiplicative_expression			{ $$ = createAST(1, "-", {$1, $3}); }
	;

shift_expression
	: additive_expression
	| shift_expression LEFT_OP additive_expression				{ $$ = createAST(1, "LEFT_OP", {$1, $3}); }
	| shift_expression RIGHT_OP additive_expression				{ $$ = createAST(1, "RIGHT_OP", {$1, $3}); }
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression				{ $$ = createAST(1, "<", {$1, $3}); }
	| relational_expression '>' shift_expression				{ $$ = createAST(1, ">", {$1, $3}); }
	| relational_expression LE_OP shift_expression				{ $$ = createAST(1, "LE_OP", {$1, $3}); }
	| relational_expression GE_OP shift_expression				{ $$ = createAST(1, "GE_OP", {$1, $3}); }
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression			{ $$ = createAST(1, "EQ_OP", {$1, $3}); }
	| equality_expression NE_OP relational_expression			{ $$ = createAST(1, "NE_OP", {$1, $3}); }
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression					{ $$ = createAST(1, "&", {$1, $3}); }
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression				{ $$ = createAST(1, "^", {$1, $3}); }
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression		{ $$ = createAST(1, "|", {$1, $3}); }
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND_OP inclusive_or_expression		{ $$ = createAST(1, "AND_OP", {$1, $3}); }
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression		{ $$ = createAST(1, "OR_OP", {$1, $3}); }
	;

conditional_expression
	: logical_or_expression
	;

assignment_expression
	: conditional_expression
	| unary_expression '=' assignment_expression 		{ $$ = createAST(1, "assignment", {$1, $3}); }
	;

expression
	: assignment_expression					
	| expression ',' assignment_expression 	{ $$ = createAST(1, "expression", {$1, $3}); }
	;

declaration
	: declaration_specifiers ';'						{ $$ = createAST(1, "declaration", {$1}); }
	| declaration_specifiers init_declarator_list ';'	{ $$ = createAST(1, "declaration", {$1, $2}); }
	;

declaration_specifiers							
	: type_specifier declaration_specifiers				{ $$ = createAST(1, "declaration_specifiers", {$1, $2}); }
	| type_specifier									
	| type_qualifier declaration_specifiers				{ $$ = createAST(1, "declaration_specifiers", {$1, $2}); }
	| type_qualifier									
	;

init_declarator_list
	: init_declarator								
	| init_declarator_list ',' init_declarator		{ $$ = createAST(3, "init_declarator_list", {$1, $3}); }
	;

init_declarator
	: declarator '=' initializer				{ $$ = createAST(1, "=", {$1, $3}); }
	| declarator
	;

type_specifier
	: VOID		{$$ = createAST(0, "VOID");}
	| CHAR		{$$ = createAST(0, "CHAR");}
	| SHORT		{$$ = createAST(0, "SHORT");}
	| INT		{$$ = createAST(0, "INT");}
	| LONG		{$$ = createAST(0, "LONG");}
	| FLOAT		{$$ = createAST(0, "FLOAT");}
	| DOUBLE	{$$ = createAST(0, "DOUBLE");}
	| SIGNED	{$$ = createAST(0, "SIGNED");}
	| UNSIGNED	{$$ = createAST(0, "UNSIGNED");}
	| BOOL		{$$ = createAST(0, "BOOL");}
	;

type_qualifier
	: CONST			{ $$ = createAST(0, "CONST"); }
	;

declarator
	: pointer direct_declarator		{ $$ = createAST(0, "declarator", {$1, $2}); }
	| direct_declarator
	;

direct_declarator
	: IDENTIFIER																	{ $$ = createAST(0, "ID", {}, $1); }
	| '(' declarator ')'															{ $$ = $2; }
	| direct_declarator '(' parameter_type_list ')'									{ $$ = createAST(1, "direct_declarator", {$1, $3}); }
	| direct_declarator '(' ')'
	;

pointer
	: '*' type_qualifier_list pointer		{ AST* star = createAST(0, "*"); $$ = createAST(1, "pointer", {star, $2, $3}); }
	| '*' type_qualifier_list				{ AST* star = createAST(0, "*"); $$ = createAST(1, "pointer", {star, $2}); }
	| '*' pointer							{ AST* star = createAST(0, "*"); $$ = createAST(1, "pointer", {star, $2}); }
	| '*'									{ $$ = createAST(0, "*"); }
	;

type_qualifier_list
	: type_qualifier						
	| type_qualifier_list type_qualifier	{ $$ = createAST(3, "type_qualifier_list", {$1, $2}); }
	;


parameter_type_list
	: parameter_list ',' ELLIPSIS			{ AST* temp = createAST(0, "ELLIPSIS"); push($1, {temp}); $$ = $1; }
	| parameter_list
	;

parameter_list
	: parameter_declaration							
	| parameter_list ',' parameter_declaration		{ $$ = createAST(3, "parameter_list", {$1, $3}); }
	;

parameter_declaration
	: declaration_specifiers declarator				{ $$ = createAST(1, "parameter_declaration", {$1, $2}); }
	| declaration_specifiers
	;

initializer
	: '{' initializer_list '}'			{ $$ = $2; }
	| '{' initializer_list ',' '}'		{ $$ = $2; }
	| assignment_expression				{ $$ = $1; }
	;

initializer_list	
	: initializer
	| initializer_list ',' initializer					{ $$ = createAST(3, "initializer_list", {$1, $3}); }
	;

statement
	: labeled_statement
	| compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

labeled_statement
	: IDENTIFIER ':' statement						{ AST* temp = createAST(0, "ID", {}, $1); $$ = createAST(1, "labeled_statement", {temp, $3}); }
	;

compound_statement
	: '{' '}'							{ $$ = createAST(4, "empty_compound_statement"); }
	| '{'  block_item_list '}'			{ $$ = createAST(1, "compound_statement", {$2}); }
	;

block_item_list
	: block_item						
	| block_item_list block_item		{ $$ = createAST(3, "block_item_list", {$1, $2}); }
	;

block_item
	: declaration
	| statement
	;

expression_statement
	: ';'					{ $$ = createAST(0, ";"); }
	| expression ';'		{ $$ = $1; }
	;

selection_statement
	: IF '(' expression ')' statement ELSE statement		{ $$ = createAST(1, "ifte", {$3, $5, $7}); }
	| IF '(' expression ')' statement						{ $$ = createAST(1, "ifte", {$3, $5}); }
	;

iteration_statement
	: WHILE '(' expression ')' statement												{ $$ = createAST(1, "while", {$3, $5}); }
	;

jump_statement
	: GOTO IDENTIFIER ';'			{ AST* temp1 = createAST(0, "GOTO"); AST* temp2 = createAST(0, "ID", {}, $2); $$ = createAST(1, "jump", {temp1, temp2});}
	| CONTINUE ';'					{ AST* temp1 = createAST(0, "CONTINUE"); $$ = createAST(1, "jump", {temp1});}
	| BREAK ';'						{ AST* temp1 = createAST(0, "BREAK"); $$ = createAST(1, "jump", {temp1});}
	| RETURN ';'					{ AST* temp1 = createAST(0, "RETURN"); $$ = createAST(1, "jump", {temp1});}
	| RETURN expression ';'			{ AST* temp1 = createAST(0, "RETURN"); $$ = createAST(1, "jump", {temp1, $2});}
	;

new_start
	: translation_unit		{ ast_root = $1; $$ = $1; }
	;

translation_unit
	: external_declaration						{ $$ = createAST(1, "PROGRAM", {$1}); }
	| translation_unit external_declaration		{ AST* root = $1; push(root, {$2}); $$ = root; }
	;

external_declaration
	: function_definition
	| declaration
	;

function_definition
	: declaration_specifiers declarator compound_statement						{ $$ = createAST(1, "FUNC", {$1, $2, $3}); }
	;

%%
#include <stdio.h>

void yyerror(const char *s)
{
	fflush(stdout);
	fprintf(stderr, "*** %s\n", s);
}
