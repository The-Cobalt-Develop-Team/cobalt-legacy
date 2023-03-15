#ifndef COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_ASTNODE_H_
#define COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_ASTNODE_H_

#include <cstring>
#include <ostream>
#include <string>
#include <string_view>

namespace Cobalt {

enum ASTNodeKind : int {
#define ADD_NODE_KIND(name) NK_##name,
#define END_NODE_KIND(name) NK_##name##_END_TAG,
#include "AST/Node/ASTNode.inc"
#undef ADD_NODE_KIND
#undef END_NODE_KIND
};

struct BaseASTVisitor;

struct BaseASTNode {
    explicit BaseASTNode(char* loc)
        : location(loc, strlen(loc))
    {
    }
    virtual ~BaseASTNode() = default;
    [[nodiscard]] virtual ASTNodeKind kind() const = 0;
    virtual void dump(std::ostream& os) const = 0;
    virtual void visitNext(BaseASTVisitor& v) = 0;
    const std::string_view location; // const std::string location;
};

inline std::ostream& operator<<(std::ostream& os, const BaseASTNode& node)
{
    node.dump(os);
    return os;
}

#define ADD_NODE_KIND(name) \
    struct AST##name##Node;
#include "AST/Node/ASTNode.inc"
#undef ADD_NODE_KIND

}

#endif