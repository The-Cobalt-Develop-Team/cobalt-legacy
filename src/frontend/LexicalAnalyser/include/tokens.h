/*
    Tokens header of the Cobalt Compiler
    Copyright (C) 2023  Andy Shen

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#include "util.h"
enum TOKENS {
    /*Types*/
    ERROR,
    CHAR = 258,
    INT,
    FLOAT,
    DOUBLE,
    SHORT,
    LONG,
    /*Statements*/
    IF,
    ELSE,
    SWITCH,
    CASE,
    WHILE,
    FOR,
    DO,
    BREAK,
    CONTINUE,
    GOTO,
    IMPORT,
    /*Constants*/
    NUM,
    REAL,
    CH,
    STRING,
    /*Arithmetic Operators*/
    ADD,
    SUB,
    TIMES,
    DIV,
    MOD,
    /*Relational and Logical Operators*/
    GEQ,
    GREATER,
    LEQ,
    LESS,
    EQUAL,
    NEQUAL,
    /*Increment and Decrement Operators*/
    INC,
    DEC,
    /*Bitwise Operators*/
    BITAND,
    BITOR,
    BITXOR,
    LSHIFT,
    RSHIFT,
    COMPLE,
    /*Assignment Operators*/
    ADDAGN,
    SUBAGN,
    TIMAGN,
    DIVAGN,
    MODAGN,
    LSHAGN,
    RSHAGN,
    BANDAGN,
    BXORAGN,
    BORAGN,
    AGN,
    /*Conditional Expressions(Ternary Operator)*/
    QUES, /* "?" */
    /*Parentheses*/
    LPAREN,
    RPAREN,
    LBRACK,
    RBRACK,
    LBRACE,
    RBRACE,
    /*Symbol*/
    COLON,
    SEMICOLON,
    COMMA,
    DOT,
    /*Other*/
    EMPTY,
    ID
};
typedef union {
    int pos;
    int ival;
    C_string sval;
    double fval;
} YYTYPE;

extern YYTYPE yylval;