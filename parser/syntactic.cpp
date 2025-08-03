/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Substitute the type names.  */
#define YYSTYPE         M68KASM_STYPE
/* Substitute the variable and function names.  */
#define yyparse         m68kasm_parse
#define yylex           m68kasm_lex
#define yyerror         m68kasm_error
#define yydebug         m68kasm_debug
#define yynerrs         m68kasm_nerrs


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

#include "syntactic.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOKEN_DIRECTIVE_DC = 3,         /* TOKEN_DIRECTIVE_DC  */
  YYSYMBOL_TOKEN_DIRECTIVE_EVEN = 4,       /* TOKEN_DIRECTIVE_EVEN  */
  YYSYMBOL_TOKEN_SIZE_BYTE = 5,            /* TOKEN_SIZE_BYTE  */
  YYSYMBOL_TOKEN_SIZE_SHORT = 6,           /* TOKEN_SIZE_SHORT  */
  YYSYMBOL_TOKEN_SIZE_WORD = 7,            /* TOKEN_SIZE_WORD  */
  YYSYMBOL_TOKEN_SIZE_LONGWORD = 8,        /* TOKEN_SIZE_LONGWORD  */
  YYSYMBOL_TOKEN_NUMBER = 9,               /* TOKEN_NUMBER  */
  YYSYMBOL_TOKEN_IDENTIFIER = 10,          /* TOKEN_IDENTIFIER  */
  YYSYMBOL_TOKEN_LOCAL_IDENTIFIER = 11,    /* TOKEN_LOCAL_IDENTIFIER  */
  YYSYMBOL_TOKEN_LOGICAL_AND = 12,         /* TOKEN_LOGICAL_AND  */
  YYSYMBOL_TOKEN_LOGICAL_OR = 13,          /* TOKEN_LOGICAL_OR  */
  YYSYMBOL_TOKEN_EQUALITY = 14,            /* TOKEN_EQUALITY  */
  YYSYMBOL_TOKEN_INEQUALITY = 15,          /* TOKEN_INEQUALITY  */
  YYSYMBOL_TOKEN_LESS_OR_EQUAL = 16,       /* TOKEN_LESS_OR_EQUAL  */
  YYSYMBOL_TOKEN_MORE_OR_EQUAL = 17,       /* TOKEN_MORE_OR_EQUAL  */
  YYSYMBOL_TOKEN_LEFT_SHIFT = 18,          /* TOKEN_LEFT_SHIFT  */
  YYSYMBOL_TOKEN_RIGHT_SHIFT = 19,         /* TOKEN_RIGHT_SHIFT  */
  YYSYMBOL_20_ = 20,                       /* ','  */
  YYSYMBOL_21_ = 21,                       /* '='  */
  YYSYMBOL_22_ = 22,                       /* '<'  */
  YYSYMBOL_23_ = 23,                       /* '>'  */
  YYSYMBOL_24_ = 24,                       /* '+'  */
  YYSYMBOL_25_ = 25,                       /* '-'  */
  YYSYMBOL_26_ = 26,                       /* '*'  */
  YYSYMBOL_27_ = 27,                       /* '/'  */
  YYSYMBOL_28_ = 28,                       /* '%'  */
  YYSYMBOL_29_ = 29,                       /* '&'  */
  YYSYMBOL_30_ = 30,                       /* '!'  */
  YYSYMBOL_31_ = 31,                       /* '|'  */
  YYSYMBOL_32_ = 32,                       /* '^'  */
  YYSYMBOL_33_ = 33,                       /* '~'  */
  YYSYMBOL_34_ = 34,                       /* '('  */
  YYSYMBOL_35_ = 35,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 36,                  /* $accept  */
  YYSYMBOL_statement = 37,                 /* statement  */
  YYSYMBOL_expression_list = 38,           /* expression_list  */
  YYSYMBOL_size = 39,                      /* size  */
  YYSYMBOL_expression = 40,                /* expression  */
  YYSYMBOL_expression1 = 41,               /* expression1  */
  YYSYMBOL_expression2 = 42,               /* expression2  */
  YYSYMBOL_expression3 = 43,               /* expression3  */
  YYSYMBOL_expression4 = 44,               /* expression4  */
  YYSYMBOL_expression5 = 45,               /* expression5  */
  YYSYMBOL_expression6 = 46,               /* expression6  */
  YYSYMBOL_expression7 = 47,               /* expression7  */
  YYSYMBOL_expression8 = 48                /* expression8  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;



/* Unqualified %code blocks.  */
#line 146 "syntactic.y"


