#ifndef ADD_EXPR_NODE
#define ADD_EXPR_NODE ADD_NODE_KIND(Expr)
#endif

ADD_EXPR_NODE
  ADD_NODE_KIND(AbstractAssign)
    ADD_NODE_KIND(Assign)
    ADD_NODE_KIND(OpAssign)
  ADD_NODE_KIND(Address)
  ADD_NODE_KIND(BinaryOp)
    ADD_NODE_KIND(LogicalAnd)
    ADD_NODE_KIND(LogicalOr)
  ADD_NODE_KIND(Cast)
  ADD_NODE_KIND(CondExpr)
  ADD_NODE_KIND(FuncCall)
  ADD_NODE_KIND(LHS)
    ADD_NODE_KIND(ArraySubscript)
    ADD_NODE_KIND(Dereference)
    ADD_NODE_KIND(Member)
    ADD_NODE_KIND(PtrMember)
    ADD_NODE_KIND(Variable)
  ADD_NODE_KIND(Literal)
    ADD_NODE_KIND(IntLiteral)
    ADD_NODE_KIND(StringLiteral)
    ADD_NODE_KIND(FloatLiteral)
  ADD_NODE_KIND(SizeofExpr)
  ADD_NODE_KIND(SizeofType)
  ADD_NODE_KIND(UnaryOp)
    /* ++ -- */
    ADD_NODE_KIND(UnaryArithmeticOp)
      ADD_NODE_KIND(PrefixOp)
      ADD_NODE_KIND(SuffixOp)
END_NODE_KIND(Expr)

#undef ADD_EXPR_NODE
