#ifndef COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_NODE_BASENODE_H_
#define COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_NODE_BASENODE_H_

#include "AST/ASTNode.h"

namespace Cobalt {

struct ASTExprNode : BaseASTNode {
    explicit ASTExprNode(char* loc)
        : BaseASTNode(loc)
    {
    }
};

struct ASTStmtNode : BaseASTNode {
    explicit ASTStmtNode(char* loc)
        : BaseASTNode(loc)
    {
    }
};

struct ASTTypeNode : BaseASTNode {
    ASTTypeNode(char* name_, char* loc)
        : BaseASTNode(loc)
        , name(name_, strlen(name_))
    {
    }
    [[nodiscard]] ASTNodeKind kind() const override { return NK_Type; }
    void dump(std::ostream& os) const override { }
    const std::string_view name;
};

struct ASTTypeDefinitionNode : BaseASTNode {
    explicit ASTTypeDefinitionNode(char* loc)
        : BaseASTNode(loc)
    {
    }
};

}

#endif