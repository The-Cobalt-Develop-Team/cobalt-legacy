flex src/cobalt.lex
bison -d src/cobalt.y
mv cobalt.tab.c cobalt.tab.h lex.yy.c src/
gcc src/driver.c src/util.c src/lex.yy.c -o bin/lextest.out -lfl
gcc src/cobalt.tab.c src/lex.yy.c src/util.c src/tree.c src/main.c -o bin/yacctest.out