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
    explicit ASTTypeNode(char* loc)
        : BaseASTNode(loc)
    {
    }
};

struct ASTTypeDefinitionNode : BaseASTNode {
    explicit ASTTypeDefinitionNode(char* loc)
        : BaseASTNode(loc)
    {
    }
};

}

#endif