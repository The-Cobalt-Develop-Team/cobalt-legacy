#include "AST/Node/StmtNode.h"
#include "AST/ASTCApi.h"
#include "AST/ASTNode.h"
#include "AST/Node/BaseNode.h"

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

void* AST_GotoConstructor(char* loc, void* label)
{
    return new ASTGotoNode(*static_cast<ASTLabelNode*>(label), loc);
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
    auto ca = static_cast<ASTCaseNode*>(cas);
    static_cast<ASTSwitchNode*>(swit)->bodys.emplace(ca->label, &(ca->stmt));
    return swit;
}
}