#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int m68kasm_lex(M68KASM_STYPE *yylval_param, void *yyscanner);
void m68kasm_warning(void *scanner, Statement *statement, const char *message);
void m68kasm_warning_pedantic(void *scanner, Statement *statement, const char *message);
void m68kasm_error(void *scanner, Statement *statement, const char *message);

static bool DoExpressionTriple(Expression *expression, ExpressionType type, Expression *left_expression, Expression *middle_expression, Expression *right_expression);
static bool DoExpression(Expression *expression, ExpressionType type, Expression *left_expression, Expression *right_expression);
static void DestroyExpressionList(ExpressionList *list);


#line 176 "syntactic.cpp"

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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined M68KASM_STYPE_IS_TRIVIAL && M68KASM_STYPE_IS_TRIVIAL)))

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   65

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  44
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  74

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   274


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,     2,     2,     2,    28,    29,     2,
      34,    35,    26,    24,    20,    25,     2,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      22,    21,    23,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    32,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    31,     2,    33,     2,     2,     2,
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
      15,    16,    17,    18,    19
};

#if M68KASM_DEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   205,   205,   208,   214,   221,   238,   266,   270,   274,
     278,   291,   296,   302,   310,   314,   319,   324,   332,   336,
     341,   346,   351,   359,   363,   368,   376,   380,   385,   390,
     398,   402,   407,   412,   417,   425,   429,   434,   442,   446,
     450,   455,   461,   469,   474
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TOKEN_DIRECTIVE_DC",
  "TOKEN_DIRECTIVE_EVEN", "TOKEN_SIZE_BYTE", "TOKEN_SIZE_SHORT",
  "TOKEN_SIZE_WORD", "TOKEN_SIZE_LONGWORD", "TOKEN_NUMBER",
  "TOKEN_IDENTIFIER", "TOKEN_LOCAL_IDENTIFIER", "TOKEN_LOGICAL_AND",
  "TOKEN_LOGICAL_OR", "TOKEN_EQUALITY", "TOKEN_INEQUALITY",
  "TOKEN_LESS_OR_EQUAL", "TOKEN_MORE_OR_EQUAL", "TOKEN_LEFT_SHIFT",
  "TOKEN_RIGHT_SHIFT", "','", "'='", "'<'", "'>'", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'&'", "'!'", "'|'", "'^'", "'~'", "'('", "')'", "$accept",
  "statement", "expression_list", "size", "expression", "expression1",
  "expression2", "expression3", "expression4", "expression5",
  "expression6", "expression7", "expression8", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-13)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      23,    27,   -13,    18,   -13,   -13,   -13,   -13,    -5,   -13,
     -13,    -5,    -5,    -5,    -5,    -5,    45,     2,    -8,    -6,
      33,    10,    12,    41,   -13,   -13,   -13,   -13,   -13,   -13,
      -4,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,   -13,     2,    -8,    -8,    -6,    -6,    -6,    33,
      33,    33,    33,    10,    10,    12,    12,    12,    41,    41,
      41,    41,   -13,   -13
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     4,     0,     7,     8,     9,    10,     0,     1,
      43,     0,     0,     0,     0,     0,     3,     5,    11,    14,
      18,    23,    26,    30,    35,    38,    39,    40,    42,    41,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    44,     6,    12,    13,    16,    17,    15,    20,
      22,    19,    21,    24,    25,    27,    28,    29,    31,    32,
      33,    34,    36,    37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -13,   -13,   -13,   -13,   -10,    29,   -12,     8,    22,    11,
       3,   -11,   -13
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,    16,     8,    17,    18,    19,    20,    21,    22,
      23,    24,    25
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      26,    27,    28,    29,    10,    30,    34,    35,    32,    33,
      37,    38,     0,    36,    32,    33,    39,    40,     9,    11,
      12,    53,    56,    57,    58,    13,     1,     2,    14,    15,
       0,    52,     4,     5,     6,     7,    43,    44,    45,    72,
      73,    46,    47,    48,    49,    59,    60,    61,    62,    68,
      69,    70,    71,     0,    65,    66,    67,    41,    42,    50,
      51,    54,    55,    63,    64,    31
};

