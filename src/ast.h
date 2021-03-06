/* 
 * ast.h
 *
 * File defining an enum and a struct for node types in an abstract
 * syntax tree.
 *
 * Written by THC for CS 57; massaged by SWS.  
 *
 * Students: Yondon Fu and Matt McFarland - Delights (CS57 16W)
 *
 * You should modify this file as appropriate.
 *
 */

#ifndef AST_H_
#define AST_H_

#include "types.h"
#include <stdlib.h>

/* You should fill in the various AST node types.  The following are given
   to you to start with.  You may add or remove node types as you
   wish. */
typedef enum { 
         ROOT_N,
         VAR_N,
         ARG_LIST_N,
         EXPRESSION_N,
         CALL_N,
         PRINT_N,
         READ_N,
         SIZEOF_N,
         RETURN_N,
         BREAK_N,
         CONTINUE_N,
         FOR_HEADER_N,
         FOR_STMT_N,
         DO_WHILE_N,
         WHILE_N,
         EXPRESSION_STMT_N,
         COMPOUND_STMT_N,
         FORMAL_PARAM_N,
         FORMAL_PARAM_ARR_N,
         FORMAL_PARAMS_N,
         FUNC_DECLARATION_N,
         VAR_DECL_N,
         TYPE_SPEC_N,
         VAR_DECLARATION_N,

	       OP_ASSIGN_N, OP_PLUS_N, OP_MINUS_N, OP_NEG_N, OP_TIMES_N, OP_DIVIDE_N,
	       OP_MOD_N, OP_LT_N, OP_LTE_N, OP_GT_N, OP_GTE_N, 
         OP_EQ_N, OP_NE_N, OP_AND_N, OP_OR_N, OP_NOT_N,
         OP_PRE_INC_N, OP_PRE_DEC_N, OP_POST_INC_N, OP_POST_DEC_N,

	       IF_STMT_N, IF_ELSE_STMT_N,

         TYPEINT_N, VOID_N, 
         ID_N, INT_LITERAL_N, STRING_N } ast_node_type;



/* Define a table of nd associated strings.  You
   should modify this table as appropriate.  The order of entries
   should match the order of enumerated values in ast_node_type. */


static val_name_pair token_table[] = {
  { ROOT_N, "ROOT" },

  { VAR_N, "VARIABLE"},
  { ARG_LIST_N, "ARGUMENT_LIST"},
  { EXPRESSION_N, "EXPRESSION"},
  { CALL_N, "CALL"},
  { PRINT_N, "PRINT"},
  { READ_N, "READ"},
  { SIZEOF_N, "SIZEOF"},
  { RETURN_N, "RETURN"},
  { BREAK_N, "BREAK"},
  { CONTINUE_N, "CONTINUE"},
  { FOR_HEADER_N, "FOR_HEADER"},
  { FOR_STMT_N, "FOR_STATEMENT"},
  { DO_WHILE_N, "DO_WHILE"},
  { WHILE_N, "WHILE"},
  { EXPRESSION_STMT_N, "EXPRESSION_STATEMENT"},
  { COMPOUND_STMT_N, "COMPOUND_STATEMENT"},
  { FORMAL_PARAM_N, "FORMAL_PARAMETER"},
  { FORMAL_PARAM_ARR_N, "FORMAL_PARAMETER_ARRAY"},
  { FORMAL_PARAMS_N, "FORMAL_PARAMS"},
  { FUNC_DECLARATION_N, "FUNCTION_DECLARATION"},
  { VAR_DECL_N, "VARIABLE_DECLARATION"},
  { TYPE_SPEC_N, "TYPE_SPECIFIER"},
  { VAR_DECLARATION_N, "VARIABLE_DECLARATION_LINE"},

  { OP_ASSIGN_N, "=" },
  { OP_PLUS_N, "+" },
  { OP_MINUS_N, "-" },
  { OP_NEG_N, "-" },
  { OP_TIMES_N, "*" },
  { OP_DIVIDE_N, "/" },
  { OP_MOD_N, "%"},
  { OP_LT_N, "<"},
  { OP_LTE_N, "<="},
  { OP_GT_N, ">"},
  { OP_GTE_N, ">="},
  { OP_EQ_N, "==" },
  { OP_NE_N, "!="},
  { OP_AND_N, "&&"},
  { OP_OR_N, "||"},
  { OP_NOT_N, "!"},
  { OP_PRE_INC_N, "PRE ++"},
  { OP_PRE_DEC_N, "PRE --"},
  { OP_POST_INC_N, "POST ++"},
  { OP_POST_DEC_N, "POST --"},

  { IF_STMT_N, "IF_STMT" },
  { IF_ELSE_STMT_N, "IF_ELSE_STMT" },

  { TYPEINT_N, "INT"},
  { VOID_N, "VOID"},
  { ID_N, "IDENTIFIER"},
  { INT_LITERAL_N, "INT_LITERAL"},
  { STRING_N, "STRING"},
  { 0, NULL }
};

#define NODE_INDEX(X)    ( (X) - ROOT_N) 
#define NODE_NAME(X)     ( token_table[ NODE_INDEX((X)) ].name)


/* Structure for nodes of the abstract syntax tree.  Uses the
   left-child/right-sibling representation, so that each node can have
   a variable number of children.  You should add or remove fields as
   appropriate. */
typedef struct ast_node_struct *ast_node;
struct ast_node_struct {
  ast_node_type node_type;
  ast_node left_child, right_sibling;
  ast_node parent;

  // scope information
  int id;                       // unique id
  void * scope_table;           // void becuase of include dependencies
  int line_number;              // yylineno that this node was synthesized on
  ast_node parent_function;     // for RETURN_N

  // type information
  type_specifier_t type;
  modifier_t mod;

  // as most one of these would be nonzero
  char *value_string;   /* for ID */
  int value_int;        /* for INT_LITERAL */
  
};

/* Create a node with a given token type and return a pointer to the
   node. */
ast_node create_ast_node(ast_node_type node_type);

/**
 * Post process the tree to add parent pointers
 */
void post_process_ast(ast_node root);

/**
 * Look up ast node that represents parent block
 */
ast_node lookup_parent_block(ast_node root);

/*
 * returns line number of left most child.
 */
int get_line_number(ast_node root);

/* Print the contents of a subtree of an abstract syntax tree, given
   the root of the subtree and the depth of the subtree root. */
void print_ast(ast_node root, int depth);

#endif
