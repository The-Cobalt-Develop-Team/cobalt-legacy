/*
    Test program of the Cobalt Compiler
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
// #include "../include/tokens.h"
#include "../include/util.h"
#include "cobalt.tab.h"

YYSTYPE yylval;

int yylex(void);

C_string toknames[] = {
    "YYUNDEF",
    "BUILTINTYPE",
    "IF",
    "ELSE",
    "SWITCH",
    "CASE",
    "WHILE",
    "FOR",
    "DO",
    "BREAK",
    "CONTINUE",
    "GOTO",
    "IMPORT",
    "ADD",
    "SUB",
    "TIMES",
    "DIV",
    "MOD",
    "GEQ",
    "GREATER",
    "LEQ",
    "LESS",
    "EQUAL",
    "NEQUAL",
    "INC",
    "DEC",
    "BITAND",
    "BITOR",
    "BITXOR",
    "LSHIFT",
    "RSHIFT",
    "COMPLE",
    "ADDAGN",
    "SUBAGN",
    "TIMAGN",
    "DIVAGN",
    "MODAGN",
    "LSHAGN",
    "RSHAGN",
    "BANDAGN",
    "BXORAGN",
    "BORAGN",
    "AGN",
    "QUES",
    "LPAREN",
    "RPAREN",
    "LBRACK",
    "RBRACK",
    "LBRACE",
    "RBRACE",
    "COLON",
    "SEMICOLON",
    "COMMA",
    "DOT",
    "ID",
    "NUM",
    "REAL",
    "CH",
    "STRING"
};

C_string tokname(int tok)
{
    return tok < 1 || tok > 400 ? "BAD_TOKEN" : toknames[tok - 257];
}

int main(int argc, char** argv)
{
    // C_string fname = NULL;
    int tok = 0;
    // if (argc != 2) {
    //     fprintf(stderr, "usage: a.out filename\n");
    //     exit(1);
    // }
    // fname = argv[1];
    while (1) {
        tok = yylex();
        if (tok == 0) {
            break;
        }
        switch (tok) {
        case ID:
            printf("%10s %s\n", tokname(tok), yylval.sval);
            break;
        case STRING:
            printf("%10s %s\n", tokname(tok), yylval.sval);
            break;
        case NUM:
            printf("%10s %d\n", tokname(tok), yylval.ival);
            break;
        default:
            printf("%10s\n", tokname(tok));
            break;
        }
    }
}