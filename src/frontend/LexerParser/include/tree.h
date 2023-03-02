#include "util.h"
/*This Program is **just for test**, DO NOT COMPILE IT IN RELEASE VERSION*/
#if LP_DEBUG
#ifndef LPT_TREE_H
#define LPT_TREE_H

typedef struct _identifier_ {
    C_string name;
} Identifier;

typedef struct _addop_ {
    C_string name;
    Identifier value;
    void *l, *r;
} AddOp;

void* addAddOp(Identifier* l, Identifier* r);
void* addIdentifier(C_string s);
#endif
#endif