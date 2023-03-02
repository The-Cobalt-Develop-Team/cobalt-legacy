#include "AST/Node/TypeNode.h"
#include "AST/ASTCApi.h"
#include "AST/ASTNode.h"

using namespace Cobalt;

extern "C" {

void* AST_TypeConstructor(char* loc, char* name)
{
    return new ASTTypeNode(name, loc);
}

void* AST_StructDefConstructor(char* loc, char* name)
{
    return new ASTStructDefNode(name, loc);
}

void* AST_UnionDefConstructor(char* loc, char* name)
{
    return new ASTUnionDefNode(name, loc);
}

void* AST_AddStructSlot(void* strc, void* slot)
{
    static_cast<ASTStructDefNode*>(strc)->slots.emplace_back(static_cast<ASTSlotNode*>(slot));
    return strc;
}

void* AST_AddUnionSlot(void* strc, void* slot)
{
    static_cast<ASTUnionDefNode*>(strc)->slots.emplace_back(static_cast<ASTSlotNode*>(slot));
    return strc;
}
}
