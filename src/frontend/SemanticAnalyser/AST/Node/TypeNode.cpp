#include "AST/Node/TypeNode.h"
#include "AST/ASTCApi.h"
#include "AST/ASTNode.h"

namespace Cobalt {

void ASTTypedefNode::dump(std::ostream& os) const
{
    os << "{";
    os << R"("nodeKind":"ASTTypedefNode",)";
    os << "\"type\":" << type << ",";
    os << "\"name\":"
       << "\"" << name << "\"";
    os << "}";
}

void ASTStructDefNode::dump(std::ostream& os) const
{
    os << "{";
    os << R"("nodeKind":"ASTStructDefNode",)";
    os << "\"name\":"
       << "\"" << name << "\",";
    os << "\"slots\":";
    os << "[";
    for (auto m : slots)
        os << (*m) << ",";
    os << "]";
    os << "}";
}

void ASTUnionDefNode::dump(std::ostream& os) const
{
    os << "{";
    os << R"("nodeKind":"ASTUnionDefNode",)";
    os << "\"name\":"
       << "\"" << name << "\",";
    os << "\"slots\":";
    os << "[";
    for (auto m : slots)
        os << (*m) << ",";
    os << "]";
    os << "}";
}

}

using namespace Cobalt;

extern "C" {

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

void* AST_SimpleTypeConstructor(char* loc, char* name)
{
    return new ASTSimpleTypeNode(name, loc);
}
}
