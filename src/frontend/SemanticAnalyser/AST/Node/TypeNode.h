#ifndef COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_NODE_TYPENODE_H_
#define COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_NODE_TYPENODE_H_

#include "AST/ASTNode.h"
#include "AST/Node/BaseNode.h"

#include <cstring>
#include <ostream>
#include <string_view>
#include <vector>

namespace Cobalt {

struct ASTTypedefNode : ASTTypeDefinitionNode {
    ASTTypedefNode(ASTTypeNode& type_, char* name_, char* loc)
        : ASTTypeDefinitionNode(loc)
        , type(type_)
        , name(name_, strlen(name_))
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_Typedef; }
    void dump(std::ostream& os) const override;
    const ASTTypeNode& type;
    const std::string_view name;
};

struct ASTCompositeTypeNode : ASTTypeDefinitionNode {
    ASTCompositeTypeNode(char* name_, char* loc)
        : ASTTypeDefinitionNode(loc)
        , name(name_, strlen(name_))
    {
    }
    const std::string_view name;
    std::vector<ASTSlotNode*> slots;
};

struct ASTStructDefNode : ASTCompositeTypeNode {
    ASTStructDefNode(char* name, char* loc)
        : ASTCompositeTypeNode(name, loc)
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_StructDef; }
    void dump(std::ostream& os) const override;
};

struct ASTUnionDefNode : ASTCompositeTypeNode {
    ASTUnionDefNode(char* name, char* loc)
        : ASTCompositeTypeNode(name, loc)
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_UnionDef; }
    void dump(std::ostream& os) const override;
};

}

#endif