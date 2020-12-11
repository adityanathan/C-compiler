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
%token	<s> TYPEDEF_NAME ENUMERATION_CONSTANT

%token	<s> TYPEDEF EXTERN STATIC AUTO REGISTER INLINE
%token	<s> CONST RESTRICT VOLATILE
%token	<s> BOOL CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE VOID
%token	<s> COMPLEX IMAGINARY 
%token	<s> STRUCT UNION ENUM ELLIPSIS

%token	<s> CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%token	<s> ALIGNAS ALIGNOF ATOMIC GENERIC NORETURN STATIC_ASSERT THREAD_LOCAL

%type <a> primary_expression constant enumeration_constant string generic_selection
%type <a> generic_assoc_list generic_association postfix_expression
%type <a> argument_expression_list unary_expression unary_operator cast_expression multiplicative_expression
%type <a> additive_expression shift_expression relational_expression equality_expression and_expression
%type <a> exclusive_or_expression inclusive_or_expression logical_and_expression logical_or_expression
%type <a> conditional_expression assignment_expression assignment_operator expression constant_expression
%type <a> declaration declaration_specifiers init_declarator_list init_declarator storage_class_specifier
%type <a> type_specifier struct_or_union_specifier struct_or_union struct_declaration_list struct_declaration
%type <a> specifier_qualifier_list struct_declarator_list struct_declarator enum_specifier enumerator_list
%type <a> enumerator atomic_type_specifier type_qualifier function_specifier alignment_specifier
%type <a> declarator direct_declarator pointer type_qualifier_list parameter_type_list parameter_list
%type <a> parameter_declaration identifier_list type_name abstract_declarator direct_abstract_declarator
%type <a> initializer initializer_list designation designator_list designator static_assert_declaration statement
%type <a> labeled_statement compound_statement block_item_list block_item expression_statement selection_statement
%type <a> iteration_statement jump_statement new_start translation_unit external_declaration function_definition declaration_list

// %start translation_unit
%start new_start
%%

primary_expression
	: IDENTIFIER 	{ $$ = createAST(0, "ID", {}, $1); }
	| constant
	| string
	| '(' expression ')'		{ $$ = $2; }
	| generic_selection
	;

constant
	: I_CONSTANT		{ $$ = createAST(0, "I_CONSTANT", {}, $1); }		/* includes character_constant */
	| F_CONSTANT		{ $$ = createAST(0, "F_CONSTANT", {}, $1); }
	| ENUMERATION_CONSTANT			{ $$ = createAST(0, "ENUM_CONSTANT", {}, $1); }		/* after it has been defined as such */
	;

enumeration_constant		/* before it has been defined as such */
	: IDENTIFIER		{ $$ = createAST(0, "ID", {}, $1); }
	;

string
	: STRING_LITERAL		{ $$ = createAST(0, "STR_LITERAL", {}, $1); }
	| FUNC_NAME				{ $$ = createAST(0, "FN_NAME"); }
	;

generic_selection
	: GENERIC '(' assignment_expression ',' generic_assoc_list ')'		{ AST* g = createAST(0, "GENERIC"); $$ = createAST(1, "generic_selection", {g, $3, $5}); }
	;

generic_assoc_list
	: generic_association								
	| generic_assoc_list ',' generic_association		{ $$ = createAST(1, "generic_assoc_list", {$1, $3}); }
	;

generic_association
	: type_name ':' assignment_expression		{ $$ = createAST(1, "generic_association", {$1, $3}); }
	| DEFAULT ':' assignment_expression			{ AST* d = createAST(0, "DEFAULT"); $$ = createAST(1, "generic_association", {d, $3}); }
	;

postfix_expression
	: primary_expression										
	| postfix_expression '[' expression ']'						{ $$ = createAST(1, "postfix_expression", {$1, $3}); }
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')' 		{ $$ = createAST(1, "postfix_expression", {$1, $3}); }
	| postfix_expression '.' IDENTIFIER							{ AST* id = createAST(0, "ID", {}, $3); $$ = createAST(1, "postfix_expression", {$1, id}); }
	| postfix_expression PTR_OP IDENTIFIER						{ AST* id = createAST(0, "ID", {}, $3); AST* ptrop = createAST(0, "PTR_OP"); $$ = createAST(1, "postfix_expression", {$1, ptrop, id}); }
	| postfix_expression INC_OP									{ AST* inc = createAST(0, "INC_OP"); $$ = createAST(1, "postfix_expression", {$1, inc}); }
	| postfix_expression DEC_OP									{ AST* dec = createAST(0, "DEC_OP"); $$ = createAST(1, "postfix_expression", {$1, dec}); }
	| '(' type_name ')' '{' initializer_list '}'				{ $$ = createAST(3, "postfix_expression", {$2, $5}); }
	| '(' type_name ')' '{' initializer_list ',' '}'			{ $$ = createAST(3, "postfix_expression", {$2, $5}); }
	;

