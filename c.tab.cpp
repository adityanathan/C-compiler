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
#define YYLAST   399

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  95
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  132
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  198

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
       2,     2,     2,     2,     2,     2,     2,     2,    94,    91,
      86,    90,    87,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    88,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    92,    89,    93,    82,     2,     2,     2,
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
      76,    77,    78,    79,    80,    84,    85,    89,    90,    91,
      92,    96,    97,    98,    99,   100,   101,   105,   106,   107,
     108,   112,   113,   114,   118,   119,   120,   124,   125,   126,
     127,   128,   132,   133,   134,   138,   139,   143,   144,   148,
     149,   153,   154,   158,   159,   163,   167,   168,   172,   173,
     177,   178,   182,   183,   184,   185,   189,   190,   194,   195,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     212,   216,   217,   221,   222,   223,   224,   228,   229,   230,
     231,   235,   236,   241,   242,   246,   247,   251,   252,   256,
     257,   258,   262,   263,   267,   268,   269,   270,   271,   272,
     276,   280,   281,   285,   286,   290,   291,   295,   296,   300,
     301,   305,   309,   310,   311,   312,   313,   317,   321,   322,
     326,   327,   331
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
  "'|'", "'='", "';'", "'{'", "'}'", "':'", "$accept",
  "primary_expression", "constant", "string", "postfix_expression",
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
  "initializer", "initializer_list", "statement", "labeled_statement",
  "compound_statement", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "new_start", "translation_unit",
  "external_declaration", "function_definition", YY_NULLPTR
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
      61,    59,   123,   125,    58
};
# endif

