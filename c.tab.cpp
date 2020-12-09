/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "c.y"

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


#line 90 "c.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_C_TAB_HPP_INCLUDED
# define YY_YY_C_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    I_CONSTANT = 259,
    F_CONSTANT = 260,
    STRING_LITERAL = 261,
    FUNC_NAME = 262,
    SIZEOF = 263,
    PTR_OP = 264,
    INC_OP = 265,
    DEC_OP = 266,
    LEFT_OP = 267,
    RIGHT_OP = 268,
    LE_OP = 269,
    GE_OP = 270,
    EQ_OP = 271,
    NE_OP = 272,
    AND_OP = 273,
    OR_OP = 274,
    MUL_ASSIGN = 275,
    DIV_ASSIGN = 276,
    MOD_ASSIGN = 277,
    ADD_ASSIGN = 278,
    SUB_ASSIGN = 279,
    LEFT_ASSIGN = 280,
    RIGHT_ASSIGN = 281,
    AND_ASSIGN = 282,
    XOR_ASSIGN = 283,
    OR_ASSIGN = 284,
    TYPEDEF_NAME = 285,
    TYPEDEF = 286,
    EXTERN = 287,
    STATIC = 288,
    AUTO = 289,
    REGISTER = 290,
    INLINE = 291,
    CONST = 292,
    RESTRICT = 293,
    VOLATILE = 294,
    BOOL = 295,
    CHAR = 296,
    SHORT = 297,
    INT = 298,
    LONG = 299,
    SIGNED = 300,
    UNSIGNED = 301,
    FLOAT = 302,
    DOUBLE = 303,
    VOID = 304,
    COMPLEX = 305,
    IMAGINARY = 306,
    STRUCT = 307,
    UNION = 308,
    ENUM = 309,
    ELLIPSIS = 310,
    CASE = 311,
    DEFAULT = 312,
    IF = 313,
    ELSE = 314,
    SWITCH = 315,
    WHILE = 316,
    DO = 317,
    FOR = 318,
    GOTO = 319,
    CONTINUE = 320,
    BREAK = 321,
    RETURN = 322,
    ALIGNAS = 323,
    ALIGNOF = 324,
    ATOMIC = 325,
    GENERIC = 326,
    NORETURN = 327,
    STATIC_ASSERT = 328,
    THREAD_LOCAL = 329
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 21 "c.y"

	AST* a;
	char* s;

#line 222 "c.tab.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_C_TAB_HPP_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  31
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   397

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  96
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  126
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  192

#define YYUNDEFTOK  2
#define YYMAXUTOK   329


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    83,     2,     2,     2,    85,    78,     2,
      75,    76,    79,    80,    77,    81,     2,    84,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    91,    93,
      86,    92,    87,    90,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    88,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    94,    89,    95,    82,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    59,    59,    60,    61,    62,    66,    67,    71,    72,
      73,    74,    75,    79,    80,    84,    85,    86,    87,    91,
      92,    93,    94,    95,    96,   100,   101,   102,   103,   107,
     108,   109,   113,   114,   115,   119,   120,   121,   122,   123,
     127,   128,   129,   133,   134,   138,   139,   143,   144,   148,
     149,   153,   154,   158,   159,   163,   164,   168,   169,   173,
     174,   178,   179,   180,   181,   185,   186,   190,   191,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   208,
     212,   213,   217,   218,   219,   220,   224,   225,   226,   227,
     231,   232,   237,   238,   242,   243,   247,   248,   252,   253,
     254,   255,   256,   257,   261,   265,   266,   270,   271,   275,
     276,   280,   281,   285,   286,   290,   294,   295,   296,   297,
     298,   302,   306,   307,   311,   312,   316
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "I_CONSTANT", "F_CONSTANT",
  "STRING_LITERAL", "FUNC_NAME", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP",
  "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP",
  "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN",
  "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN",
  "OR_ASSIGN", "TYPEDEF_NAME", "TYPEDEF", "EXTERN", "STATIC", "AUTO",
  "REGISTER", "INLINE", "CONST", "RESTRICT", "VOLATILE", "BOOL", "CHAR",
  "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "VOID",
  "COMPLEX", "IMAGINARY", "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE",
  "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "ALIGNAS", "ALIGNOF", "ATOMIC", "GENERIC",
  "NORETURN", "STATIC_ASSERT", "THREAD_LOCAL", "'('", "')'", "','", "'&'",
  "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'", "'^'",
  "'|'", "'?'", "':'", "'='", "';'", "'{'", "'}'", "$accept",
  "primary_expression", "constant", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "expression",
  "declaration", "declaration_specifiers", "init_declarator_list",
  "init_declarator", "type_specifier", "type_qualifier", "declarator",
  "direct_declarator", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "statement", "labeled_statement", "compound_statement",
  "block_item_list", "block_item", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "new_start", "translation_unit", "external_declaration",
  "function_definition", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,    40,    41,    44,    38,    42,
      43,    45,   126,    33,    47,    37,    60,    62,    94,   124,
      63,    58,    61,    59,   123,   125
};
# endif

