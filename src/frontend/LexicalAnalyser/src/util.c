#include "../include/util.h"

void* checked_malloc(int len)
{
    void* p = malloc(len);
    assert(p);
    return p;
}

C_string C_String(char* s)
{
    C_string p = checked_malloc(strlen(s) + 1);
    strcpy(p, s);
    return p;
}