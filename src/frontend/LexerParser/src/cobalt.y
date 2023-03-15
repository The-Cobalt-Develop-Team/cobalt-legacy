/*
    The Parser of the Cobalt Compiler
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
#include <stdio.h>
#include "../include/util.h"
#include "../include/errormsg.h"
#include "../include/tree.h"
#include "../../SemanticAnalyser/AST/ASTCApi.h"
// #include "../../SemanticAnalyser/AST/ASTCApi.h"

extern int yylex(void);

extern int yyparse(void);

int yywrap()
{
    return 1;
}

void yyerror(char* ErrorMsg)
{
    // TODO: Using external Logger
    LOG_ERRORMSG(EM_tokpos,ErrorMsg);
}
%}
%union {int ival; double fval; char cval; C_string sval; void* vval;}
%token BUILTINTYPE 
%token IF ELSE SWITCH CASE WHILE FOR DO BREAK CONTINUE GOTO IMPORT 
%token ADD SUB TIMES DIV MOD 
%token GEQ GREATER LEQ LESS EQUAL NEQUAL 
%token INC DEC 
%token BITAND BITOR BITXOR LSHIFT RSHIFT COMPLE 
%token ADDAGN SUBAGN TIMAGN DIVAGN MODAGN LSHAGN RSHAGN BANDAGN BXORAGN BORAGN AGN 
%token QUES  
%token LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE 
%token COLON SEMICOLON COMMA DOT 
%token <sval> ID
%token <ival> NUM
%token <fval> REAL
%token <cval> CH
%token <sval> STRING
%right SEMICOLON
%left COMMA
%left ADDAGN SUBAGN TIMAGN DIVAGN MODAGN LSHAGN RSHAGN BANDAGN BXORAGN BORAGN AGN 
%left QUES COLON
%left BITOR
%left BITXOR
%left BITAND
%left EQUAL NEQUAL
%left GEQ GREATER LEQ LESS
%left LSHIFT RSHIFT
%left ADD SUB
%left TIMES DIV MOD
%left COMPLE
%left LPAREN RPAREN LBRACK RBRACK DOT INC DEC
%type <vval> exp 
%start prog
%%
prog : stm

stm 
: stm SEMICOLON stm
| stm SEMICOLON
| IMPORT ID {
    printf("import identifier,%s\n",$2);
};
| ID AGN exp {   /* Assign a valuable */
    printf("Identifier:%s, assign to %d\n",$1,$3);
};
| BUILTINTYPE ID AGN exp {
    printf("Declare an Value, name is %s",$2);
};

exp
: LPAREN exp LPAREN {
    $$ = $2;
}
| ID {
    $$ = addIdentifier($1);
    /* AST_AddressNodeConstructor() */
}
| NUM {
    
}
| REAL {

}
| CH {

}
| STRING {
    
}
| exp ADD exp {
    /* $$ = addAddOp($1,$3);*/
    // $$ = AST_BinaryOpNodeConstructor($1, AST_AddOp, $3);
}
| exp SUB exp {
    // $$ = AST_BinaryOpNodeConstructor($1, AST_SubOp, $3);
}
| exp TIMES exp {
    // $$ = AST_BinaryOpNodeConstructor($1, AST_TimesOp, $3);
}
| exp DIV exp {
    // $$ = AST_BinaryOpNodeConstructor($1, AST_DivOp, $3);
}
| exp MOD exp {
    // $$ = AST_BinaryOpNodeConstructor($1, AST_ModOp, $3);
}
| exp GEQ exp {
    // $$ = AST_BinaryOpNodeConstructor($1, AST_GEQOp, $3);
}
| exp GREATER exp {
    // $$ = AST_BinaryOpNodeConstructor($1, AST_GreaterOp, $3);
}
| exp LEQ exp {
    // $$ = AST_BinaryOpNodeConstructor($1, AST_LEQOp, $3);
}
| exp LESS exp {
    // $$ = AST_BinaryOpNodeConstructor($1, AST_LessOp, $3);
}
| exp EQUAL exp {
    // $$ = AST_BinaryOpNodeConstructor($1, AST_EqualOp, $3);
}
| exp NEQUAL exp {
    // $$ = AST_BinaryOpNodeConstructor($1, AST_NEqualOp, $3);
}
| INC exp {
    // $$ = AST_UnaryOpNodeConstructor(char* loc, void* expr, AST_UnaryOperatorType op);
}
| DEC exp {

}
| exp INC {

}
| exp DEC {

}
| exp BITAND exp {

}
| exp BITOR exp {
    
}
| exp BITXOR exp {
    
}
| exp LSHIFT exp {
    
}
| exp RSHIFT exp {
    
}
| COMPLE exp {

}
%%