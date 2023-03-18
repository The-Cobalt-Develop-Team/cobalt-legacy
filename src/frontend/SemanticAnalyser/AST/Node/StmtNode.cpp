#include "AST/Node/StmtNode.h"

#include "AST/ASTCApi.h"
#include "AST/ASTNode.h"
#include "AST/Node/BaseNode.h"
#include "AST/Node/ExprNode.h"

namespace Cobalt {

void ASTBlockNode::visitNext(BaseASTVisitor& v)
{
    for (auto p : stmts) {
        v.visit(*p);
    }
}

void ASTBlockNode::dump(std::ostream& os) const
{
    os << "{";
    os << R"("nodeKind":"ASTBlockNode",)";
    os << R"("statements":)"
       << "[";
    for (auto p : stmts)
        os << (*p) << ",";
    os << "]";
    os << "}";
}

void ASTBreakNode::dump(std::ostream& os) const
{
    os << R"({"nodeKind":"ASTBreakNode"})";
}

void ASTContinueNode::dump(std::ostream& os) const
{
    os << R"({"nodeKind":"ASTContinueNode"})";
}

void ASTCaseNode::dump(std::ostream& os) const
{
    os << "{";
    os << R"("nodeKind":"ASTCaseNode",)";
    os << "\"label\":"
       << "\"" << label << "\""
       << ",";
    os << "\"statements\":" << stmt;
    os << "}";
}

void ASTDoWhileNode::dump(std::ostream& os) const
{
    os << "{";
    os << R"("nodeKind":"ASTDoWhileNode",)";
    os << "\"condition\":" << cond << ",";
    os << "\"statement\":" << stmt;
    os << "}";
}

void ASTWhileNode::dump(std::ostream& os) const
{
    os << "{";
    os << R"("nodeKind":"ASTWhileNode",)";
    os << "\"condition\":" << cond << ",";
    os << "\"statement\":" << stmt;
    os << "}";
}

void ASTForNode::dump(std::ostream& os) const
{
    os << "{";
    os << R"("nodeKind":"ASTForNode",)";
    os << "\"initializer\":" << init << ",";
    os << "\"condition\":" << cond << ",";
    os << "\"modifier\":" << mod << ",";
    os << "\"body\":" << body;
    os << "}";
}

void ASTGotoNode::dump(std::ostream& os) const
{
    os << "{";
    os << R"("nodeKind":"ASTGotoNode",)";
    os << "\"label\":"
       << "\"" << label << "\"";
    os << "}";
}

void ASTExprStmtNode::dump(std::ostream& os) const
{
    os << "{";
    os << R"("nodeKind":"ASTExprStmtNode",)";
    os << "\"expr\":" << expr;
    os << "}";
}

void ASTExprStmtNode::visitNext(BaseASTVisitor& v)
{
    v.visit(expr);
}

void ASTIfNode::dump(std::ostream& os) const
{
    os << "{";
    os << R"("nodeKind":"ASTIfNode",)";
    os << "\"condition\":" << cond << ",";
    os << "\"body\":" << body;
    os << "}";
}

void ASTLabelNode::dump(std::ostream& os) const
{
    os << "{";
    os << R"("nodeKind":"ASTLabelNode",)";
    os << "\"label\":"
       << "\"" << name << "\"";
    os << "}";
}

void ASTReturnNode::dump(std::ostream& os) const
{
    os << "{";
    os << R"("nodeKind":"ASTReturnNode",)";
    os << "\"expr\":" << expr;
    os << "}";
}

void ASTSwitchNode::dump(std::ostream& os) const
{
    os << "{";
    os << R"("nodeKind":"ASTSwitchNode",)";
    os << "\"state\":" << state << ",";
    os << "\"bodies\":";
    os << "[";
    for (auto c : bodies) {
        os << "{";
        os << "\"case\":"
           << "\"" << c.first << "\",";
        os << "\"body\":" << (*c.second);
        os << "},";
    }
    os << "]";
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

}

using namespace Cobalt;

extern "C" {

void* AST_BlockConstructor(char* loc)
{
    return static_cast<void*>(new ASTBlockNode(loc));
}

void* AST_AddBlockStmt(void* block, void* stmt)
{
    static_cast<ASTBlockNode*>(block)->stmts.emplace_back(static_cast<ASTStmtNode*>(stmt));
    return block;
}

void* AST_ContinueNodeConstructor(char* loc)
{
    return static_cast<void*>(new ASTContinueNode(loc));
}

void* AST_BreakNodeConstructor(char* loc)
{
    return static_cast<void*>(new ASTBreakNode(loc));
}

void* AST_CaseNodeConstructor(char* loc, char* label, void* stmt)
{
    return new ASTCaseNode(label, *static_cast<ASTStmtNode*>(stmt), loc);
}

void* AST_DoWhileConstructor(char* loc, void* cond, void* body)
{
    return new ASTDoWhileNode(*static_cast<ASTExprNode*>(cond), *static_cast<ASTStmtNode*>(body), loc);
}

void* AST_WhileConstructor(char* loc, void* cond, void* body)
{
    return new ASTWhileNode(*static_cast<ASTExprNode*>(cond), *static_cast<ASTStmtNode*>(body), loc);
}

void* AST_ForConstructor(char* loc, void* init, void* cond, void* mod, void* body)
{
    return new ASTForNode(*static_cast<ASTStmtNode*>(init), *static_cast<ASTExprNode*>(cond), *static_cast<ASTStmtNode*>(mod), *static_cast<ASTStmtNode*>(body), loc);
}

void* AST_GotoConstructor(char* loc, char* label)
{
    return new ASTGotoNode(label, loc);
}

void* AST_ExprStmtConstructor(char* loc, void* expr)
{
    return new ASTExprStmtNode(*static_cast<ASTExprNode*>(expr), loc);
}

void* AST_IfConstructor(char* loc, void* cond, void* body)
{
    return new ASTIfNode(*static_cast<ASTExprNode*>(cond), *static_cast<ASTStmtNode*>(body), loc);
}

void* AST_LabelConstructor(char* loc, char* name)
{
    return new ASTLabelNode(name, loc);
}

void* AST_ReturnConstructor(char* loc, void* expr)
{
    return new ASTReturnNode(*static_cast<ASTExprNode*>(expr), loc);
}

void* AST_SwitchConstructor(char* loc, void* expr)
{
    return new ASTSwitchNode(*static_cast<ASTExprNode*>(expr), loc);
}

void* AST_AddSwitchCase(void* swit, void* cas)
{
    // TODO: Redesign Switch
    // auto ca = static_cast<ASTCaseNode*>(cas);
    // static_cast<ASTSwitchNode*>(swit)->bodies.emplace(ca->label, &(ca->stmt));
    return swit;
}

void* AST_VariableDefinitionConstructor(char* loc, char* type, char* name, void* initializer)
{
    auto init = static_cast<Cobalt::ASTExprNode*>(initializer);
    if (!initializer) {
        // TODO: default initializer
    }
    return new Cobalt::ASTVariableDefinitionNode(type, name, init, loc);
}
}
