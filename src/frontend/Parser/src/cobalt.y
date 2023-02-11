%{
#include <stdio.h>

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
%token CHAR INT FLOAT DOUBLE SHORT LONG 
%token IF ELSE SWITCH CASE WHILE FOR DO BREAK CONTINUE GOTO IMPORT 
%token NUM REAL CH STRING 
%token ADD SUB TIMES DIV MOD 
%token GEQ GREATER LEQ LESS EQUAL NEQUAL 
%token INC DEC 
%token BITAND BITOR BITXOR LSHIFT RSHIFT COMPLE 
%token ADDAGN SUBAGN TIMAGN DIVAGN MODAGN LSHAGN RSHAGN BANDAGN BXORAGN BORAGN AGN 
%token QUES  
%token LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE 
%token COLON SEMICOLON COMMA DOT 
%token EMPTY ID
%start stm
%%
stm 
: IMPORT ID SEMICOLON {
    printf("import identifier,%d\n",ID);
};
| IMPORT SEMICOLON {
    printf("import identifier\n");
};
| EMPTY {
    printf("Nothing\n");
};
%%