argument_expression_list
	: assignment_expression										
	| argument_expression_list ',' assignment_expression		{ $$ = createAST(1, "argument_expression_list", {$1, $3}); }
	;

unary_expression
	: postfix_expression				
	| INC_OP unary_expression			{ AST* inc = createAST(0, "INC_OP"); $$ = createAST(1, "unary_expression", {inc, $2}); }
	| DEC_OP unary_expression			{ AST* dec = createAST(0, "DEC_OP"); $$ = createAST(1, "unary_expression", {dec, $2}); }
	| unary_operator cast_expression	{ $$ = createAST(1, "unary_expression", {$1, $2}); }
	| SIZEOF unary_expression			{ AST* sz = createAST(0, "SIZEOF"); $$ = createAST(1, "unary_expression", {sz, $2}); }
	| SIZEOF '(' type_name ')'			{ AST* sz = createAST(0, "SIZEOF"); $$ = createAST(1, "unary_expression", {sz, $3}); }
	| ALIGNOF '(' type_name ')'			{ AST* al = createAST(0, "ALIGNOF"); $$ = createAST(1, "unary_expression", {al, $3}); }
	;

unary_operator
	: '&'	{$$ = createAST(0, "&");}
	| '*'	{$$ = createAST(0, "*");}
	| '+'	{$$ = createAST(0, "+");}
	| '-'	{$$ = createAST(0, "-");}
	| '~'	{$$ = createAST(0, "~");}
	| '!'	{$$ = createAST(0, "!");}
	;

cast_expression
	: unary_expression						
	| '(' type_name ')' cast_expression		{ $$ = createAST(1, "cast_expression", {$2, $4}); }
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression '*' cast_expression		{ $$ = createAST(1, "*", {$1, $3}); }
	| multiplicative_expression '/' cast_expression		{ $$ = createAST(1, "/", {$1, $3}); }
	| multiplicative_expression '%' cast_expression		{ $$ = createAST(1, "%", {$1, $3}); }
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
	| logical_or_expression '?' expression ':' conditional_expression			{ $$ = createAST(1, "?:", {$1, $3, $5}); }
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression 		{ $$ = createAST(1, $2->node_string, {$1, $3}); }
	;

assignment_operator
	: '=' 			{$$ = createAST(0, "=");}
	| MUL_ASSIGN 	{$$ = createAST(0, "MUL_ASSIGN");}
	| DIV_ASSIGN	{$$ = createAST(0, "DIV_ASSIGN");}
	| MOD_ASSIGN	{$$ = createAST(0, "MOD_ASSIGN");}
	| ADD_ASSIGN	{$$ = createAST(0, "ADD_ASSIGN");}
	| SUB_ASSIGN	{$$ = createAST(0, "SUB_ASSIGN");}
	| LEFT_ASSIGN	{$$ = createAST(0, "LEFT_ASSIGN");}
	| RIGHT_ASSIGN	{$$ = createAST(0, "RIGHT_ASSIGN");}
	| AND_ASSIGN	{$$ = createAST(0, "AND_ASSIGN");}
	| XOR_ASSIGN	{$$ = createAST(0, "XOR_ASSIGN");}
	| OR_ASSIGN		{$$ = createAST(0, "OR_ASSIGN");}
	;

expression
	: assignment_expression					
	| expression ',' assignment_expression 	{ $$ = createAST(1, "expression", {$1, $3}); }
	;

constant_expression
	: conditional_expression	/* with constraints */
	;

declaration
	: declaration_specifiers ';'						{ $$ = createAST(1, "declaration", {$1}); }
	| declaration_specifiers init_declarator_list ';'	{ $$ = createAST(1, "declaration", {$1, $2}); }
	| static_assert_declaration							{ $$ = createAST(1, "declaration", {$1}); }
	;