#define YYPACT_NINF (-131)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     350,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,
    -131,  -131,  -131,     2,   350,   350,    18,   350,  -131,  -131,
    -131,    19,   -20,  -131,   -49,  -131,   -27,   -37,     7,  -131,
    -131,  -131,  -131,   -33,  -131,  -131,   -20,    19,  -131,    30,
       9,  -131,   292,   -37,  -131,  -131,  -131,  -131,   -69,  -131,
    -131,  -131,  -131,  -131,   303,   303,   303,  -131,  -131,  -131,
    -131,  -131,  -131,    30,  -131,  -131,  -131,    -4,   -45,   303,
      42,   -55,   124,    17,   129,   -30,   -28,   -25,    54,    78,
    -131,  -131,  -131,    12,    74,    77,   122,    38,    47,   221,
    -131,  -131,  -131,   -47,  -131,     2,  -131,  -131,  -131,   113,
    -131,  -131,  -131,  -131,  -131,  -131,    19,   105,   110,  -131,
    -131,  -131,    87,  -131,   -54,  -131,  -131,   245,   303,  -131,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   179,   303,
     303,   108,  -131,  -131,  -131,    -8,   303,  -131,  -131,  -131,
    -131,  -131,   305,  -131,   137,  -131,  -131,    89,  -131,  -131,
    -131,  -131,  -131,  -131,    42,    42,   -55,   -55,   124,   124,
     124,   124,    17,    17,   129,   -30,   -28,   -25,    54,  -131,
      91,    93,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,
     303,   179,   179,  -131,   141,  -131,   179,  -131
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    80,    79,    71,    72,    73,    74,    77,    78,    75,
      76,    70,   131,     0,    63,    65,     0,   127,   128,   130,
      83,     0,    90,    60,     0,    66,    69,    82,     0,    62,
      64,     1,   129,     0,    91,    89,    88,     0,    61,     0,
       0,   132,     0,    81,    84,    92,    87,    67,    69,     2,
       6,     7,     8,     9,     0,     0,     0,    21,    22,    23,
      24,    25,    26,     0,    10,     3,     4,    17,    27,     0,
      31,    34,    37,    42,    45,    47,    49,    51,    53,    55,
      56,   101,    68,     2,     0,     0,     0,     0,     0,     0,
     117,   111,    58,     0,   115,     0,   116,   104,   105,     0,
     113,   106,   107,   108,   109,    86,    98,     0,    94,    95,
      18,    19,     0,   102,     0,    13,    14,     0,     0,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   123,   124,   125,     0,     0,   118,   112,   114,
      97,    85,     0,     5,     0,    99,    11,     0,    15,    57,
      28,    29,    30,    27,    32,    33,    35,    36,    40,    41,
      38,    39,    43,    44,    46,    48,    50,    52,    54,   110,
       0,     0,   122,   126,    59,    93,    96,   100,   103,    12,
       0,     0,     0,    16,   120,   121,     0,   119
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -131,  -131,  -131,  -131,  -131,  -131,   153,  -131,    49,    50,
       5,    66,    68,    69,    67,    73,    76,  -131,  -131,   -39,
      -9,   -31,   -13,  -131,   173,  -131,    63,   -10,   183,    92,
    -131,  -131,  -131,    62,   -59,  -131,  -130,  -131,   195,  -131,
     134,  -131,  -131,  -131,  -131,  -131,  -131,   206,  -131
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    64,    65,    66,    67,   157,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    92,
      93,    12,    13,    24,    25,    14,    15,    48,    27,    28,
      36,   107,   108,   109,    82,   114,    96,    97,    98,    99,
     100,   101,   102,   103,   104,    16,    17,    18,    19
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      81,    29,    30,    26,   113,    20,   115,   116,   179,    94,
      20,    33,    83,    50,    51,    52,    53,     1,    31,    54,
      55,    39,    20,   154,    81,   123,   124,    95,    37,   106,
     146,   127,   128,    49,    50,    51,    52,    53,    42,   155,
      54,    55,    38,    44,   147,   118,     1,   112,   133,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    22,
     134,   194,   195,    39,   135,    40,   197,    84,    94,   146,
      85,   117,   136,    86,    87,    88,    89,    21,   158,   159,
     145,    22,    21,   183,    56,    34,    95,    57,    58,    59,
      60,    61,    62,    23,    21,   188,   150,   137,    22,    45,
      90,    40,    91,   129,   130,    56,   138,   184,    57,    58,
      59,    60,    61,    62,    35,    81,    83,    50,    51,    52,
      53,   120,    63,    54,    55,   141,   121,   122,    46,   142,
     180,   181,   168,   169,   170,   171,   125,   126,   143,   106,
      49,    50,    51,    52,    53,   131,   132,    54,    55,   139,
       1,   193,   140,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,   153,   146,   189,   190,   191,   146,   192,
     146,    84,   164,   165,    85,   166,   167,    86,    87,    88,
      89,   151,    83,    50,    51,    52,    53,   152,    56,    54,
      55,    57,    58,    59,    60,    61,    62,   172,   173,   182,
     196,   174,   176,   175,    90,    40,   148,   110,   111,   177,
      47,    43,    56,   178,   186,    57,    58,    59,    60,    61,
      62,    41,   119,    32,    49,    50,    51,    52,    53,    63,
     187,    54,    55,   149,     0,     0,     0,    84,     0,     0,
      85,     0,     0,    86,    87,    88,    89,     0,    49,    50,
      51,    52,    53,     0,    56,    54,    55,    57,    58,    59,
      60,    61,    62,     0,     0,     0,     0,     0,     0,     0,
      90,    40,     0,   160,   161,   162,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,     0,     0,     0,     0,     0,    56,     0,     0,    57,
      58,    59,    60,    61,    62,     0,    49,    50,    51,    52,
      53,     0,   144,    54,    55,     0,     0,     0,     0,     0,
      56,   156,     0,    57,    58,    59,    60,    61,    62,     1,
       0,     0,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,     1,     0,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,     0,     0,     0,     0,     0,
     185,     0,     0,     0,     0,     0,     0,     0,   105,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    56,     0,
       0,    57,    58,    59,    60,    61,    62,     1,     0,     0,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11
};

