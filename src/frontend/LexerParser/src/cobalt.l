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
// #include "../include/tokens.h"
#include "../include/errormsg.h"
#include "../include/util.h"
#include "cobalt.tab.h"
int charPos = 1;
#define ADJ (EM_tokpos=charPos, charPos+=yyleng)
%}
/*Lex Definitions*/
digits [0-9]+
/*Regular Expressions and Actions*/
%%
char {
    ADJ;
    yylval.sval = C_String(yytext);
    return BUILTINTYPE;
}
int {
    ADJ;
    yylval.sval = C_String(yytext);
    return BUILTINTYPE;
}
float {
    ADJ;
    yylval.sval = C_String(yytext);
    return BUILTINTYPE;
}
double {
    ADJ;
    yylval.sval = C_String(yytext);
    return BUILTINTYPE;
}
short {
    ADJ;
    yylval.sval = C_String(yytext);
    return BUILTINTYPE;
}
long {
    ADJ;
    yylval.sval = C_String(yytext);
    return BUILTINTYPE;
}
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
"\"".*"\"" {
    ADJ;
    yylval.sval = C_String(yytext);
    return STRING;
}
"+" {
    ADJ;
    return ADD;
}
"-" {
    ADJ;
    return SUB;
}
"*" {
    ADJ;
    return TIMES;
}
"/" {
    ADJ;
    return DIV;
}
"%" {
    ADJ;
    return MOD;
}
">=" {
    ADJ;
    return GEQ;
}
">" {
    ADJ;
    return GREATER;
}
"<=" {
    ADJ;
    return LEQ;
}
"<" {
    ADJ;
    return LESS;
}
"==" {
    ADJ;
    return EQUAL;
}
"!=" {
    ADJ;
    return NEQUAL;
}
"++" {
    ADJ;
    return INC;
}
"--" {
    ADJ;
    return DEC;
}
"+=" {
    ADJ;
    return ADDAGN;
}
"-=" {
    ADJ;
    return SUBAGN;
}
"*=" {
    ADJ;
    return TIMAGN;
}
"/=" {
    ADJ;
    return DIVAGN;
}
"%=" {
    ADJ;
    return MODAGN;
}
"<<=" {
    ADJ;
    return LSHAGN;
}
">>=" {
    ADJ;
    return RSHAGN;
}
"&=" {
    ADJ;
    return BANDAGN;
}
"^=" {
    ADJ;
    return BXORAGN;
}
"|=" {
    ADJ;
    return BORAGN;
}
"=" {
    ADJ;
    return AGN;
}
"?" {
    ADJ;
    return QUES;
}
"(" {
    ADJ;
    return LPAREN;
}
")" {
    ADJ;
    return RPAREN;
}
"[" {
    ADJ;
    return LBRACK;
}
"]" {
    ADJ;
    return RBRACK;
}
"{" {
    ADJ;
    return LBRACE;
}
"}" {
    ADJ;
    return RBRACE;
}
":" {
    ADJ;
    return COLON;
}
";" {
    ADJ;
    return SEMICOLON;
}
"," {
    ADJ;
    return COMMA;
}
"." {
    ADJ;
    return DOT;
}
[a-zA-Z][a-zA-Z0-9]* {
    ADJ;
    yylval.sval = C_String(yytext);
    return ID;
}