static const yytype_int8 yycheck[] =
{
      11,    12,    13,    14,     9,    15,    14,    15,    12,    13,
      16,    17,    -1,    21,    12,    13,    22,    23,     0,    24,
      25,    31,    34,    35,    36,    30,     3,     4,    33,    34,
      -1,    35,     5,     6,     7,     8,    26,    27,    28,    50,
      51,    29,    30,    31,    32,    37,    38,    39,    40,    46,
      47,    48,    49,    -1,    43,    44,    45,    24,    25,    18,
      19,    32,    33,    41,    42,    20
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,    37,     5,     6,     7,     8,    39,     0,
       9,    24,    25,    30,    33,    34,    38,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    47,    47,    47,    47,
      40,    20,    12,    13,    14,    15,    21,    16,    17,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      18,    19,    35,    40,    41,    41,    42,    42,    42,    43,
      43,    43,    43,    44,    44,    45,    45,    45,    46,    46,
      46,    46,    47,    47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    37,    37,    38,    38,    39,    39,    39,
      39,    40,    40,    40,    41,    41,    41,    41,    42,    42,
      42,    42,    42,    43,    43,    43,    44,    44,    44,    44,
      45,    45,    45,    45,    45,    46,    46,    46,    47,    47,
      47,    47,    47,    48,    48
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     1,     1,     3,     1,     1,     1,
       1,     1,     3,     3,     1,     3,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     2,
       2,     2,     2,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = M68KASM_EMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == M68KASM_EMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (scanner, statement, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use M68KASM_error or M68KASM_UNDEF. */
#define YYERRCODE M68KASM_UNDEF


/* Enable debugging if requested.  */
#if M68KASM_DEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, scanner, statement); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void *scanner, Statement *statement)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (scanner);
  YY_USE (statement);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void *scanner, Statement *statement)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, scanner, statement);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, void *scanner, Statement *statement)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], scanner, statement);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, scanner, statement); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !M68KASM_DEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !M68KASM_DEBUG */


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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
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
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
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


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, void *scanner, Statement *statement)
{
  YY_USE (yyvaluep);
  YY_USE (scanner);
  YY_USE (statement);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yykind)
    {
    case YYSYMBOL_TOKEN_IDENTIFIER: /* TOKEN_IDENTIFIER  */
#line 195 "syntactic.y"
            { String_Destroy(&((*yyvaluep).string)); }
#line 1185 "syntactic.cpp"
        break;

    case YYSYMBOL_TOKEN_LOCAL_IDENTIFIER: /* TOKEN_LOCAL_IDENTIFIER  */
#line 195 "syntactic.y"
            { String_Destroy(&((*yyvaluep).string)); }
#line 1191 "syntactic.cpp"
        break;

    case YYSYMBOL_expression_list: /* expression_list  */
#line 196 "syntactic.y"
            { DestroyExpressionList(&((*yyvaluep).expression_list)); }
#line 1197 "syntactic.cpp"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 197 "syntactic.y"
            { DestroyExpression(&((*yyvaluep).expression)); }
#line 1203 "syntactic.cpp"
        break;

    case YYSYMBOL_expression1: /* expression1  */
#line 197 "syntactic.y"
            { DestroyExpression(&((*yyvaluep).expression)); }
#line 1209 "syntactic.cpp"
        break;

    case YYSYMBOL_expression2: /* expression2  */
#line 197 "syntactic.y"
            { DestroyExpression(&((*yyvaluep).expression)); }
#line 1215 "syntactic.cpp"
        break;

    case YYSYMBOL_expression3: /* expression3  */
#line 197 "syntactic.y"
            { DestroyExpression(&((*yyvaluep).expression)); }
#line 1221 "syntactic.cpp"
        break;

    case YYSYMBOL_expression4: /* expression4  */
#line 197 "syntactic.y"
            { DestroyExpression(&((*yyvaluep).expression)); }
#line 1227 "syntactic.cpp"
        break;

    case YYSYMBOL_expression5: /* expression5  */
#line 197 "syntactic.y"
            { DestroyExpression(&((*yyvaluep).expression)); }
#line 1233 "syntactic.cpp"
        break;

    case YYSYMBOL_expression6: /* expression6  */
#line 197 "syntactic.y"
            { DestroyExpression(&((*yyvaluep).expression)); }
#line 1239 "syntactic.cpp"
        break;

    case YYSYMBOL_expression7: /* expression7  */
#line 197 "syntactic.y"
            { DestroyExpression(&((*yyvaluep).expression)); }
#line 1245 "syntactic.cpp"
        break;

    case YYSYMBOL_expression8: /* expression8  */
#line 197 "syntactic.y"
            { DestroyExpression(&((*yyvaluep).expression)); }
#line 1251 "syntactic.cpp"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (void *scanner, Statement *statement)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = M68KASM_EMPTY; /* Cause a token to be read.  */

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == M68KASM_EMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, scanner);
    }

  if (yychar <= M68KASM_EOF)
    {
      yychar = M68KASM_EOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == M68KASM_error)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = M68KASM_UNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yychar = M68KASM_EMPTY;
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
  case 2: /* statement: %empty  */
