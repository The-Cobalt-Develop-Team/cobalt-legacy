/*
    The lexical analyser of the Cobalt Compiler
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
%{
/*C Declarations*/
#include "../include/tokens.h"
#include "../include/errormsg.h"
union {
    int lval;
    C_string sval;
    double fval;
} yylval;
#define ADJ (EM_tokpos=charPos, charPos+=yyleng)
%}
/*Lex Definitions*/
digits [0-9]+
%%
/*Regular Expressions and Actions*/
if {
    ADJ;
    return IF;
}
else {
    ADJ;
    return ELSE;
}
switch {
    ADJ;
    return SWITCH;
}
case {
    ADJ;
    return CASE;
}
while {
    ADJ;
    return WHILE;
}
for {
    ADJ;
    return FOR;
}
do {
    ADJ;
    return DO;
}
break {
    ADJ;
    return BREAK;
}
continue {
    ADJ;
    return CONTINUE;
}
goto {
    ADJ;
    return GOTO;
}
import {
    ADJ;
    return IMPORT;
}
{digits} {
    ADJ;
    yylval.ival=atoi(yytext);
    return NUM;
}
({digits}"."[0-9]*)|([0-9]*"."{digits}) {
    ADJ;
    yylval.fval=atof(yytext);
    return REAL;
}
("'"."'")|("'\\"[a-z0-9]+"'") {
    ADJ;
    yylval.sval = C_String(yytext);
    return CH;
}
"+" {
    ADJ;
    return ADD;
}
""
[a-zA-Z][a-zA-Z0-9]* {
    ADJ;
    yylval.sval = C_String(yytext);
    return ID;
}