declaration_specifiers
	: storage_class_specifier declaration_specifiers	{ $$ = createAST(1, "declaration_specifiers", {$1, $2}); }
	| storage_class_specifier							
	| type_specifier declaration_specifiers				{ $$ = createAST(1, "declaration_specifiers", {$1, $2}); }
	| type_specifier									
	| type_qualifier declaration_specifiers				{ $$ = createAST(1, "declaration_specifiers", {$1, $2}); }
	| type_qualifier									
	| function_specifier declaration_specifiers			{ $$ = createAST(1, "declaration_specifiers", {$1, $2}); }
	| function_specifier								
	| alignment_specifier declaration_specifiers		{ $$ = createAST(1, "declaration_specifiers", {$1, $2}); }
	| alignment_specifier								
	;

init_declarator_list
	: init_declarator								
	| init_declarator_list ',' init_declarator		{ $$ = createAST(1, "init_declarator_list", {$1, $3}); }
	;

init_declarator
	: declarator '=' initializer				{ $$ = createAST(1, "=", {$1, $3}); }
	| declarator
	;

storage_class_specifier
	: TYPEDEF		{$$ = createAST(0, "TYPEDEF");}		/* identifiers must be flagged as TYPEDEF_NAME */
	| EXTERN		{$$ = createAST(0, "EXTERN");}
	| STATIC		{$$ = createAST(0, "STATIC");}
	| THREAD_LOCAL	{$$ = createAST(0, "THREAD_LOCAL");}
	| AUTO			{$$ = createAST(0, "AUTO");}
	| REGISTER		{$$ = createAST(0, "REGISTER");}
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
	| COMPLEX	{$$ = createAST(0, "COMPLEX");}
	| IMAGINARY	  	 {$$ = createAST(0, "IMAGINARY");}		/* non-mandated extension */
	| atomic_type_specifier
	| struct_or_union_specifier
	| enum_specifier
	| TYPEDEF_NAME		/* after it has been defined as such */ {$$ = createAST(0, "TYPEDEF_NAME", {}, $1);}
	;

struct_or_union_specifier
	: struct_or_union '{' struct_declaration_list '}'				{ $$ = createAST(1, "struct_or_union_specifier", {$1, $3}); }
	| struct_or_union IDENTIFIER '{' struct_declaration_list '}'	{ AST* tmp = createAST(0, "ID", {}, $2); $$ = createAST(1, "struct_or_union_specifier", {$1, tmp, $4}); }
	| struct_or_union IDENTIFIER									{ AST* tmp = createAST(0, "ID", {}, $2); $$ = createAST(1, "struct_or_union_specifier", {$1, tmp}); }
	;

struct_or_union
	: STRUCT	{$$ = createAST(0, "STRUCT");}
	| UNION		{$$ = createAST(0, "UNION");}
	;

struct_declaration_list
	: struct_declaration							
	| struct_declaration_list struct_declaration 	{ $$ = createAST(1, "struct_declaration_list", {$1, $2}); }
	;

struct_declaration
	: specifier_qualifier_list ';'								{ $$ = createAST(1, "struct_declaration", {$1}); }		/* for anonymous struct/union */
	| specifier_qualifier_list struct_declarator_list ';'		{ $$ = createAST(1, "struct_declaration", {$1, $2}); }
	| static_assert_declaration									{ $$ = createAST(1, "struct_declaration", {$1}); }
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list		{ $$ = createAST(1, "specifier_qualifier_list", {$1, $2}); }
	| type_specifier								
	| type_qualifier specifier_qualifier_list		{ $$ = createAST(1, "specifier_qualifier_list", {$1, $2}); }
	| type_qualifier								
	;

struct_declarator_list
	: struct_declarator								
	| struct_declarator_list ',' struct_declarator	{ $$ = createAST(1, "struct_declarator_list", {$1, $3}); }
	;

struct_declarator
	: ':' constant_expression				{ $$ = createAST(1, ":", {$2}); }
	| declarator ':' constant_expression	{ $$ = createAST(1, ":", {$1, $3}); }
	| declarator
	;

