/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_COBALT_TAB_H_INCLUDED
# define YY_YY_COBALT_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    CHAR = 258,                    /* CHAR  */
    INT = 259,                     /* INT  */
    FLOAT = 260,                   /* FLOAT  */
    DOUBLE = 261,                  /* DOUBLE  */
    SHORT = 262,                   /* SHORT  */
    LONG = 263,                    /* LONG  */
    IF = 264,                      /* IF  */
    ELSE = 265,                    /* ELSE  */
    SWITCH = 266,                  /* SWITCH  */
    CASE = 267,                    /* CASE  */
    WHILE = 268,                   /* WHILE  */
    FOR = 269,                     /* FOR  */
    DO = 270,                      /* DO  */
    BREAK = 271,                   /* BREAK  */
    CONTINUE = 272,                /* CONTINUE  */
    GOTO = 273,                    /* GOTO  */
    IMPORT = 274,                  /* IMPORT  */
    ADD = 275,                     /* ADD  */
    SUB = 276,                     /* SUB  */
    TIMES = 277,                   /* TIMES  */
    DIV = 278,                     /* DIV  */
    MOD = 279,                     /* MOD  */
    GEQ = 280,                     /* GEQ  */
    GREATER = 281,                 /* GREATER  */
    LEQ = 282,                     /* LEQ  */
    LESS = 283,                    /* LESS  */
    EQUAL = 284,                   /* EQUAL  */
    NEQUAL = 285,                  /* NEQUAL  */
    INC = 286,                     /* INC  */
    DEC = 287,                     /* DEC  */
    BITAND = 288,                  /* BITAND  */
    BITOR = 289,                   /* BITOR  */
    BITXOR = 290,                  /* BITXOR  */
    LSHIFT = 291,                  /* LSHIFT  */
    RSHIFT = 292,                  /* RSHIFT  */
    COMPLE = 293,                  /* COMPLE  */
    ADDAGN = 294,                  /* ADDAGN  */
    SUBAGN = 295,                  /* SUBAGN  */
    TIMAGN = 296,                  /* TIMAGN  */
    DIVAGN = 297,                  /* DIVAGN  */
    MODAGN = 298,                  /* MODAGN  */
    LSHAGN = 299,                  /* LSHAGN  */
    RSHAGN = 300,                  /* RSHAGN  */
    BANDAGN = 301,                 /* BANDAGN  */
    BXORAGN = 302,                 /* BXORAGN  */
    BORAGN = 303,                  /* BORAGN  */
    AGN = 304,                     /* AGN  */
    QUES = 305,                    /* QUES  */
    LPAREN = 306,                  /* LPAREN  */
    RPAREN = 307,                  /* RPAREN  */
    LBRACK = 308,                  /* LBRACK  */
    RBRACK = 309,                  /* RBRACK  */
    LBRACE = 310,                  /* LBRACE  */
    RBRACE = 311,                  /* RBRACE  */
    COLON = 312,                   /* COLON  */
    SEMICOLON = 313,               /* SEMICOLON  */
    COMMA = 314,                   /* COMMA  */
    DOT = 315,                     /* DOT  */
    ID = 316,                      /* ID  */
    NUM = 317,                     /* NUM  */
    REAL = 318,                    /* REAL  */
    CH = 319,                      /* CH  */
    STRING = 320                   /* STRING  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 25 "cobalt.y"
int ival; double fval; char cval; C_string sval;

#line 132 "cobalt.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_COBALT_TAB_H_INCLUDED  */
