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
 * increments the global type_err_count and prints a message to console about
 * error on line
 */
void type_err(ast_node root);

#endif // _CHECK_SYM_H