static const yytype_int16 yycheck[] =
{
      39,    14,    15,    13,    63,     3,    10,    11,   138,    40,
       3,    21,     3,     4,     5,     6,     7,    37,     0,    10,
      11,    90,     3,    77,    63,    80,    81,    40,    77,    42,
      77,    14,    15,     3,     4,     5,     6,     7,    75,    93,
      10,    11,    91,    76,    91,    90,    37,    56,    78,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    79,
      88,   191,   192,    90,    89,    92,   196,    58,    99,    77,
      61,    75,    18,    64,    65,    66,    67,    75,   117,   118,
      89,    79,    75,    91,    75,    22,    99,    78,    79,    80,
      81,    82,    83,    91,    75,   154,   106,    19,    79,    36,
      91,    92,    93,    86,    87,    75,    94,   146,    78,    79,
      80,    81,    82,    83,    22,   154,     3,     4,     5,     6,
       7,    79,    92,    10,    11,     3,    84,    85,    36,    91,
     139,   140,   127,   128,   129,   130,    12,    13,    91,   152,
       3,     4,     5,     6,     7,    16,    17,    10,    11,    75,
      37,   190,    75,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    76,    77,    76,    77,    76,    77,    76,
      77,    58,   123,   124,    61,   125,   126,    64,    65,    66,
      67,    76,     3,     4,     5,     6,     7,    77,    75,    10,
      11,    78,    79,    80,    81,    82,    83,   131,   132,    91,
      59,   133,   135,   134,    91,    92,    93,    54,    55,   136,
      37,    28,    75,   137,   152,    78,    79,    80,    81,    82,
      83,    26,    69,    17,     3,     4,     5,     6,     7,    92,
      93,    10,    11,    99,    -1,    -1,    -1,    58,    -1,    -1,
      61,    -1,    -1,    64,    65,    66,    67,    -1,     3,     4,
       5,     6,     7,    -1,    75,    10,    11,    78,    79,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      91,    92,    -1,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    78,
      79,    80,    81,    82,    83,    -1,     3,     4,     5,     6,
       7,    -1,    91,    10,    11,    -1,    -1,    -1,    -1,    -1,
      75,    76,    -1,    78,    79,    80,    81,    82,    83,    37,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    37,    -1,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,
      -1,    78,    79,    80,    81,    82,    83,    37,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    37,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,   116,   117,   120,   121,   140,   141,   142,   143,
       3,    75,    79,    91,   118,   119,   122,   123,   124,   117,
     117,     0,   142,   122,   121,   124,   125,    77,    91,    90,
      92,   133,    75,   123,    76,   121,   124,   119,   122,     3,
       4,     5,     6,     7,    10,    11,    75,    78,    79,    80,
      81,    82,    83,    92,    96,    97,    98,    99,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   129,     3,    58,    61,    64,    65,    66,    67,
      91,    93,   114,   115,   116,   117,   131,   132,   133,   134,
     135,   136,   137,   138,   139,    76,   117,   126,   127,   128,
     101,   101,   115,   129,   130,    10,    11,    75,    90,   101,
      79,    84,    85,    80,    81,    12,    13,    14,    15,    86,
      87,    16,    17,    78,    88,    89,    18,    19,    94,    75,
      75,     3,    91,    91,    91,   115,    77,    91,    93,   135,
     122,    76,    77,    76,    77,    93,    76,   100,   114,   114,
     101,   101,   101,   101,   103,   103,   104,   104,   105,   105,
     105,   105,   106,   106,   107,   108,   109,   110,   111,   131,
     115,   115,    91,    91,   114,    55,   128,    93,   129,    76,
      77,    76,    76,   114,   131,   131,    59,   131
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    95,    96,    96,    96,    96,    97,    97,    98,    98,
      99,    99,    99,    99,    99,   100,   100,   101,   101,   101,
     101,   102,   102,   102,   102,   102,   102,   103,   103,   103,
     103,   104,   104,   104,   105,   105,   105,   106,   106,   106,
     106,   106,   107,   107,   107,   108,   108,   109,   109,   110,
     110,   111,   111,   112,   112,   113,   114,   114,   115,   115,
     116,   116,   117,   117,   117,   117,   118,   118,   119,   119,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     121,   122,   122,   123,   123,   123,   123,   124,   124,   124,
     124,   125,   125,   126,   126,   127,   127,   128,   128,   129,
     129,   129,   130,   130,   131,   131,   131,   131,   131,   131,
     132,   133,   133,   134,   134,   135,   135,   136,   136,   137,
     137,   138,   139,   139,   139,   139,   139,   140,   141,   141,
     142,   142,   143
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     3,     4,     2,     2,     1,     3,     1,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     1,     3,     1,     3,
       2,     3,     2,     1,     2,     1,     1,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     3,     4,     3,     3,     2,     2,
       1,     1,     2,     3,     1,     1,     3,     2,     1,     3,
       4,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       3,     2,     3,     1,     2,     1,     1,     1,     2,     7,
       5,     5,     3,     2,     2,     2,     3,     1,     1,     2,
       1,     1,     3
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
#line 1610 "c.tab.cpp"
    break;

  case 5:
#line 62 "c.y"
                                        { (yyval.a) = (yyvsp[-1].a); }
#line 1616 "c.tab.cpp"
    break;

  case 6:
#line 66 "c.y"
                                { (yyval.a) = createAST(0, "I_CONSTANT", {}, (yyvsp[0].s)); }
#line 1622 "c.tab.cpp"
    break;

  case 7:
#line 67 "c.y"
                                { (yyval.a) = createAST(0, "F_CONSTANT", {}, (yyvsp[0].s)); }
#line 1628 "c.tab.cpp"
    break;

  case 8:
#line 71 "c.y"
                                        { (yyval.a) = createAST(0, "STR_LITERAL", {}, (yyvsp[0].s)); }
#line 1634 "c.tab.cpp"
    break;

  case 9:
#line 72 "c.y"
                                                { (yyval.a) = createAST(0, "FN_NAME"); }
#line 1640 "c.tab.cpp"
    break;

  case 11:
#line 77 "c.y"
                                                                                                { (yyval.a) = createAST(1, "fn_call", {(yyvsp[-2].a)}); }
#line 1646 "c.tab.cpp"
    break;

  case 12:
#line 78 "c.y"
                                                                        { (yyval.a) = createAST(1, "fn_call", {(yyvsp[-3].a), (yyvsp[-1].a)}); }
#line 1652 "c.tab.cpp"
    break;

  case 13:
#line 79 "c.y"
                                                                                                        { AST* inc = createAST(0, "INC_OP"); (yyval.a) = createAST(1, "postfix_expression", {(yyvsp[-1].a), inc}); }
#line 1658 "c.tab.cpp"
    break;

  case 14:
#line 80 "c.y"
                                                                                                        { AST* dec = createAST(0, "DEC_OP"); (yyval.a) = createAST(1, "postfix_expression", {(yyvsp[-1].a), dec}); }
#line 1664 "c.tab.cpp"
    break;

  case 15:
#line 84 "c.y"
                                                                                                        { (yyval.a) = createAST(3, "argument_expression_list", {(yyvsp[0].a)}); }
#line 1670 "c.tab.cpp"
    break;

  case 16:
#line 85 "c.y"
                                                                        { (yyval.a) = createAST(3, "argument_expression_list", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1676 "c.tab.cpp"
    break;

  case 18:
#line 90 "c.y"
                                                        { AST* inc = createAST(0, "INC_OP"); (yyval.a) = createAST(1, "unary_expression", {inc, (yyvsp[0].a)}); }
#line 1682 "c.tab.cpp"
    break;

  case 19:
#line 91 "c.y"
                                                        { AST* dec = createAST(0, "DEC_OP"); (yyval.a) = createAST(1, "unary_expression", {dec, (yyvsp[0].a)}); }
#line 1688 "c.tab.cpp"
    break;

  case 20:
#line 92 "c.y"
                                                { (yyval.a) = createAST(1, "unary expression", {(yyvsp[-1].a), (yyvsp[0].a)}); }
#line 1694 "c.tab.cpp"
    break;

  case 21:
#line 96 "c.y"
                {(yyval.a) = createAST(0, "&");}
#line 1700 "c.tab.cpp"
    break;

  case 22:
#line 97 "c.y"
                {(yyval.a) = createAST(0, "*");}
#line 1706 "c.tab.cpp"
    break;

  case 23:
#line 98 "c.y"
                {(yyval.a) = createAST(0, "+");}
#line 1712 "c.tab.cpp"
    break;

  case 24:
#line 99 "c.y"
                {(yyval.a) = createAST(0, "-");}
#line 1718 "c.tab.cpp"
    break;

  case 25:
#line 100 "c.y"
                {(yyval.a) = createAST(0, "~");}
#line 1724 "c.tab.cpp"
    break;

  case 26:
#line 101 "c.y"
                {(yyval.a) = createAST(0, "!");}
#line 1730 "c.tab.cpp"
    break;

  case 28:
#line 106 "c.y"
                                                                        { (yyval.a) = createAST(1, "*", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1736 "c.tab.cpp"
    break;

  case 29:
#line 107 "c.y"
                                                                        { (yyval.a) = createAST(1, "/", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1742 "c.tab.cpp"
    break;

  case 30:
#line 108 "c.y"
                                                                        { (yyval.a) = createAST(1, "%", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1748 "c.tab.cpp"
    break;

  case 32:
#line 113 "c.y"
                                                                                { (yyval.a) = createAST(1, "+", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1754 "c.tab.cpp"
    break;

  case 33:
#line 114 "c.y"
                                                                                { (yyval.a) = createAST(1, "-", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1760 "c.tab.cpp"
    break;

  case 35:
#line 119 "c.y"
                                                                                { (yyval.a) = createAST(1, "LEFT_OP", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1766 "c.tab.cpp"
    break;

  case 36:
#line 120 "c.y"
                                                                                { (yyval.a) = createAST(1, "RIGHT_OP", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1772 "c.tab.cpp"
    break;

  case 38:
#line 125 "c.y"
                                                                                { (yyval.a) = createAST(1, "<", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1778 "c.tab.cpp"
    break;

  case 39:
#line 126 "c.y"
                                                                                { (yyval.a) = createAST(1, ">", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1784 "c.tab.cpp"
    break;

  case 40:
#line 127 "c.y"
                                                                                { (yyval.a) = createAST(1, "LE_OP", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1790 "c.tab.cpp"
    break;

  case 41:
#line 128 "c.y"
                                                                                { (yyval.a) = createAST(1, "GE_OP", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1796 "c.tab.cpp"
    break;

  case 43:
#line 133 "c.y"
                                                                                { (yyval.a) = createAST(1, "EQ_OP", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1802 "c.tab.cpp"
    break;

  case 44:
#line 134 "c.y"
                                                                                { (yyval.a) = createAST(1, "NE_OP", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1808 "c.tab.cpp"
    break;

  case 46:
#line 139 "c.y"
                                                                                        { (yyval.a) = createAST(1, "&", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1814 "c.tab.cpp"
    break;

  case 48:
#line 144 "c.y"
                                                                                { (yyval.a) = createAST(1, "^", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1820 "c.tab.cpp"
    break;

  case 50:
#line 149 "c.y"
                                                                        { (yyval.a) = createAST(1, "|", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1826 "c.tab.cpp"
    break;

  case 52:
#line 154 "c.y"
                                                                        { (yyval.a) = createAST(1, "AND_OP", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1832 "c.tab.cpp"
    break;

  case 54:
#line 159 "c.y"
                                                                        { (yyval.a) = createAST(1, "OR_OP", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1838 "c.tab.cpp"
    break;

  case 57:
#line 168 "c.y"
                                                                { (yyval.a) = createAST(1, "assignment", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1844 "c.tab.cpp"
    break;

  case 59:
#line 173 "c.y"
                                                { (yyval.a) = createAST(1, "expression", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1850 "c.tab.cpp"
    break;

  case 60:
#line 177 "c.y"
                                                                                { (yyval.a) = createAST(1, "declaration", {(yyvsp[-1].a)}); }
#line 1856 "c.tab.cpp"
    break;

  case 61:
#line 178 "c.y"
                                                                { (yyval.a) = createAST(1, "declaration", {(yyvsp[-2].a), (yyvsp[-1].a)}); }
#line 1862 "c.tab.cpp"
    break;

  case 62:
#line 182 "c.y"
                                                                        { (yyval.a) = createAST(1, "declaration_specifiers", {(yyvsp[-1].a), (yyvsp[0].a)}); }
#line 1868 "c.tab.cpp"
    break;

  case 64:
#line 184 "c.y"
                                                                        { (yyval.a) = createAST(1, "declaration_specifiers", {(yyvsp[-1].a), (yyvsp[0].a)}); }
#line 1874 "c.tab.cpp"
    break;

  case 67:
#line 190 "c.y"
                                                                { (yyval.a) = createAST(3, "init_declarator_list", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1880 "c.tab.cpp"
    break;

  case 68:
#line 194 "c.y"
                                                                { (yyval.a) = createAST(1, "=", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1886 "c.tab.cpp"
    break;

  case 70:
#line 199 "c.y"
                        {(yyval.a) = createAST(0, "VOID");}
#line 1892 "c.tab.cpp"
    break;

  case 71:
#line 200 "c.y"
                        {(yyval.a) = createAST(0, "CHAR");}
#line 1898 "c.tab.cpp"
    break;

  case 72:
#line 201 "c.y"
                        {(yyval.a) = createAST(0, "SHORT");}
#line 1904 "c.tab.cpp"
    break;

  case 73:
#line 202 "c.y"
                        {(yyval.a) = createAST(0, "INT");}
#line 1910 "c.tab.cpp"
    break;

  case 74:
#line 203 "c.y"
                        {(yyval.a) = createAST(0, "LONG");}
#line 1916 "c.tab.cpp"
    break;

  case 75:
#line 204 "c.y"
                        {(yyval.a) = createAST(0, "FLOAT");}
#line 1922 "c.tab.cpp"
    break;

  case 76:
#line 205 "c.y"
                        {(yyval.a) = createAST(0, "DOUBLE");}
#line 1928 "c.tab.cpp"
    break;

  case 77:
#line 206 "c.y"
                        {(yyval.a) = createAST(0, "SIGNED");}
#line 1934 "c.tab.cpp"
    break;

  case 78:
#line 207 "c.y"
                        {(yyval.a) = createAST(0, "UNSIGNED");}
#line 1940 "c.tab.cpp"
    break;

  case 79:
#line 208 "c.y"
                        {(yyval.a) = createAST(0, "BOOL");}
#line 1946 "c.tab.cpp"
    break;

  case 80:
#line 212 "c.y"
                                { (yyval.a) = createAST(0, "CONST"); }
#line 1952 "c.tab.cpp"
    break;

  case 81:
#line 216 "c.y"
                                                { (yyval.a) = createAST(0, "declarator", {(yyvsp[-1].a), (yyvsp[0].a)}); }
#line 1958 "c.tab.cpp"
    break;

  case 83:
#line 221 "c.y"
                                                                                                                                                        { (yyval.a) = createAST(0, "ID", {}, (yyvsp[0].s)); }
#line 1964 "c.tab.cpp"
    break;

  case 84:
#line 222 "c.y"
                                                                                                                                                { (yyval.a) = (yyvsp[-1].a); }
#line 1970 "c.tab.cpp"
    break;

  case 85:
#line 223 "c.y"
                                                                                                                        { (yyval.a) = createAST(1, "direct_declarator", {(yyvsp[-3].a), (yyvsp[-1].a)}); }
#line 1976 "c.tab.cpp"
    break;

  case 87:
#line 228 "c.y"
                                                        { AST* star = createAST(0, "*"); (yyval.a) = createAST(1, "pointer", {star, (yyvsp[-1].a), (yyvsp[0].a)}); }
#line 1982 "c.tab.cpp"
    break;

  case 88:
#line 229 "c.y"
                                                                { AST* star = createAST(0, "*"); (yyval.a) = createAST(1, "pointer", {star, (yyvsp[0].a)}); }
#line 1988 "c.tab.cpp"
    break;

  case 89:
#line 230 "c.y"
                                                                        { AST* star = createAST(0, "*"); (yyval.a) = createAST(1, "pointer", {star, (yyvsp[0].a)}); }
#line 1994 "c.tab.cpp"
    break;

  case 90:
#line 231 "c.y"
                                                                                { (yyval.a) = createAST(0, "*"); }
#line 2000 "c.tab.cpp"
    break;

  case 92:
#line 236 "c.y"
                                                { (yyval.a) = createAST(3, "type_qualifier_list", {(yyvsp[-1].a), (yyvsp[0].a)}); }
#line 2006 "c.tab.cpp"
    break;

  case 93:
#line 241 "c.y"
                                                        { AST* temp = createAST(0, "ELLIPSIS"); push((yyvsp[-2].a), {temp}); (yyval.a) = (yyvsp[-2].a); }
#line 2012 "c.tab.cpp"
    break;

  case 96:
#line 247 "c.y"
                                                                { (yyval.a) = createAST(3, "parameter_list", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 2018 "c.tab.cpp"
    break;

  case 97:
#line 251 "c.y"
                                                                        { (yyval.a) = createAST(1, "parameter_declaration", {(yyvsp[-1].a), (yyvsp[0].a)}); }
#line 2024 "c.tab.cpp"
    break;

  case 99:
#line 256 "c.y"
                                                        { (yyval.a) = (yyvsp[-1].a); }
#line 2030 "c.tab.cpp"
    break;

  case 100:
#line 257 "c.y"
                                                { (yyval.a) = (yyvsp[-2].a); }
#line 2036 "c.tab.cpp"
    break;

  case 101:
#line 258 "c.y"
                                                        { (yyval.a) = (yyvsp[0].a); }
#line 2042 "c.tab.cpp"
    break;

  case 103:
#line 263 "c.y"
                                                                                { (yyval.a) = createAST(3, "initializer_list", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 2048 "c.tab.cpp"
    break;

  case 110:
#line 276 "c.y"
                                                                                { AST* temp = createAST(0, "ID", {}, (yyvsp[-2].s)); (yyval.a) = createAST(1, "labeled_statement", {temp, (yyvsp[0].a)}); }
#line 2054 "c.tab.cpp"
    break;

  case 111:
#line 280 "c.y"
                                                                        { (yyval.a) = createAST(4, "empty_compound_statement"); }
#line 2060 "c.tab.cpp"
    break;

  case 112:
#line 281 "c.y"
                                                        { (yyval.a) = createAST(1, "compound_statement", {(yyvsp[-1].a)}); }
#line 2066 "c.tab.cpp"
    break;

  case 114:
#line 286 "c.y"
                                                { (yyval.a) = createAST(3, "block_item_list", {(yyvsp[-1].a), (yyvsp[0].a)}); }
#line 2072 "c.tab.cpp"
    break;

  case 117:
#line 295 "c.y"
                                                { (yyval.a) = createAST(0, ";"); }
#line 2078 "c.tab.cpp"
    break;

  case 118:
#line 296 "c.y"
                                        { (yyval.a) = (yyvsp[-1].a); }
#line 2084 "c.tab.cpp"
    break;

  case 119:
#line 300 "c.y"
                                                                        { (yyval.a) = createAST(1, "ifte", {(yyvsp[-4].a), (yyvsp[-2].a), (yyvsp[0].a)}); }
#line 2090 "c.tab.cpp"
    break;

  case 120:
#line 301 "c.y"
                                                                                        { (yyval.a) = createAST(1, "ifte", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 2096 "c.tab.cpp"
    break;

  case 121:
#line 305 "c.y"
                                                                                                                                        { (yyval.a) = createAST(1, "while", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 2102 "c.tab.cpp"
    break;

  case 122:
#line 309 "c.y"
                                                { AST* temp1 = createAST(0, "GOTO"); AST* temp2 = createAST(0, "ID", {}, (yyvsp[-1].s)); (yyval.a) = createAST(1, "jump", {temp1, temp2});}
#line 2108 "c.tab.cpp"
    break;

  case 123:
#line 310 "c.y"
                                                        { AST* temp1 = createAST(0, "CONTINUE"); (yyval.a) = createAST(1, "jump", {temp1});}
#line 2114 "c.tab.cpp"
    break;

  case 124:
#line 311 "c.y"
                                                                { AST* temp1 = createAST(0, "BREAK"); (yyval.a) = createAST(1, "jump", {temp1});}
#line 2120 "c.tab.cpp"
    break;

  case 125:
#line 312 "c.y"
                                                        { AST* temp1 = createAST(0, "RETURN"); (yyval.a) = createAST(1, "jump", {temp1});}
#line 2126 "c.tab.cpp"
    break;

  case 126:
#line 313 "c.y"
                                                { AST* temp1 = createAST(0, "RETURN"); (yyval.a) = createAST(1, "jump", {temp1, (yyvsp[-1].a)});}
#line 2132 "c.tab.cpp"
    break;

  case 127:
#line 317 "c.y"
                                        { ast_root = (yyvsp[0].a); (yyval.a) = (yyvsp[0].a); }
#line 2138 "c.tab.cpp"
    break;

  case 128:
#line 321 "c.y"
                                                                        { (yyval.a) = createAST(1, "PROGRAM", {(yyvsp[0].a)}); }
#line 2144 "c.tab.cpp"
    break;

  case 129:
#line 322 "c.y"
                                                        { AST* root = (yyvsp[-1].a); push(root, {(yyvsp[0].a)}); (yyval.a) = root; }
#line 2150 "c.tab.cpp"
    break;

  case 132:
#line 331 "c.y"
                                                                                                        { (yyval.a) = createAST(1, "FUNC", {(yyvsp[-2].a), (yyvsp[-1].a), (yyvsp[0].a)}); }
#line 2156 "c.tab.cpp"
    break;


#line 2160 "c.tab.cpp"

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
#line 334 "c.y"

#include <stdio.h>

void yyerror(const char *s)
{
	fflush(stdout);
	fprintf(stderr, "*** %s\n", s);
}
