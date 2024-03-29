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
#define YYLAST   509

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  96
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  130
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  199

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
       0,    60,    60,    61,    62,    63,    67,    68,    72,    73,
      74,    75,    76,    80,    81,    86,    87,    88,    89,    93,
      94,    95,    96,    97,    98,   102,   103,   104,   105,   109,
     110,   111,   115,   116,   117,   121,   122,   123,   124,   125,
     129,   130,   131,   135,   136,   140,   141,   145,   146,   150,
     151,   155,   156,   160,   161,   165,   166,   170,   171,   176,
     177,   181,   182,   186,   187,   191,   192,   193,   194,   198,
     199,   203,   204,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   221,   225,   226,   230,   231,   232,   233,
     237,   238,   239,   240,   244,   245,   250,   251,   255,   256,
     260,   261,   265,   266,   267,   268,   269,   270,   274,   278,
     279,   283,   284,   288,   289,   293,   294,   298,   299,   303,
     307,   308,   309,   310,   311,   315,   319,   320,   324,   325,
     329
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
  "conditional_expression", "cast_expression", "type_name",
  "assignment_expression", "expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "type_specifier", "type_qualifier", "declarator", "direct_declarator",
  "pointer", "type_qualifier_list", "parameter_type_list",
  "parameter_list", "parameter_declaration", "statement",
  "labeled_statement", "compound_statement", "block_item_list",
  "block_item", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", "new_start", "translation_unit",
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
      63,    58,    61,    59,   123,   125
};
# endif

