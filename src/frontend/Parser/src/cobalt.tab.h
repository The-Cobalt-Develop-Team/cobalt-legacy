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
    NUM = 275,                     /* NUM  */
    REAL = 276,                    /* REAL  */
    CH = 277,                      /* CH  */
    STRING = 278,                  /* STRING  */
    ADD = 279,                     /* ADD  */
    SUB = 280,                     /* SUB  */
    TIMES = 281,                   /* TIMES  */
    DIV = 282,                     /* DIV  */
    MOD = 283,                     /* MOD  */
    GEQ = 284,                     /* GEQ  */
    GREATER = 285,                 /* GREATER  */
    LEQ = 286,                     /* LEQ  */
    LESS = 287,                    /* LESS  */
    EQUAL = 288,                   /* EQUAL  */
    NEQUAL = 289,                  /* NEQUAL  */
    INC = 290,                     /* INC  */
    DEC = 291,                     /* DEC  */
    BITAND = 292,                  /* BITAND  */
    BITOR = 293,                   /* BITOR  */
    BITXOR = 294,                  /* BITXOR  */
    LSHIFT = 295,                  /* LSHIFT  */
    RSHIFT = 296,                  /* RSHIFT  */
    COMPLE = 297,                  /* COMPLE  */
    ADDAGN = 298,                  /* ADDAGN  */
    SUBAGN = 299,                  /* SUBAGN  */
    TIMAGN = 300,                  /* TIMAGN  */
    DIVAGN = 301,                  /* DIVAGN  */
    MODAGN = 302,                  /* MODAGN  */
    LSHAGN = 303,                  /* LSHAGN  */
    RSHAGN = 304,                  /* RSHAGN  */
    BANDAGN = 305,                 /* BANDAGN  */
    BXORAGN = 306,                 /* BXORAGN  */
    BORAGN = 307,                  /* BORAGN  */
    AGN = 308,                     /* AGN  */
    QUES = 309,                    /* QUES  */
    LPAREN = 310,                  /* LPAREN  */
    RPAREN = 311,                  /* RPAREN  */
    LBRACK = 312,                  /* LBRACK  */
    RBRACK = 313,                  /* RBRACK  */
    LBRACE = 314,                  /* LBRACE  */
    RBRACE = 315,                  /* RBRACE  */
    COLON = 316,                   /* COLON  */
    SEMICOLON = 317,               /* SEMICOLON  */
    COMMA = 318,                   /* COMMA  */
    DOT = 319,                     /* DOT  */
    EMPTY = 320,                   /* EMPTY  */
    ID = 321                       /* ID  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_COBALT_TAB_H_INCLUDED  */
