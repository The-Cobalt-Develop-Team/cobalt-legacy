#include "AST/Node/BaseNode.h"
#include "AST/ASTCApi.h"

namespace Cobalt {

void ASTFuncParameterNode::dump(std::ostream& os) const
{
    os << "{";
    os << R"("nodeKind":"ASTFuncParameterNode",)";
    os << "\"type\":" << type << ",";
    os << "\"name\":"
       << "\"" << name << "\"";
    os << "}";
}

void ASTVariableDefinitionNode::dump(std::ostream& os) const
{
    os << "{";
    os << R"("nodeKind":"ASTVariableDefinitionNode",)";
    os << "\"type\":" << type << ",";
    os << "\"name\":"
       << "\"" << name << "\",";
    os << "\"initializer\":" << init;
    os << "}";
}

void ASTSlotNode::dump(std::ostream& os) const
{
    os << "{";
    os << R"("nodeKind":"ASTSlotNode",)";
    os << "\"type\":" << type << ",";
    os << "\"name\":"
       << "\"" << name << "\"";
    os << "}";
}

}

extern "C" {
void* AST_FuncParameterConstructor(char* loc, void* type, char* name)
{
    return new Cobalt::ASTFuncParameterNode(*static_cast<Cobalt::ASTTypeNode*>(type), name, loc);
}

void* AST_VariableDefinitionConstructor(char* loc, void* type, char* name, void* initializer)
{
    auto init = static_cast<Cobalt::ASTExprNode*>(initializer);
    if (!initializer) {
        // TODO: default initializer
    }
    return new Cobalt::ASTVariableDefinitionNode(*static_cast<Cobalt::ASTTypeNode*>(type), name, *init, loc);
}

void* AST_SlotConstructor(char* loc, void* type, char* name)
{
    return new Cobalt::ASTSlotNode(*static_cast<Cobalt::ASTTypeNode*>(type), name, loc);
}
}