#define YYPACT_NINF (-135)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     460,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,
    -135,  -135,  -135,   272,  -135,  -135,    12,   460,  -135,  -135,
    -135,    -1,   -28,  -135,   -70,  -135,  -135,  -135,   -59,   -57,
      -2,  -135,  -135,   -52,  -135,  -135,   -28,    -1,  -135,   319,
      98,  -135,   423,   -57,  -135,  -135,  -135,  -135,   -60,  -135,
    -135,  -135,  -135,   375,   375,   294,  -135,  -135,  -135,  -135,
    -135,  -135,  -135,  -135,     0,   -40,   375,   -48,   -42,    32,
      26,    39,   -19,   -26,   -17,    61,    15,  -135,  -135,  -135,
     -41,    54,    57,   134,    60,    62,    43,  -135,  -135,  -135,
     -63,  -135,   272,  -135,  -135,  -135,   164,  -135,  -135,  -135,
    -135,  -135,  -135,   367,    78,    80,  -135,   319,  -135,  -135,
      82,    -8,   380,  -135,  -135,   279,   319,  -135,   375,   375,
     375,   375,   375,   375,   375,   375,   375,   375,   375,   375,
     375,   375,   375,   375,   375,   375,   319,   213,   319,   319,
      67,  -135,  -135,  -135,   -51,   319,  -135,  -135,  -135,  -135,
    -135,   436,   319,  -135,  -135,  -135,    -6,  -135,  -135,  -135,
    -135,  -135,  -135,   -48,   -48,   -42,   -42,    32,    32,    32,
      32,    26,    26,    39,   -19,   -26,   -17,    61,   -64,  -135,
      40,    51,  -135,  -135,  -135,  -135,  -135,  -135,  -135,   319,
     375,   213,   213,  -135,  -135,   102,  -135,   213,  -135
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    83,    82,    74,    75,    76,    77,    80,    81,    78,
      79,    73,   129,     0,    66,    68,     0,   125,   126,   128,
      86,     0,    93,    63,     0,    69,    65,    67,    72,    85,
       0,     1,   127,     0,    94,    92,    91,     0,    64,     0,
       0,   130,     0,    84,    87,    95,    90,    70,    72,     2,
       6,     7,     4,     0,     0,     0,    19,    20,    21,    22,
      23,    24,     8,     3,    15,    25,     0,    29,    32,    35,
      40,    43,    45,    47,    49,    51,    53,    55,    59,    71,
       2,     0,     0,     0,     0,     0,     0,   115,   109,    61,
       0,   113,     0,   114,   102,   103,     0,   111,   104,   105,
     106,   107,    89,   101,     0,    97,    98,     0,    16,    17,
       0,     0,    58,    11,    12,     0,     0,    18,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   121,   122,   123,     0,     0,   116,   110,   112,   100,
      88,     0,     0,     5,    57,     9,     0,    13,    60,    26,
      27,    28,    25,    30,    31,    33,    34,    38,    39,    36,
      37,    41,    42,    44,    46,    48,    50,    52,     0,   108,
       0,     0,   120,   124,    62,    96,    99,    56,    10,     0,
       0,     0,     0,    14,    54,   118,   119,     0,   117
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -135,  -135,  -135,  -135,  -135,   -38,  -135,     9,    10,   -61,
      19,    35,    52,    38,    49,    37,  -135,    -5,    34,  -135,
     -39,    96,   -35,   -36,  -135,   150,     8,     7,     4,   158,
     -14,  -135,  -135,  -135,    44,  -134,  -135,   161,  -135,    94,
    -135,  -135,  -135,  -135,  -135,  -135,   177,  -135
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    62,    63,    64,   156,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,   110,
      89,    90,    12,    13,    24,    25,    14,    15,    48,    29,
      30,    36,   104,   105,   106,    93,    94,    95,    96,    97,
      98,    99,   100,   101,    16,    17,    18,    19
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      79,    20,    20,   179,    92,    91,   103,    37,    35,     1,
     113,   114,    31,   145,   145,   108,   109,    28,    42,   112,
      27,    26,    46,    38,    44,    33,   145,   190,   117,    34,
     146,   118,    39,    39,   135,    40,   119,   120,   121,   122,
     125,   126,   183,    45,   123,   124,    49,    50,    51,    52,
     137,    22,   116,    53,    54,   129,   130,   195,   196,   131,
      92,    91,   132,   198,   167,   168,   169,   170,   153,   145,
     188,   189,   133,    21,    21,   115,   157,   158,    22,   134,
     159,   160,   161,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   162,   154,    27,
      26,    80,    50,    51,    52,   136,   184,   149,    53,    54,
      27,    26,   127,   128,   162,   103,   191,   145,    55,    27,
      26,    56,    57,    58,    59,    60,    61,   192,   145,   138,
     163,   164,   139,   165,   166,     1,   143,   140,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,   171,   172,
     193,   111,   162,   141,   150,   142,    81,   151,   152,    82,
     182,   197,    83,    84,    85,    86,   173,    80,    50,    51,
      52,   175,   177,    55,    53,    54,    56,    57,    58,    59,
      60,    61,   144,   176,   174,   194,   187,    47,    43,    41,
     148,    87,    40,    88,    32,   186,     0,     0,     0,     0,
       0,     1,     0,   111,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,     0,     0,    80,    50,    51,    52,
       0,     0,    81,    53,    54,    82,     0,     0,    83,    84,
      85,    86,   178,     0,   180,   181,     0,     0,     0,    55,
       0,     0,    56,    57,    58,    59,    60,    61,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    87,    40,   147,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    81,     0,     0,    82,    20,     0,    83,    84,    85,
      86,     0,    49,    50,    51,    52,     0,     0,    55,    53,
      54,    56,    57,    58,    59,    60,    61,    49,    50,    51,
      52,     0,     0,     0,    53,    54,    87,    40,     0,     1,
       0,     0,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    49,    50,    51,    52,     0,     0,     0,    53,
      54,     1,     0,     0,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,     0,     0,     0,    21,     0,     0,
       0,    22,     0,     0,    55,   155,     0,    56,    57,    58,
      59,    60,    61,     0,     0,    23,     0,     0,     0,    55,
      20,     0,    56,    57,    58,    59,    60,    61,    49,    50,
      51,    52,     0,     0,     0,    53,    54,     0,     0,     0,
       0,     0,     0,     0,    55,     0,     0,    56,    57,    58,
      59,    60,    61,     0,     1,     0,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,     1,     0,     0,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     0,    22,     0,     0,     0,
     107,     0,     0,    56,    57,    58,    59,    60,    61,    22,
       1,     0,     0,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,     1,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,     0,     0,     0,     0,
       0,   185,     0,     0,     0,     0,     0,     1,     0,   102,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11
};

