flex cobalt.lex
bison -d cobalt.y
gcc driver.c util.c lex.yy.c -o lextest.out -lfl
gcc cobalt.tab.c lex.yy.c util.c -o yacctest.out