enum_specifier
	: ENUM '{' enumerator_list '}'					{ AST* temp = createAST(0, "ENUM"); $$ = createAST(1, "enum_specifier", {temp, $3}); }
	| ENUM '{' enumerator_list ',' '}'				{ AST* temp = createAST(0, "ENUM"); $$ = createAST(1, "enum_specifier", {temp, $3}); }
	| ENUM IDENTIFIER '{' enumerator_list '}'		{ AST* temp = createAST(0, "ENUM"); AST* temp2 = createAST(0, "ID", {}, $2); $$ = createAST(1, "enum_specifier", {temp, temp2, $4}); }
	| ENUM IDENTIFIER '{' enumerator_list ',' '}'	{ AST* temp = createAST(0, "ENUM"); AST* temp2 = createAST(0, "ID", {}, $2); $$ = createAST(1, "enum_specifier", {temp, temp2, $4}); }
	| ENUM IDENTIFIER								{ AST* temp = createAST(0, "ENUM"); AST* temp2 = createAST(0, "ID", {}, $2); $$ = createAST(1, "enum_specifier", {temp, temp2}); }
	;

enumerator_list
	: enumerator							
	| enumerator_list ',' enumerator		{ $$ = createAST(1, "enumerator_list", {$1, $3}); }
	;

enumerator	/* identifiers must be flagged as ENUMERATION_CONSTANT */
	: enumeration_constant '=' constant_expression		{ $$ = createAST(1, "=", {$1, $3}); }
	| enumeration_constant
	;

atomic_type_specifier
	: ATOMIC '(' type_name ')'			{ AST* temp = createAST(0, "ATOMIC"); $$ = createAST(1, "atomic_type_specifier", {temp, $3}); }
	;

type_qualifier
	: CONST			{ $$ = createAST(0, "CONST"); }
	| RESTRICT		{ $$ = createAST(0, "RESTRICT"); }
	| VOLATILE		{ $$ = createAST(0, "VOLATILE"); }
	| ATOMIC		{ $$ = createAST(0, "ATOMIC"); }
	;

function_specifier
	: INLINE		{ $$ = createAST(0, "INLINE"); }
	| NORETURN		{ $$ = createAST(0, "NORETURN"); }
	;

alignment_specifier
	: ALIGNAS '(' type_name ')'				{ AST* temp = createAST(0, "ALIGNAS"); $$ = createAST(1, "alignment_specifier", {temp, $3}); }
	| ALIGNAS '(' constant_expression ')'	{ AST* temp = createAST(0, "ALIGNAS"); $$ = createAST(1, "alignment_specifier", {temp, $3}); }
	;

declarator
	: pointer direct_declarator		{ $$ = createAST(0, "declarator", {$1, $2}); }
	| direct_declarator
	;

direct_declarator
	: IDENTIFIER																	{ $$ = createAST(0, "ID", {}, $1); }
	| '(' declarator ')'															{ $$ = $2; }
	| direct_declarator '[' ']'														
	| direct_declarator '[' '*' ']'													{ AST* temp = createAST(0, "*"); $$ = createAST(1, "direct_declarator", {$1, temp}); }
	| direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'	{ AST* temp = createAST(0, "STATIC"); $$ = createAST(1, "direct_declarator", {$1, temp, $4, $5}); }
	| direct_declarator '[' STATIC assignment_expression ']'						{ AST* temp = createAST(0, "STATIC"); $$ = createAST(1, "direct_declarator", {$1, temp, $4}); }
	| direct_declarator '[' type_qualifier_list '*' ']'								{ AST* temp = createAST(0, "*"); $$ = createAST(1, "direct_declarator", {$1, $3, temp}); }
	| direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'	{ AST* temp = createAST(0, "STATIC"); $$ = createAST(1, "direct_declarator", {$1, $3, temp, $5}); }
	| direct_declarator '[' type_qualifier_list assignment_expression ']'			{ $$ = createAST(1, "direct_declarator", {$1, $3, $4}); }
	| direct_declarator '[' type_qualifier_list ']'									{ $$ = createAST(1, "direct_declarator", {$1, $3}); }
	| direct_declarator '[' assignment_expression ']'								{ $$ = createAST(1, "direct_declarator", {$1, $3}); }
	| direct_declarator '(' parameter_type_list ')'									{ $$ = createAST(1, "direct_declarator", {$1, $3}); }
	| direct_declarator '(' ')'
	| direct_declarator '(' identifier_list ')'										{ $$ = createAST(1, "direct_declarator", {$1, $3}); }
	;

