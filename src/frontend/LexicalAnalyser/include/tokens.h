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
#include "../../Common/include/util.h"
enum TOKENS {
    /*Types*/
    CHAR,
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
    /*Arithmetic Operators*/
    ADD,
    SUB,
    TIMES,
    DIV,
    MOD,
    /*Relational and Logical Operators*/
    GREATER,
    GEQ,
    LESS,
    LEQ,
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
    AGN,
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
    /*Conditional Expressions(Ternary Operator)*/
    QUES, /* "?" */
    OTH, /* ":" */
    /*Other*/
    ID
};