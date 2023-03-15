#ifndef COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_NODE_ASTROOTNODE_H_
#define COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_NODE_ASTROOTNODE_H_

#include "AST/ASTNode.h"
#include "AST/ASTVisitor.h"

#include <cstddef>
#include <ostream>
#include <vector>

namespace Cobalt {

struct ASTASTRootNode : BaseASTNode {
private:
    ASTASTRootNode()
        : BaseASTNode(nullptr)
    {
    }

public:
    [[nodiscard]] ASTNodeKind kind() const override { return NK_ASTRoot; }
    void dump(std::ostream& os) const override
    {
        os << "{";
        for (auto p : children)
            p->dump(os);
        os << "}";
    }
    void visitNext(BaseASTVisitor& v) override { v.visit(*this); }
    std::vector<BaseASTNode*> children;
    static ASTASTRootNode* instance(bool reset = false)
    {
        static ASTASTRootNode* ins = nullptr;
        if (reset) {
            delete ins;
            ins = nullptr;
        }
        if (!ins)
            ins = new ASTASTRootNode();
        return ins;
    }
};

}

#endif