pointer
	: '*' type_qualifier_list pointer		{ AST* star = createAST(0, "*"); $$ = createAST(1, "pointer", {star, $2, $3}); }
	| '*' type_qualifier_list				{ AST* star = createAST(0, "*"); $$ = createAST(1, "pointer", {star, $2}); }
	| '*' pointer							{ AST* star = createAST(0, "*"); $$ = createAST(1, "pointer", {star, $2}); }
	| '*'									{ $$ = createAST(0, "*"); }
	;

type_qualifier_list
	: type_qualifier						
	| type_qualifier_list type_qualifier	{ $$ = createAST(1, "type_qualifier_list", {$1, $2}); }
	;


parameter_type_list
	: parameter_list ',' ELLIPSIS			{ AST* temp = createAST(0, "ELLIPSIS"); $$ = createAST(1, ",", {$1, temp}); }
	| parameter_list
	;

parameter_list
	: parameter_declaration							
	| parameter_list ',' parameter_declaration		{ $$ = createAST(1, "parameter_list", {$1, $3}); }
	;

parameter_declaration
	: declaration_specifiers declarator				{ $$ = createAST(1, "parameter_declaration", {$1, $2}); }
	| declaration_specifiers abstract_declarator	{ $$ = createAST(1, "parameter_declaration", {$1, $2}); }
	| declaration_specifiers
	;

identifier_list
	: IDENTIFIER								{ $$ = createAST(0, "ID", {}, $1); }
	| identifier_list ',' IDENTIFIER			{ AST* temp = createAST(0, "ID", {}, $3); $$ = createAST(1, "identifier_list", {$1, temp}); }
	;

type_name
	: specifier_qualifier_list abstract_declarator		{ $$ = createAST(1, "type_name", {$1, $2}); }
	| specifier_qualifier_list							{ $$ = createAST(1, "type_name", {$1}); }
	;

abstract_declarator
	: pointer direct_abstract_declarator			{ $$ = createAST(1, "abstract_declarator", {$1, $2}); }
	| pointer
	| direct_abstract_declarator
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'																{ $$ = $2; }
	| '[' ']'																					{ $$ = createAST(4, "empty_direct_abstr_declarator"); }
	| '[' '*' ']'																				{ $$ = createAST(0, "*"); }
	| '[' STATIC type_qualifier_list assignment_expression ']'									{ AST* temp = createAST(0, "STATIC"); $$ = createAST(1, "direct_abstract_declarator", {temp, $3, $4}); }
	| '[' STATIC assignment_expression ']'														{ AST* temp = createAST(0, "STATIC"); $$ = createAST(1, "direct_abstract_declarator", {temp, $3}); }
	| '[' type_qualifier_list STATIC assignment_expression ']'									{ AST* temp = createAST(0, "STATIC"); $$ = createAST(1, "direct_abstract_declarator", {$2, temp, $4}); }
	| '[' type_qualifier_list assignment_expression ']'											{ $$ = createAST(1, "direct_abstract_declarator", {$2, $3}); }
	| '[' type_qualifier_list ']'																{ $$ = $2; }
	| '[' assignment_expression ']'																{ $$ = $2; }
	| direct_abstract_declarator '[' ']'														{ $$ = $1; }
	| direct_abstract_declarator '[' '*' ']'													{ AST* temp = createAST(0, "*"); $$ = createAST(1, "direct_abstract_declarator", {$1, temp}); }
	| direct_abstract_declarator '[' STATIC type_qualifier_list assignment_expression ']'		{ AST* temp = createAST(0, "STATIC"); $$ = createAST(1, "direct_abstract_declarator", {$1, temp, $4, $5}); }
	| direct_abstract_declarator '[' STATIC assignment_expression ']'							{ AST* temp = createAST(0, "STATIC"); $$ = createAST(1, "direct_abstract_declarator", {$1, temp, $4}); }
	| direct_abstract_declarator '[' type_qualifier_list assignment_expression ']'				{ $$ = createAST(1, "direct_abstract_declarator", {$1, $3, $4}); }
	| direct_abstract_declarator '[' type_qualifier_list STATIC assignment_expression ']'		{ AST* temp = createAST(0, "STATIC"); $$ = createAST(1, "direct_abstract_declarator", {$1, $3, temp, $5}); }
	| direct_abstract_declarator '[' type_qualifier_list ']'									{ $$ = createAST(1, "direct_abstract_declarator", {$1, $3}); }
	| direct_abstract_declarator '[' assignment_expression ']'									{ $$ = createAST(1, "direct_abstract_declarator", {$1, $3}); }
	| '(' ')'																					{ $$ = createAST(0, "empty_list"); }
	| '(' parameter_type_list ')'																{ $$ = $2; }
	| direct_abstract_declarator '(' ')'														{ $$ = $1; }
	| direct_abstract_declarator '(' parameter_type_list ')'									{ $$ = createAST(1, "direct_abstract_declarator", {$1, $3}); }
	;

