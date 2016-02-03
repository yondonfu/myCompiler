/* check_sym.h
 * Headers for the checking the symbol table
 *
 * Students: Yondon Fu and Matt McFarland - Delights (CS57 16W)
 */

 #ifndef _CHECK_SYM_H
 #define _CHECK_SYM_H

/*
 * recursive function call to check symbol types 
 * exits with error (1) if type inconsistencies are found
 */
void set_type(ast_node root);

/*
 * starting at lowest scope, searches for symbol with name
 *
 * returns NULL if not found
 */
symnode_t * find_symnode(symhashtable_t * hashtable, char * name);

/*
 * check argument types -> expected number of child of type and modifier
 *
 * returns 0 if no error
 * returns 1 if error
 */
int check_op_arg_types(ast_node op_node, int child_count, type_specifier_t type, modifier_t mod);

#endif // _CHECK_SYM_H