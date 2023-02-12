#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* C_string;
C_string C_String(char* s);

typedef char C_bool;
#define TRUE 1
#define FALSE 0

void* checked_malloc(int);