initializer
	: '{' initializer_list '}'			{ $$ = $2; }
	| '{' initializer_list ',' '}'		{ $$ = $2; }
	| assignment_expression				{ $$ = $1; }
	;

initializer_list
	: designation initializer							
	| initializer										
	| initializer_list ',' designation initializer		{ $$ = createAST(1, "initializer_list", {$1, $3}); }
	| initializer_list ',' initializer					{ $$ = createAST(1, "initializer_list", {$1, $3}); }
	;

designation
	: designator_list '='		{ AST* temp = createAST(0, "="); $$ = createAST(1, "designation", {$1, temp}); }
	;

designator_list
	: designator						
	| designator_list designator		{ $$ = createAST(1, "designator_list", {$1, $2}); }
	;

designator
	: '[' constant_expression ']'		{ $$ = $2; }
	| '.' IDENTIFIER					{ AST* temp = createAST(0, "."); AST* temp2 = createAST(0, "ID", {}, $2); $$ = createAST(1, "designator", {temp, temp2}); }
	;

static_assert_declaration
	: STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';'		{ AST* temp1 = createAST(0, "STATIC_ASSERT"); AST* temp2 = createAST(0, "STRING_LITERAL", {}, $5); $$ = createAST(1, "static_assert_declaration", {temp1, $3, temp2}); }
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
	| CASE constant_expression ':' statement		{ AST* temp = createAST(0, "CASE"); $$ = createAST(1, "labeled_statement", {temp, $2, $4}); }
	| DEFAULT ':' statement							{ AST* temp = createAST(0, "DEFAULT"); $$ = createAST(1, "labeled_statement", {temp, $3}); }
	;

compound_statement
	: '{' '}'							{ $$ = createAST(4, "empty_compound_statement"); }
	| '{'  block_item_list '}'			{ $$ = $2; }
	;

block_item_list
	: block_item						
	| block_item_list block_item		{ $$ = createAST(1, "block_item_list", {$1, $2}); }
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
	| SWITCH '(' expression ')' statement					{ $$ = createAST(1, "switch", {$3, $5}); }
	;

iteration_statement
	: WHILE '(' expression ')' statement												{ $$ = createAST(1, "while", {$3, $5}); }
	| DO statement WHILE '(' expression ')' ';'											{ $$ = createAST(1, "do_while", {$2, $5}); }
	| FOR '(' expression_statement expression_statement ')' statement					{ $$ = createAST(1, "for", {$3, $4, $6}); }
	| FOR '(' expression_statement expression_statement expression ')' statement		{ $$ = createAST(1, "for", {$3, $4, $5, $7}); }
	| FOR '(' declaration expression_statement ')' statement							{ $$ = createAST(1, "for", {$3, $4, $6}); }
	| FOR '(' declaration expression_statement expression ')' statement					{ $$ = createAST(1, "for", {$3, $4, $5, $7}); }
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
	: declaration_specifiers declarator declaration_list compound_statement		{ $$ = createAST(1, "FUNC", {$1, $2, $3, $4}); }
	| declaration_specifiers declarator compound_statement						{ $$ = createAST(1, "FUNC", {$1, $2, $3}); }
	;

declaration_list
	: declaration						
	| declaration_list declaration			{ $$ = createAST(1, "declaration_list", {$1, $2}); }
	;

%%
#include <stdio.h>

void yyerror(const char *s)
{
	fflush(stdout);
	fprintf(stderr, "*** %s\n", s);
}