#define YYPACT_NINF (-126)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     348,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,   267,  -126,  -126,     1,   348,  -126,  -126,
    -126,    30,   -25,  -126,   -63,  -126,  -126,  -126,   -43,   -40,
      -1,  -126,  -126,   -34,  -126,  -126,   -25,    30,  -126,    42,
      93,  -126,   307,   -40,  -126,  -126,  -126,  -126,   -42,  -126,
    -126,  -126,  -126,    42,    42,    42,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,    -4,     2,    42,   -22,   -49,    54,
      41,    52,   -17,   -18,    40,   101,   -15,  -126,  -126,    53,
      57,    75,   158,    84,    86,    33,  -126,  -126,  -126,   -59,
    -126,   267,  -126,  -126,  -126,   159,  -126,  -126,  -126,  -126,
    -126,  -126,   292,   113,   114,  -126,  -126,  -126,    70,  -126,
    -126,   245,    42,  -126,    42,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    42,   208,    42,    42,    97,  -126,  -126,  -126,
     -52,    42,  -126,  -126,  -126,  -126,  -126,   332,  -126,  -126,
      72,  -126,  -126,  -126,  -126,  -126,  -126,   -22,   -22,   -49,
     -49,    54,    54,    54,    54,    41,    41,    52,   -17,   -18,
      40,   101,   -67,  -126,    76,    79,  -126,  -126,  -126,  -126,
    -126,  -126,    42,    42,   208,   208,  -126,  -126,   133,  -126,
     208,  -126
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    79,    78,    70,    71,    72,    73,    76,    77,    74,
      75,    69,   125,     0,    62,    64,     0,   121,   122,   124,
      82,     0,    89,    59,     0,    65,    61,    63,    68,    81,
       0,     1,   123,     0,    90,    88,    87,     0,    60,     0,
       0,   126,     0,    80,    83,    91,    86,    66,    68,     2,
       6,     7,     4,     0,     0,     0,    19,    20,    21,    22,
      23,    24,     8,     3,    15,    25,     0,    29,    32,    35,
      40,    43,    45,    47,    49,    51,    53,    55,    67,     2,
       0,     0,     0,     0,     0,     0,   111,   105,    57,     0,
     109,     0,   110,    98,    99,     0,   107,   100,   101,   102,
     103,    85,    97,     0,    93,    94,    16,    17,     0,    11,
      12,     0,     0,    18,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   117,   118,   119,
       0,     0,   112,   106,   108,    96,    84,     0,     5,     9,
       0,    13,    56,    26,    27,    28,    25,    30,    31,    33,
      34,    38,    39,    36,    37,    41,    42,    44,    46,    48,
      50,    52,     0,   104,     0,     0,   116,   120,    58,    92,
      95,    10,     0,     0,     0,     0,    14,    54,   114,   115,
       0,   113
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -126,  -126,  -126,  -126,  -126,   -38,  -126,    49,    63,  -101,
      59,    66,    67,    65,    68,    78,  -126,    14,   -39,    46,
     -31,   -37,  -126,   173,    16,     4,    -2,   185,    -9,  -126,
    -126,  -126,    69,  -125,  -126,   193,  -126,   127,  -126,  -126,
    -126,  -126,  -126,  -126,   210,  -126
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    62,    63,    64,   150,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    88,    89,
      12,    13,    24,    25,    14,    15,    48,    29,    30,    36,
     103,   104,   105,    92,    93,    94,    95,    96,    97,    98,
      99,   100,    16,    17,    18,    19
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      78,    31,    20,    91,   131,   102,   109,   110,   173,    90,
     141,    28,     1,    35,    37,   106,   107,    27,   141,    33,
     161,   162,   163,   164,   183,   141,    34,    46,   113,    26,
      38,   117,   118,    20,   142,    42,    49,    50,    51,    52,
      45,   177,    44,    53,    54,    49,    50,    51,    52,    39,
      39,    40,    53,    54,    22,   121,   122,   114,    91,   188,
     189,   127,   115,   116,    90,   191,   119,   120,   125,   126,
     128,   111,   151,   152,    21,   132,   153,   154,   155,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   112,    27,    79,    50,    51,    52,
     145,   108,   178,    53,    54,    21,    27,    26,    55,    22,
     102,    56,    57,    58,    59,    60,    61,    55,    26,   130,
      56,    57,    58,    59,    60,    61,   139,   123,   124,   129,
       1,   140,   134,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,   186,   133,   156,   148,   141,   181,   182,
     135,    80,   184,   141,    81,   185,   141,    82,    83,    84,
      85,   136,    79,    50,    51,    52,   157,   158,    55,    53,
      54,    56,    57,    58,    59,    60,    61,   137,   172,   138,
     174,   175,   159,   160,   165,   166,    86,    40,    87,   146,
     176,   147,   190,   167,   169,   168,     1,   187,   170,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,   171,
      47,    79,    50,    51,    52,    43,   180,    80,    53,    54,
      81,    41,   144,    82,    83,    84,    85,    32,     0,     0,
       0,     0,     0,     0,    55,     0,     0,    56,    57,    58,
      59,    60,    61,     0,     0,     0,     0,     0,    49,    50,
      51,    52,    86,    40,   143,    53,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,     0,     0,    81,
      20,     0,    82,    83,    84,    85,     0,     0,     0,     0,
       0,     0,     0,    55,     0,     0,    56,    57,    58,    59,
      60,    61,     0,     0,     0,    20,     0,     0,     0,     0,
       0,    86,    40,     0,     1,     0,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,     0,     0,     0,
      55,   149,     0,    56,    57,    58,    59,    60,    61,     1,
       0,     0,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    21,     0,     1,     0,    22,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,     0,     0,     0,
      23,     0,     0,     0,     0,     0,     0,    21,     0,     1,
       0,    22,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,     0,   101,     0,     1,     0,   179,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11
};

