#ifndef COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_ASTCAPI_H_
#define COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_ASTCAPI_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief construct a None node which can explicitly convert to any ASTNode
 * \return Pointer to the Node
 * \retval NULL Construct failed
 */
void* AST_NoneNodeConstructor();

/**
 * \brief Construct ASTRootNode. It will only construct once
 * \return Pointer to the Node
 * \retval NULL Construct failed
 */
void* AST_ASTRootNodeConstructor();

/**
 * \brief Add a node to an existed Node.
 * \return Pointer to the parent node
 * \retval NULL Add failed
 */
void* AST_AddChildNode(void* parent, void* child);

/**
 * \brief Construct Base AssignNode e.g. a = b
 * \param lhs Expression on the left hand side of Assign Symbol
 * \param rhs Expression on the right hand side of Assign Symbol
 * \return Pointer to the Node
 * \retval NULL Construct failed
 */
void* AST_AssignNodeConstructor(void* lhs, void* rhs);

typedef enum {
    AST_AddOp,
    AST_SubOp,
    AST_TimesOp,
    AST_DivOp,
    AST_ModOp,
    AST_GEQOp,
    AST_GreaterOp,
    AST_LEQOp,
    AST_LessOp,
    AST_EqualOp,
    AST_NEqualOp,
    AST_BitAndOp,
    AST_BitOrOp,
    AST_BitXorOp,
    AST_LShiftOp,
    AST_RShiftOp,
    AST_LogicalAndOp,
    AST_LogicalOrOp,
} AST_BinaryOperatorType;

typedef enum {
    AST_IncOp,
    AST_DecOp,
    AST_CompleOp,
} AST_UnaryOperatorType;

// typedef const char* AST_BinaryOperatorType;

/**
 * \brief Construct OpAssignNode e.g. a+=1
 * \param lhs Expression on the left hand side of Assign Symbol
 * \param op Operator
 * \param rhs Expression on the right hand side of Assign Symbol
 * \return Pointer to the Node
 * \retval NULL Construct failed
 */
void* AST_OpAssignNodeConstructor(void* lhs, AST_BinaryOperatorType op, void* rhs);

/**
 * \brief Construct Address Node e.g. &x
 * \param expr Expression to be dereferenced
 */
void* AST_AddressNodeConstructor(void* expr);

/**
 * \brief Construct BinaryOperator Node e.g. 1+a
 * \param lhs left hand side
 * \param op Operator
 * \param rhs right hand side
 */
void* AST_BinaryOpNodeConstructor(void* lhs, AST_BinaryOperatorType op, void* rhs);

void* AST_UnaryOpNodeCostructor(void* expr, AST_UnaryOperatorType op);

/**
 * \brief Construct static cast node e.g. (int)(1.5)
 * \param type Type to cast
 * \param expr Type to cast
 */
void* AST_CastNodeConstructor(void* type, void* expr);

/**
 * \brief Construct Condition Expr node e.g. a?b:
 */
void* AST_CondExprNodeConstructor(void* condition, void* statement_a, void* statement_b);

/**
 * \brief Construct Node which call a function
 * \param func The name of the function
 */
void* AST_FuncCallnodeConstructor(const char* func);

#ifdef __cplusplus
}
#endif

#endif