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
void* AST_NoneNodeConstructor(char* loc);

/**
 * \brief Constructor of ASTRootNode. It will only construct once
 * \return Pointer to the Node
 * \retval NULL Construct failed
 */
void* AST_ASTRootNodeConstructor();

/**
 * \brief Adding a Node to ASTRootNode
 */
void* AST_AddASTRootNodeChildren(void* node);

/**
 * \brief Construct Base AssignNode e.g. a = b
 * \param lhs Expression on the left hand side of Assign Symbol
 * \param rhs Expression on the right hand side of Assign Symbol
 * \return Pointer to the Node
 * \retval NULL Construct failed
 */
void* AST_AssignNodeConstructor(char* loc, void* lhs, void* rhs);

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

// typedef char* AST_BinaryOperatorType;

/**
 * \brief Construct OpAssignNode e.g. a+=1
 * \param lhs Expression on the left hand side of Assign Symbol
 * \param op Operator
 * \param rhs Expression on the right hand side of Assign Symbol
 * \return Pointer to the Node
 * \retval NULL Construct failed
 */
void* AST_OpAssignNodeConstructor(char* loc, void* lhs, AST_BinaryOperatorType op, void* rhs);

/**
 * \brief Construct Address Node e.g. &x
 * \param expr Expression to be dereferenced
 */
void* AST_AddressNodeConstructor(char* loc, void* expr);

/**
 * \brief Construct BinaryOperator Node e.g. 1+a
 * \param lhs left hand side
 * \param op Operator
 * \param rhs right hand side
 */
void* AST_BinaryOpNodeConstructor(char* loc, void* lhs, AST_BinaryOperatorType op, void* rhs);

/**
 * \brief Construct UnaryOperator Node e.g.
 * \param expr Expression
 * \param op Operator
 */
void* AST_UnaryOpNodeConstructor(char* loc, void* expr, AST_UnaryOperatorType op);

/**
 * \brief Construct static cast node e.g. (int)(1.5)
 * \param type Type to cast
 * \param expr Type to cast
 */
void* AST_CastNodeConstructor(char* loc, void* type, void* expr);

/**
 * \brief Construct Condition Expr node e.g. a?b:
 */
void* AST_CondExprNodeConstructor(char* loc, void* condition, void* statement_a, void* statement_b);

/**
 * \brief Construct Node which call a function
 * \param func The name of the function
 */
void* AST_FuncCallNodeConstructor(char* loc, char* func);

/**
 * \brief Add Parameter of FuncCall Node
 */
void* AST_AddFuncCallParameter(void* func_call, void* param);

/**
 * \brief Constructor of ArraySubscriptNode
 */
void* AST_ArraySubscriptConstructor(char* loc, void* array, void* subscript);

/**
 * \brief Constructor of Dereference node e.g. *ptr
 */
void* AST_DereferenceConstructor(char* loc, void* ptr);

/**
 * \brief Constructor of Member node e.g. cls.memb
 * \param obj object to be call
 * \param memb member of obj
 */
void* AST_MemberConstructor(char* loc, void* obj, char* memb);

/**
 * \brief Constructor of Member of pointer e.g. ptr->memb
 */
void* AST_PtrMemberConstructor(char* loc, void* ptr, char* memb);

/**
 * \brief Constructor of Variable node
 * \param name name of the variable
 */
void* AST_VariableConstructor(char* loc, char* name);

/**
 * \brief Constructor of IntLiteral
 * \param raw raw string of the int literal
 */
void* AST_IntLiteralConstructor(char* loc, char* raw);

/**
 * \brief Constructor of StringLiteral
 * \param raw raw string of the string literal
 */
void* AST_StringLiteralConstructor(char* loc, char* raw);

/**
 * \brief Constructor of FloatLiteral
 * \param raw raw string of the float literal
 */
void* AST_FloatListralConstructor(char* loc, char* raw);

/**
 * \brief Constructor of Sizeof
 * \param node type or expression inside sizeof
 */
void* AST_SizeofNodeConstructor(char* loc, void* node);

/**
 * \brief Constructpr of Slot which means definition of struct member
 * \param type type node of the slot
 * \param name name of variable
 */
void* AST_SlotConstructor(char* loc, void* type, char* name);

/**
 * \brief Constructor of Variable Node
 * \param type type node of the variable
 * \param name name of the variable
 * \param initializer ExprNode which initialize the variable while NULL means default
 */
void* AST_VariableDefinitionConstructor(char* loc, void* type, char* name, void* initializer);

/**
 * \brief Constructor of FuncParameter
 */
void* AST_FuncParameterConstructor(char* loc, void* type, char* name);

/**
 * \brief Constructor of a block node
 */
void* AST_BlockConstructor(char* loc);

/**
 * \brief Add a StmtNode to a Block Node
 */
void* AST_AddBlockStmt(void* block, void* stmt);

/**
 * \brief BreakNode
 */
void* AST_BreakNodeConstructor(char* loc);

/**
 * \brief ContinueNode
 */
void* AST_ContinueNodeConstructor(char* loc);

/**
 * \brief Case Node
 */
void* AST_CaseNodeConstructor(char* loc, char* label,void* stmt);

/**
 * \brief DoWhile Node
 */
void* AST_DoWhileConstructor(char* loc, void* cond, void* body);

/**
 * \brief While Node
 */
void* AST_WhileConstructor(char* loc, void* cond, void* body);

/**
 * \brief For loop Node e.g. for(init; cond; mod) body
 */
void* AST_ForConstructor(char* loc, void* init, void* cond, void* mod, void* body);

/**
 * \brief Goto Node
 */
void* AST_GotoConstructor(char* loc, char* label);

/**
 * \brief Convert a Expr to an Stmt
 */
void* AST_ExprStmtConstructor(char* loc, void* expr);

/**
 * \brief If node
 */
void* AST_IfConstructor(char* loc, void* cond, void* body);

/**
 * \brief Label node
 */
void* AST_LabelConstructor(char* loc, char* name);

/**
 * \brief Return node
 */
void* AST_ReturnConstructor(char* loc, void* expr);

/**
 * \brief Switch node
 */
void* AST_SwitchConstructor(char* loc, void* expr);

/**
 * \brief Add case
 */
void* AST_AddSwitchCase(void* swit, void* cas);

/**
 * \brief Struct Definition Node
 */
void* AST_StructDefConstructor(char* loc, char* name);

/**
 * \brief Add struct slot
 */
void* AST_AddStructSlot(void* strc, void* slot);

/**
 * \brief Union Definition Node
 */
void* AST_UnionDefConstructor(char* loc, char* name);

/**
 * \brief Add union slot
 */
void* AST_AddUnionSlot(void* strc, void* slot);

/**
 * \brief TypedefNode
 */
void* AST_TypedefConstructor(char* loc, void* type, char* name);

/**
 * \brief Type Node
 */
void* AST_TypeConstructor(char* loc, char* name);

#ifdef __cplusplus
}
#endif

#endif