#line 205 "syntactic.y"
        {
		statement->type = STATEMENT_TYPE_EMPTY;
	}
#line 1532 "syntactic.cpp"
    break;

  case 3: /* statement: TOKEN_DIRECTIVE_DC size expression_list  */
#line 209 "syntactic.y"
        {
		statement->type = STATEMENT_TYPE_DC;
		statement->shared.dc.size = (yyvsp[-1].size);
		statement->shared.dc.values = (yyvsp[0].expression_list);
	}
#line 1542 "syntactic.cpp"
    break;

  case 4: /* statement: TOKEN_DIRECTIVE_EVEN  */
#line 215 "syntactic.y"
        {
		statement->type = STATEMENT_TYPE_EVEN;
	}
#line 1550 "syntactic.cpp"
    break;

  case 5: /* expression_list: expression  */
#line 222 "syntactic.y"
        {
		ExpressionListNode *node = (ExpressionListNode*)malloc(sizeof(ExpressionListNode));

		if (node == NULL)
		{
			DestroyExpression(&(yyvsp[0].expression));
			YYNOMEM;
		}
		else
		{
			node->expression = (yyvsp[0].expression);
			node->next = NULL;
		}

		(yyval.expression_list).head = (yyval.expression_list).tail = node;
	}
#line 1571 "syntactic.cpp"
    break;

  case 6: /* expression_list: expression_list ',' expression  */
#line 239 "syntactic.y"
        {
		ExpressionListNode *node = (ExpressionListNode*)malloc(sizeof(ExpressionListNode));

		(yyval.expression_list) = (yyvsp[-2].expression_list);

		if (node == NULL)
		{
			DestroyExpressionList(&(yyvsp[-2].expression_list));
			DestroyExpression(&(yyvsp[0].expression));
			YYNOMEM;
		}
		else
		{
			node->expression = (yyvsp[0].expression);
			node->next = NULL;

			if ((yyval.expression_list).head == NULL)
				(yyval.expression_list).head = node;
			else
				((ExpressionListNode*)(yyval.expression_list).tail)->next = node;

			(yyval.expression_list).tail = node;
		}
	}
#line 1600 "syntactic.cpp"
    break;

  case 7: /* size: TOKEN_SIZE_BYTE  */
#line 267 "syntactic.y"
        {
		(yyval.size) = SIZE_BYTE;
	}
#line 1608 "syntactic.cpp"
    break;

  case 8: /* size: TOKEN_SIZE_SHORT  */
#line 271 "syntactic.y"
        {
		(yyval.size) = SIZE_SHORT;
	}
#line 1616 "syntactic.cpp"
    break;

  case 9: /* size: TOKEN_SIZE_WORD  */
#line 275 "syntactic.y"
        {
		(yyval.size) = SIZE_WORD;
	}
#line 1624 "syntactic.cpp"
    break;

  case 10: /* size: TOKEN_SIZE_LONGWORD  */
#line 279 "syntactic.y"
        {
		(yyval.size) = SIZE_LONGWORD;
	}
#line 1632 "syntactic.cpp"
    break;

  case 11: /* expression: expression1  */
