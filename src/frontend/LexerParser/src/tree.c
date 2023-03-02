/*This Program is **just for test**, DO NOT COMPILE IT IN RELEASE VERSION*/

#include "../include/tree.h"

void* addAddOp(Identifier* l, Identifier* r)
{
    AddOp* AddOp_ptr = malloc(sizeof(AddOp));
    AddOp_ptr->l = l;
    AddOp_ptr->r = r;
    sprintf(AddOp_ptr->name, "AddOp for %s and %s", l->name, r->name);
    printf("Add a Add Op: l:%s, r:%s\n", l->name, r->name);
    return AddOp_ptr;
}

void* addIdentifier(C_string s)
{
    AddOp* ID_ptr = malloc(sizeof(Identifier));
    ID_ptr->name = s;
    printf("Add an identifier:%s\n", s);
    return ID_ptr;
}