%{
#include <stdio.h>
#include "../include/util.h"

extern int yylex(void);

extern int yyparse(void);

int yywrap()
{
    return 1;
}

void yyerror(const char *s)
{
    printf("[error] %s\n",s);
}

int main()
{
    yyparse();
    return 0;
}
%}
%union {int ival; double fval; char cval; C_string sval;}
%token CHAR INT FLOAT DOUBLE SHORT LONG 
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
%left ADD SUB
%left TIMES DIV
%type <ival> numexp 
%start prog
%%
prog : stm

stm 
: stm SEMICOLON stm
| stm SEMICOLON
| IMPORT ID {
    printf("import identifier,%s\n",$2);
};
| ID AGN numexp {   // Assign a valuable
    printf("Identifier:%s, assign to %d\n",$1,$3);
};
| INT ID AGN numexp {
    printf("Declare an Integer, name is %s",$2);
};

numexp
: NUM {
    $$ = $1;
}
| ID {
    $$ = 1; //Temporary Value
};
| numexp ADD numexp {
    $$ = $1 + $3;
};
| numexp SUB numexp {
    $$ = $1 - $3;
};
| numexp TIMES numexp {
    $$ = $1 * $3;
};
| numexp DIV numexp {
    $$ = $1 / $3;
};
%%