#line 292 "syntactic.y"
        {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 1640 "syntactic.cpp"
    break;

  case 12: /* expression: expression TOKEN_LOGICAL_AND expression1  */
#line 297 "syntactic.y"
        {
		if (!DoExpression(&(yyval.expression), EXPRESSION_LOGICAL_AND, &(yyvsp[-2].expression), &(yyvsp[0].expression)))
			YYNOMEM;
	}
#line 1649 "syntactic.cpp"
    break;

  case 13: /* expression: expression TOKEN_LOGICAL_OR expression1  */
#line 303 "syntactic.y"
        {
		if (!DoExpression(&(yyval.expression), EXPRESSION_LOGICAL_OR, &(yyvsp[-2].expression), &(yyvsp[0].expression)))
			YYNOMEM;
	}
#line 1658 "syntactic.cpp"
    break;

  case 14: /* expression1: expression2  */
#line 311 "syntactic.y"
        {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 1666 "syntactic.cpp"
    break;

  case 15: /* expression1: expression1 '=' expression2  */
#line 315 "syntactic.y"
        {
		if (!DoExpression(&(yyval.expression), EXPRESSION_EQUALITY, &(yyvsp[-2].expression), &(yyvsp[0].expression)))
			YYNOMEM;
	}
#line 1675 "syntactic.cpp"
    break;

  case 16: /* expression1: expression1 TOKEN_EQUALITY expression2  */
#line 320 "syntactic.y"
        {
		if (!DoExpression(&(yyval.expression), EXPRESSION_EQUALITY, &(yyvsp[-2].expression), &(yyvsp[0].expression)))
			YYNOMEM;
	}
#line 1684 "syntactic.cpp"
    break;

  case 17: /* expression1: expression1 TOKEN_INEQUALITY expression2  */
#line 325 "syntactic.y"
        {
		if (!DoExpression(&(yyval.expression), EXPRESSION_INEQUALITY, &(yyvsp[-2].expression), &(yyvsp[0].expression)))
			YYNOMEM;
	}
#line 1693 "syntactic.cpp"
    break;

  case 18: /* expression2: expression3  */
#line 333 "syntactic.y"
        {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 1701 "syntactic.cpp"
    break;

  case 19: /* expression2: expression2 '<' expression3  */
#line 337 "syntactic.y"
        {
		if (!DoExpression(&(yyval.expression), EXPRESSION_LESS_THAN, &(yyvsp[-2].expression), &(yyvsp[0].expression)))
			YYNOMEM;
	}
#line 1710 "syntactic.cpp"
    break;

  case 20: /* expression2: expression2 TOKEN_LESS_OR_EQUAL expression3  */
#line 342 "syntactic.y"
        {
		if (!DoExpression(&(yyval.expression), EXPRESSION_LESS_OR_EQUAL, &(yyvsp[-2].expression), &(yyvsp[0].expression)))
			YYNOMEM;
	}
#line 1719 "syntactic.cpp"
    break;

  case 21: /* expression2: expression2 '>' expression3  */
#line 347 "syntactic.y"
        {
		if (!DoExpression(&(yyval.expression), EXPRESSION_MORE_THAN, &(yyvsp[-2].expression), &(yyvsp[0].expression)))
			YYNOMEM;
	}
#line 1728 "syntactic.cpp"
    break;

  case 22: /* expression2: expression2 TOKEN_MORE_OR_EQUAL expression3  */
#line 352 "syntactic.y"
        {
		if (!DoExpression(&(yyval.expression), EXPRESSION_MORE_OR_EQUAL, &(yyvsp[-2].expression), &(yyvsp[0].expression)))
			YYNOMEM;
	}
#line 1737 "syntactic.cpp"
    break;

  case 23: /* expression3: expression4  */
#line 360 "syntactic.y"
        {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 1745 "syntactic.cpp"
    break;

  case 24: /* expression3: expression3 '+' expression4  */
#line 364 "syntactic.y"
        {
		if (!DoExpression(&(yyval.expression), EXPRESSION_ADD, &(yyvsp[-2].expression), &(yyvsp[0].expression)))
			YYNOMEM;
	}
#line 1754 "syntactic.cpp"
    break;

  case 25: /* expression3: expression3 '-' expression4  */
#line 369 "syntactic.y"
        {
		if (!DoExpression(&(yyval.expression), EXPRESSION_SUBTRACT, &(yyvsp[-2].expression), &(yyvsp[0].expression)))
			YYNOMEM;
	}
#line 1763 "syntactic.cpp"
    break;

  case 26: /* expression4: expression5  */
#line 377 "syntactic.y"
        {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 1771 "syntactic.cpp"
    break;

  case 27: /* expression4: expression4 '*' expression5  */
#line 381 "syntactic.y"
        {
		if (!DoExpression(&(yyval.expression), EXPRESSION_MULTIPLY, &(yyvsp[-2].expression), &(yyvsp[0].expression)))
			YYNOMEM;
	}
#line 1780 "syntactic.cpp"
    break;

  case 28: /* expression4: expression4 '/' expression5  */
#line 386 "syntactic.y"
        {
		if (!DoExpression(&(yyval.expression), EXPRESSION_DIVIDE, &(yyvsp[-2].expression), &(yyvsp[0].expression)))
			YYNOMEM;
	}
#line 1789 "syntactic.cpp"
    break;

  case 29: /* expression4: expression4 '%' expression5  */
#line 391 "syntactic.y"
        {
		if (!DoExpression(&(yyval.expression), EXPRESSION_MODULO, &(yyvsp[-2].expression), &(yyvsp[0].expression)))
			YYNOMEM;
	}
#line 1798 "syntactic.cpp"
    break;

  case 30: /* expression5: expression6  */
#line 399 "syntactic.y"
        {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 1806 "syntactic.cpp"
    break;

  case 31: /* expression5: expression5 '&' expression6  */
#line 403 "syntactic.y"
        {
		if (!DoExpression(&(yyval.expression), EXPRESSION_BITWISE_AND, &(yyvsp[-2].expression), &(yyvsp[0].expression)))
			YYNOMEM;
	}
#line 1815 "syntactic.cpp"
    break;

  case 32: /* expression5: expression5 '!' expression6  */
#line 408 "syntactic.y"
        {
		if (!DoExpression(&(yyval.expression), EXPRESSION_BITWISE_OR, &(yyvsp[-2].expression), &(yyvsp[0].expression)))
			YYNOMEM;
	}
#line 1824 "syntactic.cpp"
    break;

  case 33: /* expression5: expression5 '|' expression6  */
#line 413 "syntactic.y"
        {
		if (!DoExpression(&(yyval.expression), EXPRESSION_BITWISE_OR, &(yyvsp[-2].expression), &(yyvsp[0].expression)))
			YYNOMEM;
	}
#line 1833 "syntactic.cpp"
    break;

  case 34: /* expression5: expression5 '^' expression6  */
#line 418 "syntactic.y"
        {
		if (!DoExpression(&(yyval.expression), EXPRESSION_BITWISE_XOR, &(yyvsp[-2].expression), &(yyvsp[0].expression)))
			YYNOMEM;
	}
#line 1842 "syntactic.cpp"
    break;

  case 35: /* expression6: expression7  */
#line 426 "syntactic.y"
        {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 1850 "syntactic.cpp"
    break;

  case 36: /* expression6: expression6 TOKEN_LEFT_SHIFT expression7  */
#line 430 "syntactic.y"
        {
		if (!DoExpression(&(yyval.expression), EXPRESSION_LEFT_SHIFT, &(yyvsp[-2].expression), &(yyvsp[0].expression)))
			YYNOMEM;
	}
#line 1859 "syntactic.cpp"
    break;

  case 37: /* expression6: expression6 TOKEN_RIGHT_SHIFT expression7  */
#line 435 "syntactic.y"
        {
		if (!DoExpression(&(yyval.expression), EXPRESSION_RIGHT_SHIFT, &(yyvsp[-2].expression), &(yyvsp[0].expression)))
			YYNOMEM;
	}
#line 1868 "syntactic.cpp"
    break;

  case 38: /* expression7: expression8  */
#line 443 "syntactic.y"
        {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 1876 "syntactic.cpp"
    break;

  case 39: /* expression7: '+' expression7  */
#line 447 "syntactic.y"
        {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 1884 "syntactic.cpp"
    break;

  case 40: /* expression7: '-' expression7  */
#line 451 "syntactic.y"
        {
		if (!DoExpression(&(yyval.expression), EXPRESSION_NEGATE, &(yyvsp[0].expression), NULL))
			YYNOMEM;
	}
#line 1893 "syntactic.cpp"
    break;

  case 41: /* expression7: '~' expression7  */
#line 456 "syntactic.y"
        {
		if (!DoExpression(&(yyval.expression), EXPRESSION_BITWISE_NOT, &(yyvsp[0].expression), NULL))
			YYNOMEM;
	}
#line 1902 "syntactic.cpp"
    break;

  case 42: /* expression7: '!' expression7  */
#line 462 "syntactic.y"
        {
		if (!DoExpression(&(yyval.expression), EXPRESSION_LOGICAL_NOT, &(yyvsp[0].expression), NULL))
			YYNOMEM;
	}
#line 1911 "syntactic.cpp"
    break;

  case 43: /* expression8: TOKEN_NUMBER  */
#line 470 "syntactic.y"
        {
		(yyval.expression).type = EXPRESSION_NUMBER;
		(yyval.expression).shared.unsigned_long = (yyvsp[0].unsigned_long);
	}
#line 1920 "syntactic.cpp"
    break;

  case 44: /* expression8: '(' expression ')'  */
#line 475 "syntactic.y"
        {
		(yyval.expression) = (yyvsp[-1].expression);
	}
#line 1928 "syntactic.cpp"
    break;


#line 1932 "syntactic.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == M68KASM_EMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (scanner, statement, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= M68KASM_EOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == M68KASM_EOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, scanner, statement);
          yychar = M68KASM_EMPTY;
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, scanner, statement);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (scanner, statement, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != M68KASM_EMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, scanner, statement);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, scanner, statement);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 480 "syntactic.y"


static bool DoExpressionTriple(Expression *expression, ExpressionType type, Expression *left_expression, Expression *middle_expression, Expression *right_expression)
{
	bool success = true;

	expression->type = type;

	expression->shared.subexpressions = (Expression*)malloc(sizeof(Expression) * (right_expression != NULL ? 3 : middle_expression != NULL ? 2 : 1));

	if (expression->shared.subexpressions == NULL)
	{
		DestroyExpression(left_expression);

		if (middle_expression != NULL)
			DestroyExpression(middle_expression);

		if (right_expression != NULL)
			DestroyExpression(right_expression);

		success = false;
	}
	else
	{
		expression->shared.subexpressions[0] = *left_expression;

		if (middle_expression != NULL)
			expression->shared.subexpressions[1] = *middle_expression;

		if (right_expression != NULL)
			expression->shared.subexpressions[2] = *right_expression;
	}

	return success;
}

static bool DoExpression(Expression *expression, ExpressionType type, Expression *left_expression, Expression *right_expression)
{
	return DoExpressionTriple(expression, type, left_expression, right_expression, NULL);
}

void DestroyExpression(Expression *expression)
{
	switch (expression->type)
	{
		case EXPRESSION_SUBTRACT:
		case EXPRESSION_ADD:
		case EXPRESSION_MULTIPLY:
		case EXPRESSION_DIVIDE:
		case EXPRESSION_MODULO:
		case EXPRESSION_LOGICAL_OR:
		case EXPRESSION_LOGICAL_AND:
		case EXPRESSION_BITWISE_OR:
		case EXPRESSION_BITWISE_XOR:
		case EXPRESSION_BITWISE_AND:
		case EXPRESSION_EQUALITY:
		case EXPRESSION_INEQUALITY:
		case EXPRESSION_LESS_THAN:
		case EXPRESSION_LESS_OR_EQUAL:
		case EXPRESSION_MORE_THAN:
		case EXPRESSION_MORE_OR_EQUAL:
		case EXPRESSION_LEFT_SHIFT:
		case EXPRESSION_RIGHT_SHIFT:
			DestroyExpression(&expression->shared.subexpressions[0]);
			DestroyExpression(&expression->shared.subexpressions[1]);
			free(expression->shared.subexpressions);
			break;

		case EXPRESSION_NEGATE:
		case EXPRESSION_BITWISE_NOT:
		case EXPRESSION_LOGICAL_NOT:
			DestroyExpression(&expression->shared.subexpressions[0]);
			free(expression->shared.subexpressions);
			break;

		case EXPRESSION_NUMBER:
			break;
	}
}

static void DestroyExpressionList(ExpressionList *list)
{
	ExpressionListNode *node = list->head;

	while (node != NULL)
	{
		ExpressionListNode* const next_node = node->next;

		DestroyExpression(&node->expression);

		free(node);

		node = next_node;
	}
}

void DestroyStatement(Statement *statement)
{
	switch (statement->type)
	{
		case STATEMENT_TYPE_EMPTY:
		case STATEMENT_TYPE_EVEN:
			break;

		case STATEMENT_TYPE_DC:
			DestroyExpressionList(&statement->shared.dc.values);
			break;
	}
}