static const yytype_int16 yycheck[] =
{
      39,     3,     3,   137,    40,    40,    42,    77,    22,    37,
      10,    11,     0,    77,    77,    53,    54,    13,    75,    55,
      13,    13,    36,    93,    76,    21,    77,    91,    66,    22,
      93,    79,    92,    92,    19,    94,    84,    85,    80,    81,
      14,    15,    93,    36,    12,    13,     3,     4,     5,     6,
      91,    79,    92,    10,    11,    16,    17,   191,   192,    78,
      96,    96,    88,   197,   125,   126,   127,   128,    76,    77,
      76,    77,    89,    75,    75,    75,   115,   116,    79,    18,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   112,    92,
      92,     3,     4,     5,     6,    90,   145,   103,    10,    11,
     103,   103,    86,    87,   152,   151,    76,    77,    75,   112,
     112,    78,    79,    80,    81,    82,    83,    76,    77,    75,
     121,   122,    75,   123,   124,    37,    93,     3,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,   129,   130,
     189,    55,   190,    93,    76,    93,    58,    77,    76,    61,
      93,    59,    64,    65,    66,    67,   131,     3,     4,     5,
       6,   133,   135,    75,    10,    11,    78,    79,    80,    81,
      82,    83,    86,   134,   132,   190,   152,    37,    30,    28,
      96,    93,    94,    95,    17,   151,    -1,    -1,    -1,    -1,
      -1,    37,    -1,   107,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,     3,     4,     5,     6,
      -1,    -1,    58,    10,    11,    61,    -1,    -1,    64,    65,
      66,    67,   136,    -1,   138,   139,    -1,    -1,    -1,    75,
      -1,    -1,    78,    79,    80,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    95,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    61,     3,    -1,    64,    65,    66,
      67,    -1,     3,     4,     5,     6,    -1,    -1,    75,    10,
      11,    78,    79,    80,    81,    82,    83,     3,     4,     5,
       6,    -1,    -1,    -1,    10,    11,    93,    94,    -1,    37,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,     3,     4,     5,     6,    -1,    -1,    -1,    10,
      11,    37,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    75,    -1,    -1,
      -1,    79,    -1,    -1,    75,    76,    -1,    78,    79,    80,
      81,    82,    83,    -1,    -1,    93,    -1,    -1,    -1,    75,
       3,    -1,    78,    79,    80,    81,    82,    83,     3,     4,
       5,     6,    -1,    -1,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    -1,    -1,    78,    79,    80,
      81,    82,    83,    -1,    37,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    37,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    -1,    -1,    -1,    79,    -1,    -1,    -1,
      75,    -1,    -1,    78,    79,    80,    81,    82,    83,    79,
      37,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    37,    -1,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    37,    -1,    76,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    37,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,   118,   119,   122,   123,   140,   141,   142,   143,
       3,    75,    79,    93,   120,   121,   122,   123,   124,   125,
     126,     0,   142,   124,   123,   126,   127,    77,    93,    92,
      94,   133,    75,   125,    76,   123,   126,   121,   124,     3,
       4,     5,     6,    10,    11,    75,    78,    79,    80,    81,
      82,    83,    97,    98,    99,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   116,
       3,    58,    61,    64,    65,    66,    67,    93,    95,   116,
     117,   118,   119,   131,   132,   133,   134,   135,   136,   137,
     138,   139,    76,   119,   128,   129,   130,    75,   101,   101,
     115,   117,   119,    10,    11,    75,    92,   101,    79,    84,
      85,    80,    81,    12,    13,    14,    15,    86,    87,    16,
      17,    78,    88,    89,    18,    19,    90,    91,    75,    75,
       3,    93,    93,    93,   117,    77,    93,    95,   135,   124,
      76,    77,    76,    76,   126,    76,   100,   116,   116,   101,
     101,   101,   101,   103,   103,   104,   104,   105,   105,   105,
     105,   106,   106,   107,   108,   109,   110,   111,   117,   131,
     117,   117,    93,    93,   116,    55,   130,   114,    76,    77,
      91,    76,    76,   116,   113,   131,   131,    59,   131
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
     116,   117,   117,   118,   118,   119,   119,   119,   119,   120,
     120,   121,   121,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   123,   124,   124,   125,   125,   125,   125,
     126,   126,   126,   126,   127,   127,   128,   128,   129,   129,
     130,   130,   131,   131,   131,   131,   131,   131,   132,   133,
     133,   134,   134,   135,   135,   136,   136,   137,   137,   138,
     139,   139,   139,   139,   139,   140,   141,   141,   142,   142,
     143
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     3,
       4,     2,     2,     1,     3,     1,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     5,     1,     4,     2,     1,     1,
       3,     1,     3,     2,     3,     2,     1,     2,     1,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     3,     4,     3,
       3,     2,     2,     1,     1,     2,     3,     1,     1,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     3,     2,
       3,     1,     2,     1,     1,     1,     2,     7,     5,     5,
       3,     2,     2,     2,     3,     1,     1,     2,     1,     1,
       3
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
#line 60 "c.y"
                        { (yyval.a) = createAST(0, "ID", {}, (yyvsp[0].s)); }
#line 1632 "c.tab.cpp"
    break;

  case 4:
#line 62 "c.y"
                                        { (yyval.a) = createAST(0, "STR_LITERAL", {}, (yyvsp[0].s)); }
#line 1638 "c.tab.cpp"
    break;

  case 5:
#line 63 "c.y"
                                        { (yyval.a) = (yyvsp[-1].a); }
#line 1644 "c.tab.cpp"
    break;

  case 6:
#line 67 "c.y"
                                { (yyval.a) = createAST(0, "I_CONSTANT", {}, (yyvsp[0].s)); }
#line 1650 "c.tab.cpp"
    break;

  case 7:
#line 68 "c.y"
                                { (yyval.a) = createAST(0, "F_CONSTANT", {}, (yyvsp[0].s)); }
#line 1656 "c.tab.cpp"
    break;

  case 9:
#line 73 "c.y"
                                                                                                { (yyval.a) = createAST(1, "fn_call", {(yyvsp[-2].a), createAST(3, "argument_expression")}); }
#line 1662 "c.tab.cpp"
    break;

  case 10:
#line 74 "c.y"
                                                                        { (yyval.a) = createAST(1, "fn_call", {(yyvsp[-3].a), (yyvsp[-1].a)}); }
#line 1668 "c.tab.cpp"
    break;

  case 11:
#line 75 "c.y"
                                                                                                        { AST* inc = createAST(0, "INC_OP"); (yyval.a) = createAST(1, "postfix_expression", {(yyvsp[-1].a), inc}); }
#line 1674 "c.tab.cpp"
    break;

  case 12:
#line 76 "c.y"
                                                                                                        { AST* dec = createAST(0, "DEC_OP"); (yyval.a) = createAST(1, "postfix_expression", {(yyvsp[-1].a), dec}); }
#line 1680 "c.tab.cpp"
    break;

  case 13:
#line 80 "c.y"
                                                                                                        { (yyval.a) = createAST(3, "argument_expression", {(yyvsp[0].a)}); }
#line 1686 "c.tab.cpp"
    break;

  case 14:
#line 81 "c.y"
                                                                        { push((yyvsp[-2].a), {(yyvsp[0].a)}); (yyval.a) = (yyvsp[-2].a); }
#line 1692 "c.tab.cpp"
    break;

  case 16:
#line 87 "c.y"
                                                        { AST* inc = createAST(0, "INC_OP"); (yyval.a) = createAST(1, "unary_expression", {inc, (yyvsp[0].a)}); }
#line 1698 "c.tab.cpp"
    break;

  case 17:
#line 88 "c.y"
                                                        { AST* dec = createAST(0, "DEC_OP"); (yyval.a) = createAST(1, "unary_expression", {dec, (yyvsp[0].a)}); }
#line 1704 "c.tab.cpp"
    break;

  case 18:
#line 89 "c.y"
                                                { (yyval.a) = createAST(1, "unary_expression", {(yyvsp[-1].a), (yyvsp[0].a)}); }
#line 1710 "c.tab.cpp"
    break;

  case 19:
#line 93 "c.y"
                {(yyval.a) = createAST(0, "&");}
#line 1716 "c.tab.cpp"
    break;

  case 20:
#line 94 "c.y"
                {(yyval.a) = createAST(0, "*");}
#line 1722 "c.tab.cpp"
    break;

  case 21:
#line 95 "c.y"
                {(yyval.a) = createAST(0, "+");}
#line 1728 "c.tab.cpp"
    break;

  case 22:
#line 96 "c.y"
                {(yyval.a) = createAST(0, "-");}
#line 1734 "c.tab.cpp"
    break;

  case 23:
#line 97 "c.y"
                {(yyval.a) = createAST(0, "~");}
#line 1740 "c.tab.cpp"
    break;

  case 24:
#line 98 "c.y"
                {(yyval.a) = createAST(0, "!");}
#line 1746 "c.tab.cpp"
    break;

  case 26:
#line 103 "c.y"
                                                                        { (yyval.a) = createAST(1, "*", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1752 "c.tab.cpp"
    break;

  case 27:
#line 104 "c.y"
                                                                        { (yyval.a) = createAST(1, "/", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1758 "c.tab.cpp"
    break;

  case 28:
#line 105 "c.y"
                                                                        { (yyval.a) = createAST(1, "%", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1764 "c.tab.cpp"
    break;

  case 30:
#line 110 "c.y"
                                                                                { (yyval.a) = createAST(1, "+", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1770 "c.tab.cpp"
    break;

  case 31:
#line 111 "c.y"
                                                                                { (yyval.a) = createAST(1, "-", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1776 "c.tab.cpp"
    break;

  case 33:
#line 116 "c.y"
                                                                                { (yyval.a) = createAST(1, "LEFT_OP", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1782 "c.tab.cpp"
    break;

  case 34:
#line 117 "c.y"
                                                                                { (yyval.a) = createAST(1, "RIGHT_OP", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1788 "c.tab.cpp"
    break;

  case 36:
#line 122 "c.y"
                                                                                { (yyval.a) = createAST(1, "<", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1794 "c.tab.cpp"
    break;

  case 37:
#line 123 "c.y"
                                                                                { (yyval.a) = createAST(1, ">", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1800 "c.tab.cpp"
    break;

  case 38:
#line 124 "c.y"
                                                                                { (yyval.a) = createAST(1, "LE_OP", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1806 "c.tab.cpp"
    break;

  case 39:
#line 125 "c.y"
                                                                                { (yyval.a) = createAST(1, "GE_OP", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1812 "c.tab.cpp"
    break;

  case 41:
#line 130 "c.y"
                                                                                { (yyval.a) = createAST(1, "EQ_OP", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1818 "c.tab.cpp"
    break;

  case 42:
#line 131 "c.y"
                                                                                { (yyval.a) = createAST(1, "NE_OP", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1824 "c.tab.cpp"
    break;

  case 44:
#line 136 "c.y"
                                                                                        { (yyval.a) = createAST(1, "&", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1830 "c.tab.cpp"
    break;

  case 46:
#line 141 "c.y"
                                                                                { (yyval.a) = createAST(1, "^", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1836 "c.tab.cpp"
    break;

  case 48:
#line 146 "c.y"
                                                                        { (yyval.a) = createAST(1, "|", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1842 "c.tab.cpp"
    break;

  case 50:
#line 151 "c.y"
                                                                        { (yyval.a) = createAST(1, "AND_OP", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1848 "c.tab.cpp"
    break;

  case 52:
#line 156 "c.y"
                                                                        { (yyval.a) = createAST(1, "OR_OP", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1854 "c.tab.cpp"
    break;

  case 54:
#line 161 "c.y"
                                                                                                { (yyval.a) = createAST(1, "?:", {(yyvsp[-4].a), (yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1860 "c.tab.cpp"
    break;

  case 56:
#line 166 "c.y"
                                                        { (yyval.a) = createAST(1, "cast_expression", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1866 "c.tab.cpp"
    break;

  case 57:
#line 170 "c.y"
                                                                                { (yyval.a) = createAST(1, "type_name", {(yyvsp[-1].a), (yyvsp[0].a)}); }
#line 1872 "c.tab.cpp"
    break;

  case 58:
#line 171 "c.y"
                                                                                        { (yyval.a) = createAST(1, "type_name", {(yyvsp[0].a)}); }
#line 1878 "c.tab.cpp"
    break;

  case 60:
#line 177 "c.y"
                                                                { (yyval.a) = createAST(1, "assignment", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1884 "c.tab.cpp"
    break;

  case 61:
#line 181 "c.y"
                                                                { (yyval.a) = createAST(3, "expression", {(yyvsp[0].a)}); }
#line 1890 "c.tab.cpp"
    break;

  case 62:
#line 182 "c.y"
                                                { push((yyvsp[-2].a), {(yyvsp[0].a)}); (yyval.a) = (yyvsp[-2].a); }
#line 1896 "c.tab.cpp"
    break;

  case 63:
#line 186 "c.y"
                                                                                { (yyval.a) = createAST(1, "declaration", {(yyvsp[-1].a)}); }
#line 1902 "c.tab.cpp"
    break;

  case 64:
#line 187 "c.y"
                                                                { (yyval.a) = createAST(1, "declaration", {(yyvsp[-2].a), (yyvsp[-1].a)}); }
#line 1908 "c.tab.cpp"
    break;

  case 65:
#line 191 "c.y"
                                                                        { if((yyvsp[-1].a)->node_string=="CONST") {(yyval.a) = createAST(3, "type", {(yyvsp[0].a)});} else {push((yyvsp[-1].a), {(yyvsp[0].a)});  (yyval.a) = (yyvsp[-1].a);} }
#line 1914 "c.tab.cpp"
    break;

  case 66:
#line 192 "c.y"
                                                                                                { (yyval.a) = createAST(3, "type", {(yyvsp[0].a)}); }
#line 1920 "c.tab.cpp"
    break;

  case 67:
#line 193 "c.y"
                                                                        { (yyval.a) = (yyvsp[-1].a); }
#line 1926 "c.tab.cpp"
    break;

  case 69:
#line 198 "c.y"
                                                                                                { (yyval.a) = createAST(3, "init_declarator", {(yyvsp[0].a)}); }
#line 1932 "c.tab.cpp"
    break;

  case 70:
#line 199 "c.y"
                                                                        { push((yyvsp[-2].a), {(yyvsp[0].a)});  (yyval.a) = (yyvsp[-2].a); }
#line 1938 "c.tab.cpp"
    break;

  case 71:
#line 203 "c.y"
                                                                { (yyval.a) = createAST(1, "=", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1944 "c.tab.cpp"
    break;

  case 73:
#line 208 "c.y"
                        {(yyval.a) = createAST(0, "VOID");}
#line 1950 "c.tab.cpp"
    break;

  case 74:
#line 209 "c.y"
                        {(yyval.a) = createAST(0, "CHAR");}
#line 1956 "c.tab.cpp"
    break;

  case 75:
#line 210 "c.y"
                        {(yyval.a) = createAST(0, "SHORT");}
#line 1962 "c.tab.cpp"
    break;

  case 76:
#line 211 "c.y"
                        {(yyval.a) = createAST(0, "INT");}
#line 1968 "c.tab.cpp"
    break;

  case 77:
#line 212 "c.y"
                        {(yyval.a) = createAST(0, "LONG");}
#line 1974 "c.tab.cpp"
    break;

  case 78:
#line 213 "c.y"
                        {(yyval.a) = createAST(0, "FLOAT");}
#line 1980 "c.tab.cpp"
    break;

  case 79:
#line 214 "c.y"
                        {(yyval.a) = createAST(0, "DOUBLE");}
#line 1986 "c.tab.cpp"
    break;

  case 80:
#line 215 "c.y"
                        {(yyval.a) = createAST(0, "SIGNED");}
#line 1992 "c.tab.cpp"
    break;

  case 81:
#line 216 "c.y"
                        {(yyval.a) = createAST(0, "UNSIGNED");}
#line 1998 "c.tab.cpp"
    break;

  case 82:
#line 217 "c.y"
                        {(yyval.a) = createAST(0, "BOOL");}
#line 2004 "c.tab.cpp"
    break;

  case 83:
#line 221 "c.y"
                                { (yyval.a) = createAST(0, "CONST"); }
#line 2010 "c.tab.cpp"
    break;

  case 84:
#line 225 "c.y"
                                                { if((yyvsp[0].a)->node_string=="declarator") {push((yyvsp[0].a)->children[0], (yyvsp[-1].a)->children); (yyval.a) = (yyvsp[0].a);} else {(yyval.a) = createAST(0, "declarator", {(yyvsp[-1].a), (yyvsp[0].a)});} }
#line 2016 "c.tab.cpp"
    break;

  case 85:
#line 226 "c.y"
                                                        { if((yyvsp[0].a)->node_string=="declarator") {(yyval.a) = (yyvsp[0].a);} else {(yyval.a) = createAST(0, "declarator", {createAST(0, "pointer"), (yyvsp[0].a)});} }
#line 2022 "c.tab.cpp"
    break;

  case 86:
#line 230 "c.y"
                                                                                                                                                        { (yyval.a) = createAST(0, "ID", {}, (yyvsp[0].s)); }
#line 2028 "c.tab.cpp"
    break;

  case 87:
#line 231 "c.y"
                                                                                                                                                { (yyval.a) = (yyvsp[-1].a); }
#line 2034 "c.tab.cpp"
    break;

  case 88:
#line 232 "c.y"
                                                                                                                        { (yyval.a) = createAST(1, "fn_declaration", {(yyvsp[-3].a), (yyvsp[-1].a)}); }
#line 2040 "c.tab.cpp"
    break;

  case 89:
#line 233 "c.y"
                                                                                                                                                { (yyval.a) = createAST(1, "fn_declaration", {(yyvsp[-2].a), createAST(3, "parameters")}); }
#line 2046 "c.tab.cpp"
    break;

  case 90:
#line 237 "c.y"
                                                        { AST* star = createAST(0, "*"); push((yyvsp[0].a), {star}); (yyval.a) = (yyvsp[0].a); }
#line 2052 "c.tab.cpp"
    break;

  case 91:
#line 238 "c.y"
                                                                { AST* star = createAST(0, "*"); (yyval.a) = createAST(0, "pointer", {star}); }
#line 2058 "c.tab.cpp"
    break;

  case 92:
#line 239 "c.y"
                                                                        { AST* star = createAST(0, "*"); push((yyvsp[0].a), {star}); (yyval.a) = (yyvsp[0].a); }
#line 2064 "c.tab.cpp"
    break;

  case 93:
#line 240 "c.y"
                                                                                { AST* star = createAST(0, "*"); (yyval.a) = createAST(0, "pointer", {star}); }
#line 2070 "c.tab.cpp"
    break;

  case 95:
#line 245 "c.y"
                                                { (yyval.a) = createAST(3, "type_qualifier_list", {(yyvsp[-1].a), (yyvsp[0].a)}); }
#line 2076 "c.tab.cpp"
    break;

  case 96:
#line 250 "c.y"
                                                        { AST* temp = createAST(0, "ELLIPSIS"); push((yyvsp[-2].a), {temp}); (yyval.a) = (yyvsp[-2].a); }
#line 2082 "c.tab.cpp"
    break;

  case 98:
#line 255 "c.y"
                                                                                { (yyval.a) = createAST(3, "parameters", {(yyvsp[0].a)}); }
#line 2088 "c.tab.cpp"
    break;

  case 99:
#line 256 "c.y"
                                                                { push((yyvsp[-2].a), {(yyvsp[0].a)}); (yyval.a) = (yyvsp[-2].a); }
#line 2094 "c.tab.cpp"
    break;

  case 100:
#line 260 "c.y"
                                                                        { (yyval.a) = createAST(1, "parameter_declaration", {(yyvsp[-1].a), (yyvsp[0].a)}); }
#line 2100 "c.tab.cpp"
    break;

  case 108:
#line 274 "c.y"
                                                                                { AST* temp = createAST(0, "ID", {}, (yyvsp[-2].s)); (yyval.a) = createAST(1, "labeled_statement", {temp, (yyvsp[0].a)}); }
#line 2106 "c.tab.cpp"
    break;

  case 109:
#line 278 "c.y"
                                                                        { (yyval.a) = createAST(3, "compound_statement"); }
#line 2112 "c.tab.cpp"
    break;

  case 110:
#line 279 "c.y"
                                                        { (yyval.a) = (yyvsp[-1].a); }
#line 2118 "c.tab.cpp"
    break;

  case 111:
#line 283 "c.y"
                                                                { (yyval.a) = createAST(3, "compound_statement", {(yyvsp[0].a)}); }
#line 2124 "c.tab.cpp"
    break;

  case 112:
#line 284 "c.y"
                                                { push((yyvsp[-1].a), {(yyvsp[0].a)}); (yyval.a) = (yyvsp[-1].a); }
#line 2130 "c.tab.cpp"
    break;

  case 115:
#line 293 "c.y"
                                                { (yyval.a) = createAST(0, ";"); }
#line 2136 "c.tab.cpp"
    break;

  case 116:
#line 294 "c.y"
                                        { (yyval.a) = (yyvsp[-1].a); }
#line 2142 "c.tab.cpp"
    break;

  case 117:
#line 298 "c.y"
                                                                        { (yyval.a) = createAST(1, "ifte", {(yyvsp[-4].a), (yyvsp[-2].a), (yyvsp[0].a)}); }
#line 2148 "c.tab.cpp"
    break;

  case 118:
#line 299 "c.y"
                                                                                        { (yyval.a) = createAST(1, "ifte", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 2154 "c.tab.cpp"
    break;

  case 119:
#line 303 "c.y"
                                                                                                                                        { (yyval.a) = createAST(1, "while", {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 2160 "c.tab.cpp"
    break;

  case 120:
#line 307 "c.y"
                                                { AST* temp1 = createAST(0, "GOTO"); AST* temp2 = createAST(0, "ID", {}, (yyvsp[-1].s)); (yyval.a) = createAST(1, "jump", {temp1, temp2});}
#line 2166 "c.tab.cpp"
    break;

  case 121:
#line 308 "c.y"
                                                        { AST* temp1 = createAST(0, "CONTINUE"); (yyval.a) = createAST(1, "jump", {temp1});}
#line 2172 "c.tab.cpp"
    break;

  case 122:
#line 309 "c.y"
                                                                { AST* temp1 = createAST(0, "BREAK"); (yyval.a) = createAST(1, "jump", {temp1});}
#line 2178 "c.tab.cpp"
    break;

  case 123:
#line 310 "c.y"
                                                        { AST* temp1 = createAST(0, "RETURN"); (yyval.a) = createAST(1, "jump", {temp1});}
#line 2184 "c.tab.cpp"
    break;

  case 124:
#line 311 "c.y"
                                                { AST* temp1 = createAST(0, "RETURN"); (yyval.a) = createAST(1, "jump", {temp1, (yyvsp[-1].a)});}
#line 2190 "c.tab.cpp"
    break;

  case 125:
#line 315 "c.y"
                                        { ast_root = (yyvsp[0].a); (yyval.a) = (yyvsp[0].a); }
#line 2196 "c.tab.cpp"
    break;

  case 126:
#line 319 "c.y"
                                                                        { (yyval.a) = createAST(1, "PROGRAM", {(yyvsp[0].a)}); }
#line 2202 "c.tab.cpp"
    break;

  case 127:
#line 320 "c.y"
                                                        { AST* root = (yyvsp[-1].a); push(root, {(yyvsp[0].a)}); (yyval.a) = root; }
#line 2208 "c.tab.cpp"
    break;

  case 129:
#line 325 "c.y"
                                                                                { (yyval.a) = createAST(1, "global", {(yyvsp[0].a)}); }
#line 2214 "c.tab.cpp"
    break;

  case 130:
#line 329 "c.y"
                                                                                                        { (yyval.a) = createAST(1, "FUNC", {(yyvsp[-2].a), (yyvsp[-1].a), (yyvsp[0].a)}); }
#line 2220 "c.tab.cpp"
    break;


#line 2224 "c.tab.cpp"

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
#line 332 "c.y"

#include <stdio.h>

void yyerror(const char *s)
{
	fflush(stdout);
	fprintf(stderr, "*** %s\n", s);
}
