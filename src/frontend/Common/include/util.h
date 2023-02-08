#include <assert.h>
#include <stdlib.h>

typedef char* C_string;
C_string C_String(char*);

typedef char C_bool;
#define TRUE 1
#define FALSE 0

void* checked_malloc(int);