static const yytype_int16 yycheck[] =
{
      39,     0,     3,    40,    19,    42,    10,    11,   133,    40,
      77,    13,    37,    22,    77,    53,    54,    13,    77,    21,
     121,   122,   123,   124,    91,    77,    22,    36,    66,    13,
      93,    80,    81,     3,    93,    75,     3,     4,     5,     6,
      36,    93,    76,    10,    11,     3,     4,     5,     6,    92,
      92,    94,    10,    11,    79,    14,    15,    79,    95,   184,
     185,    78,    84,    85,    95,   190,    12,    13,    16,    17,
      88,    75,   111,   112,    75,    90,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    92,    91,     3,     4,     5,     6,
     102,    55,   141,    10,    11,    75,   102,    91,    75,    79,
     147,    78,    79,    80,    81,    82,    83,    75,   102,    18,
      78,    79,    80,    81,    82,    83,    93,    86,    87,    89,
      37,    85,    75,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,   182,    91,   183,    76,    77,    76,    77,
      75,    58,    76,    77,    61,    76,    77,    64,    65,    66,
      67,     3,     3,     4,     5,     6,   117,   118,    75,    10,
      11,    78,    79,    80,    81,    82,    83,    93,   132,    93,
     134,   135,   119,   120,   125,   126,    93,    94,    95,    76,
      93,    77,    59,   127,   129,   128,    37,   183,   130,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,   131,
      37,     3,     4,     5,     6,    30,   147,    58,    10,    11,
      61,    28,    95,    64,    65,    66,    67,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    -1,    -1,    78,    79,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,    93,    94,    95,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    61,
       3,    -1,    64,    65,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    -1,    -1,    78,    79,    80,    81,
      82,    83,    -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,
      -1,    93,    94,    -1,    37,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      75,    76,    -1,    78,    79,    80,    81,    82,    83,    37,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    75,    -1,    37,    -1,    79,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      93,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    37,
      -1,    79,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    76,    -1,    37,    -1,    55,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    37,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,   116,   117,   120,   121,   138,   139,   140,   141,
       3,    75,    79,    93,   118,   119,   120,   121,   122,   123,
     124,     0,   140,   122,   121,   124,   125,    77,    93,    92,
      94,   131,    75,   123,    76,   121,   124,   119,   122,     3,
       4,     5,     6,    10,    11,    75,    78,    79,    80,    81,
      82,    83,    97,    98,    99,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,     3,
      58,    61,    64,    65,    66,    67,    93,    95,   114,   115,
     116,   117,   129,   130,   131,   132,   133,   134,   135,   136,
     137,    76,   117,   126,   127,   128,   101,   101,   115,    10,
      11,    75,    92,   101,    79,    84,    85,    80,    81,    12,
      13,    14,    15,    86,    87,    16,    17,    78,    88,    89,
      18,    19,    90,    91,    75,    75,     3,    93,    93,    93,
     115,    77,    93,    95,   133,   122,    76,    77,    76,    76,
     100,   114,   114,   101,   101,   101,   101,   103,   103,   104,
     104,   105,   105,   105,   105,   106,   106,   107,   108,   109,
     110,   111,   115,   129,   115,   115,    93,    93,   114,    55,
     128,    76,    77,    91,    76,    76,   114,   113,   129,   129,
      59,   129
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    96,    97,    97,    97,    97,    98,    98,    99,    99,
      99,    99,    99,   100,   100,   101,   101,   101,   101,   102,
     102,   102,   102,   102,   102,   103,   103,   103,   103,   104,
     104,   104,   105,   105,   105,   106,   106,   106,   106,   106,
     107,   107,   107,   108,   108,   109,   109,   110,   110,   111,
     111,   112,   112,   113,   113,   114,   114,   115,   115,   116,
     116,   117,   117,   117,   117,   118,   118,   119,   119,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   121,
     122,   122,   123,   123,   123,   123,   124,   124,   124,   124,
     125,   125,   126,   126,   127,   127,   128,   128,   129,   129,
     129,   129,   129,   129,   130,   131,   131,   132,   132,   133,
     133,   134,   134,   135,   135,   136,   137,   137,   137,   137,
     137,   138,   139,   139,   140,   140,   141
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     3,
       4,     2,     2,     1,     3,     1,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     5,     1,     3,     1,     3,     2,
       3,     2,     1,     2,     1,     1,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     3,     4,     3,     3,     2,     2,     1,
       1,     2,     3,     1,     1,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     3,     1,     2,     1,
       1,     1,     2,     7,     5,     5,     3,     2,     2,     2,
       3,     1,     1,     2,     1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 59 "c.y"
                        { (yyval.a) = createAST(0, "ID", {}, (yyvsp[0].s)); }
#line 1607 "c.tab.cpp"
    break;

  case 4:
#line 61 "c.y"
                                        { (yyval.a) = createAST(0, "STR_LITERAL", {}, (yyvsp[0].s)); }
#line 1613 "c.tab.cpp"
    break;

  case 5:
#line 62 "c.y"
                                        { (yyval.a) = (yyvsp[-1].a); }
#line 1619 "c.tab.cpp"
    break;

  case 6:
#line 66 "c.y"
                                { (yyval.a) = createAST(0, "I_CONSTANT", {}, (yyvsp[0].s)); }
#line 1625 "c.tab.cpp"
    break;

  case 7:
#line 67 "c.y"
                                { (yyval.a) = createAST(0, "F_CONSTANT", {}, (yyvsp[0].s)); }
#line 1631 "c.tab.cpp"
    break;

  case 9:
#line 72 "c.y"
                                                                                                { (yyval.a) = createAST(1, "fn_call", {(yyvsp[-2].a), createAST(3, "argument_expression")}); }
#line 1637 "c.tab.cpp"
    break;

  case 10:
#line 73 "c.y"
                                                                        { (yyval.a) = createAST(1, "fn_call", {(yyvsp[-3].a), (yyvsp[-1].a)}); }
#line 1643 "c.tab.cpp"
    break;

  case 11:
#line 74 "c.y"
                                                                                                        { AST* inc = createAST(0, "INC_OP"); (yyval.a) = createAST(1, "postfix_expression", {(yyvsp[-1].a), inc}); }
#line 1649 "c.tab.cpp"
    break;

  case 12:
#line 75 "c.y"
                                                                                                        { AST* dec = createAST(0, "DEC_OP"); (yyval.a) = createAST(1, "postfix_expression", {(yyvsp[-1].a), dec}); }
#line 1655 "c.tab.cpp"
    break;

  case 13:
#line 79 "c.y"
                                                                                                        { (yyval.a) = createAST(3, "argument_expression", {(yyvsp[0].a)}); }
#line 1661 "c.tab.cpp"
    break;

  case 14:
#line 80 "c.y"
                                                                        { push((yyvsp[-2].a), {(yyvsp[0].a)}); (yyval.a) = (yyvsp[-2].a); }
#line 1667 "c.tab.cpp"
    break;

  case 16:
#line 85 "c.y"
                                                        { AST* inc = createAST(0, "INC_OP"); (yyval.a) = createAST(1, "unary_expression", {inc, (yyvsp[0].a)}); }
#line 1673 "c.tab.cpp"
    break;

  case 17:
#line 86 "c.y"
                                                        { AST* dec = createAST(0, "DEC_OP"); (yyval.a) = createAST(1, "unary_expression", {dec, (yyvsp[0].a)}); }
#line 1679 "c.tab.cpp"
    break;

  case 18:
#line 87 "c.y"
                                                { (yyval.a) = createAST(1, "unary expression", {(yyvsp[-1].a), (yyvsp[0].a)}); }
#line 1685 "c.tab.cpp"
    break;

  case 19:
#line 91 "c.y"
                {(yyval.a) = createAST(0, "&");}
#line 1691 "c.tab.cpp"
    break;

  case 20:
#line 92 "c.y"
                {(yyval.a) = createAST(0, "*");}
#line 1697 "c.tab.cpp"
    break;

  case 21:
#line 93 "c.y"
                {(yyval.a) = createAST(0, "+");}
#line 1703 "c.tab.cpp"
    break;

  case 22:
#line 94 "c.y"
                {(yyval.a) = createAST(0, "-");}
#line 1709 "c.tab.cpp"
    break;

  case 23:
#line 95 "c.y"
                {(yyval.a) = createAST(0, "~");}
#line 1715 "c.tab.cpp"
    break;

  case 24:
#line 96 "c.y"
                {(yyval.a) = createAST(0, "!");}
#line 1721 "c.tab.cpp"
    break;

  case 26:
#line 101 "c.y"
                                                                        { (yyval.a) = createAST(1, "*", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1727 "c.tab.cpp"
    break;

  case 27:
#line 102 "c.y"
                                                                        { (yyval.a) = createAST(1, "/", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1733 "c.tab.cpp"
    break;

  case 28:
#line 103 "c.y"
                                                                        { (yyval.a) = createAST(1, "%", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1739 "c.tab.cpp"
    break;

  case 30:
#line 108 "c.y"
                                                                                { (yyval.a) = createAST(1, "+", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1745 "c.tab.cpp"
    break;

  case 31:
#line 109 "c.y"
                                                                                { (yyval.a) = createAST(1, "-", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1751 "c.tab.cpp"
    break;

  case 33:
#line 114 "c.y"
                                                                                { (yyval.a) = createAST(1, "LEFT_OP", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1757 "c.tab.cpp"
    break;

  case 34:
#line 115 "c.y"
                                                                                { (yyval.a) = createAST(1, "RIGHT_OP", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1763 "c.tab.cpp"
    break;

  case 36:
#line 120 "c.y"
                                                                                { (yyval.a) = createAST(1, "<", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1769 "c.tab.cpp"
    break;

  case 37:
#line 121 "c.y"
                                                                                { (yyval.a) = createAST(1, ">", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1775 "c.tab.cpp"
    break;

  case 38:
#line 122 "c.y"
                                                                                { (yyval.a) = createAST(1, "LE_OP", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1781 "c.tab.cpp"
    break;

  case 39:
#line 123 "c.y"
                                                                                { (yyval.a) = createAST(1, "GE_OP", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1787 "c.tab.cpp"
    break;

  case 41:
#line 128 "c.y"
                                                                                { (yyval.a) = createAST(1, "EQ_OP", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1793 "c.tab.cpp"
    break;

  case 42:
#line 129 "c.y"
                                                                                { (yyval.a) = createAST(1, "NE_OP", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1799 "c.tab.cpp"
    break;

  case 44:
#line 134 "c.y"
                                                                                        { (yyval.a) = createAST(1, "&", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1805 "c.tab.cpp"
    break;

  case 46:
#line 139 "c.y"
                                                                                { (yyval.a) = createAST(1, "^", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1811 "c.tab.cpp"
    break;

  case 48:
#line 144 "c.y"
                                                                        { (yyval.a) = createAST(1, "|", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1817 "c.tab.cpp"
    break;

  case 50:
#line 149 "c.y"
                                                                        { (yyval.a) = createAST(1, "AND_OP", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1823 "c.tab.cpp"
    break;

  case 52:
#line 154 "c.y"
                                                                        { (yyval.a) = createAST(1, "OR_OP", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1829 "c.tab.cpp"
    break;

  case 54:
#line 159 "c.y"
                                                                                                { (yyval.a) = createAST(1, "?:", {(yyvsp[-4].a), (yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1835 "c.tab.cpp"
    break;

  case 56:
#line 164 "c.y"
                                                                { (yyval.a) = createAST(1, "assignment", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1841 "c.tab.cpp"
    break;

  case 57:
#line 168 "c.y"
                                                                { (yyval.a) = createAST(3, "expression", {(yyvsp[0].a)}); }
#line 1847 "c.tab.cpp"
    break;

  case 58:
#line 169 "c.y"
                                                { push((yyvsp[-2].a), {(yyvsp[0].a)}); (yyval.a) = (yyvsp[-2].a); }
#line 1853 "c.tab.cpp"
    break;

  case 59:
#line 173 "c.y"
                                                                                { (yyval.a) = createAST(1, "declaration", {(yyvsp[-1].a)}); }
#line 1859 "c.tab.cpp"
    break;

  case 60:
#line 174 "c.y"
                                                                { (yyval.a) = createAST(1, "declaration", {(yyvsp[-2].a), (yyvsp[-1].a)}); }
#line 1865 "c.tab.cpp"
    break;

  case 61:
#line 178 "c.y"
                                                                        { push((yyvsp[-1].a), {(yyvsp[0].a)});  (yyval.a) = (yyvsp[-1].a); }
#line 1871 "c.tab.cpp"
    break;

  case 62:
#line 179 "c.y"
                                                                                                { (yyval.a) = createAST(3, "type", {(yyvsp[0].a)}); }
#line 1877 "c.tab.cpp"
    break;

  case 63:
#line 180 "c.y"
                                                                        { (yyval.a) = (yyvsp[-1].a); }
#line 1883 "c.tab.cpp"
    break;

  case 65:
#line 185 "c.y"
                                                                                                { (yyval.a) = createAST(3, "init_declarator", {(yyvsp[0].a)}); }
#line 1889 "c.tab.cpp"
    break;

  case 66:
#line 186 "c.y"
                                                                        { push((yyvsp[-2].a), {(yyvsp[0].a)});  (yyval.a) = (yyvsp[-2].a); }
#line 1895 "c.tab.cpp"
    break;

  case 67:
#line 190 "c.y"
                                                                { (yyval.a) = createAST(1, "=", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1901 "c.tab.cpp"
    break;

  case 69:
#line 195 "c.y"
                        {(yyval.a) = createAST(0, "VOID");}
#line 1907 "c.tab.cpp"
    break;

  case 70:
#line 196 "c.y"
                        {(yyval.a) = createAST(0, "CHAR");}
#line 1913 "c.tab.cpp"
    break;

  case 71:
#line 197 "c.y"
                        {(yyval.a) = createAST(0, "SHORT");}
#line 1919 "c.tab.cpp"
    break;

  case 72:
#line 198 "c.y"
                        {(yyval.a) = createAST(0, "INT");}
#line 1925 "c.tab.cpp"
    break;

  case 73:
#line 199 "c.y"
                        {(yyval.a) = createAST(0, "LONG");}
#line 1931 "c.tab.cpp"
    break;

  case 74:
#line 200 "c.y"
                        {(yyval.a) = createAST(0, "FLOAT");}
#line 1937 "c.tab.cpp"
    break;

  case 75:
#line 201 "c.y"
                        {(yyval.a) = createAST(0, "DOUBLE");}
#line 1943 "c.tab.cpp"
    break;

  case 76:
#line 202 "c.y"
                        {(yyval.a) = createAST(0, "SIGNED");}
#line 1949 "c.tab.cpp"
    break;

  case 77:
#line 203 "c.y"
                        {(yyval.a) = createAST(0, "UNSIGNED");}
#line 1955 "c.tab.cpp"
    break;

  case 78:
#line 204 "c.y"
                        {(yyval.a) = createAST(0, "BOOL");}
#line 1961 "c.tab.cpp"
    break;

  case 79:
#line 208 "c.y"
                                { (yyval.a) = createAST(0, "CONST"); }
#line 1967 "c.tab.cpp"
    break;

  case 80:
#line 212 "c.y"
                                                { (yyval.a) = createAST(0, "declarator", {(yyvsp[-1].a), (yyvsp[0].a)}); }
#line 1973 "c.tab.cpp"
    break;

  case 81:
#line 213 "c.y"
                                                        { (yyval.a) = createAST(0, "declarator", {createAST(0, "pointer"), (yyvsp[0].a)}); }
#line 1979 "c.tab.cpp"
    break;

  case 82:
#line 217 "c.y"
                                                                                                                                                        { (yyval.a) = createAST(0, "ID", {}, (yyvsp[0].s)); }
#line 1985 "c.tab.cpp"
    break;

  case 83:
#line 218 "c.y"
                                                                                                                                                { (yyval.a) = (yyvsp[-1].a); }
#line 1991 "c.tab.cpp"
    break;

  case 84:
#line 219 "c.y"
                                                                                                                        { (yyval.a) = createAST(1, "fn_declaration", {(yyvsp[-3].a), (yyvsp[-1].a)}); }
#line 1997 "c.tab.cpp"
    break;

  case 85:
#line 220 "c.y"
                                                                                                                                                { (yyval.a) = createAST(1, "fn_declaration", {(yyvsp[-2].a), createAST(3, "parameters")}); }
#line 2003 "c.tab.cpp"
    break;

  case 86:
#line 224 "c.y"
                                                        { AST* star = createAST(0, "*"); push((yyvsp[0].a), {star}); (yyval.a) = (yyvsp[0].a); }
#line 2009 "c.tab.cpp"
    break;

  case 87:
#line 225 "c.y"
                                                                { AST* star = createAST(0, "*"); (yyval.a) = createAST(0, "pointer", {star}); }
#line 2015 "c.tab.cpp"
    break;

  case 88:
#line 226 "c.y"
                                                                        { AST* star = createAST(0, "*"); push((yyvsp[0].a), {star}); (yyval.a) = (yyvsp[0].a); }
#line 2021 "c.tab.cpp"
    break;

  case 89:
#line 227 "c.y"
                                                                                { AST* star = createAST(0, "*"); (yyval.a) = createAST(0, "pointer", {star}); }
#line 2027 "c.tab.cpp"
    break;

  case 91:
#line 232 "c.y"
                                                { (yyval.a) = createAST(3, "type_qualifier_list", {(yyvsp[-1].a), (yyvsp[0].a)}); }
#line 2033 "c.tab.cpp"
    break;

  case 92:
#line 237 "c.y"
                                                        { AST* temp = createAST(0, "ELLIPSIS"); push((yyvsp[-2].a), {temp}); (yyval.a) = (yyvsp[-2].a); }
#line 2039 "c.tab.cpp"
    break;

  case 94:
#line 242 "c.y"
                                                                                { (yyval.a) = createAST(3, "parameters", {(yyvsp[0].a)}); }
#line 2045 "c.tab.cpp"
    break;

  case 95:
#line 243 "c.y"
                                                                { push((yyvsp[-2].a), {(yyvsp[0].a)}); (yyval.a) = (yyvsp[-2].a); }
#line 2051 "c.tab.cpp"
    break;

  case 96:
#line 247 "c.y"
                                                                        { (yyval.a) = createAST(1, "parameter_declaration", {(yyvsp[-1].a), (yyvsp[0].a)}); }
#line 2057 "c.tab.cpp"
    break;

  case 104:
#line 261 "c.y"
                                                                                { AST* temp = createAST(0, "ID", {}, (yyvsp[-2].s)); (yyval.a) = createAST(1, "labeled_statement", {temp, (yyvsp[0].a)}); }
#line 2063 "c.tab.cpp"
    break;

  case 105:
#line 265 "c.y"
                                                                        { (yyval.a) = createAST(3, "compound_statement"); }
#line 2069 "c.tab.cpp"
    break;

  case 106:
#line 266 "c.y"
                                                        { (yyval.a) = (yyvsp[-1].a); }
#line 2075 "c.tab.cpp"
    break;

  case 107:
#line 270 "c.y"
                                                                { (yyval.a) = createAST(3, "compound_statement", {(yyvsp[0].a)}); }
#line 2081 "c.tab.cpp"
    break;

  case 108:
#line 271 "c.y"
                                                { push((yyvsp[-1].a), {(yyvsp[0].a)}); (yyval.a) = (yyvsp[-1].a); }
#line 2087 "c.tab.cpp"
    break;

  case 111:
#line 280 "c.y"
                                                { (yyval.a) = createAST(0, ";"); }
#line 2093 "c.tab.cpp"
    break;

  case 112:
#line 281 "c.y"
                                        { (yyval.a) = (yyvsp[-1].a); }
#line 2099 "c.tab.cpp"
    break;

  case 113:
#line 285 "c.y"
                                                                        { (yyval.a) = createAST(1, "ifte", {(yyvsp[-4].a), (yyvsp[-2].a), (yyvsp[0].a)}); }
#line 2105 "c.tab.cpp"
    break;

  case 114:
#line 286 "c.y"
                                                                                        { (yyval.a) = createAST(1, "ifte", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 2111 "c.tab.cpp"
    break;

  case 115:
#line 290 "c.y"
                                                                                                                                        { (yyval.a) = createAST(1, "while", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 2117 "c.tab.cpp"
    break;

  case 116:
#line 294 "c.y"
                                                { AST* temp1 = createAST(0, "GOTO"); AST* temp2 = createAST(0, "ID", {}, (yyvsp[-1].s)); (yyval.a) = createAST(1, "jump", {temp1, temp2});}
#line 2123 "c.tab.cpp"
    break;

  case 117:
#line 295 "c.y"
                                                        { AST* temp1 = createAST(0, "CONTINUE"); (yyval.a) = createAST(1, "jump", {temp1});}
#line 2129 "c.tab.cpp"
    break;

  case 118:
#line 296 "c.y"
                                                                { AST* temp1 = createAST(0, "BREAK"); (yyval.a) = createAST(1, "jump", {temp1});}
#line 2135 "c.tab.cpp"
    break;

  case 119:
#line 297 "c.y"
                                                        { AST* temp1 = createAST(0, "RETURN"); (yyval.a) = createAST(1, "jump", {temp1});}
#line 2141 "c.tab.cpp"
    break;

  case 120:
#line 298 "c.y"
                                                { AST* temp1 = createAST(0, "RETURN"); (yyval.a) = createAST(1, "jump", {temp1, (yyvsp[-1].a)});}
#line 2147 "c.tab.cpp"
    break;

  case 121:
#line 302 "c.y"
                                        { ast_root = (yyvsp[0].a); (yyval.a) = (yyvsp[0].a); }
#line 2153 "c.tab.cpp"
    break;

  case 122:
#line 306 "c.y"
                                                                        { (yyval.a) = createAST(1, "PROGRAM", {(yyvsp[0].a)}); }
#line 2159 "c.tab.cpp"
    break;

  case 123:
#line 307 "c.y"
                                                        { AST* root = (yyvsp[-1].a); push(root, {(yyvsp[0].a)}); (yyval.a) = root; }
#line 2165 "c.tab.cpp"
    break;

  case 126:
#line 316 "c.y"
                                                                                                        { (yyval.a) = createAST(1, "FUNC", {(yyvsp[-2].a), (yyvsp[-1].a), (yyvsp[0].a)}); }
#line 2171 "c.tab.cpp"
    break;


#line 2175 "c.tab.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 319 "c.y"

#include <stdio.h>

void yyerror(const char *s)
{
	fflush(stdout);
	fprintf(stderr, "*** %s\n", s);
}
