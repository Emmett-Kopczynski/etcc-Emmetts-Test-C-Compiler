#ifndef PARSER_H_
#define PARSER_H_
/* parser.h : the header file that defines the parser_module function used in parser.c and 
 * provides documentation for it 
 *
 *  To Do :
 * 
 */

/* c inclusions */


/* homemade incluxions */
#include "../../driver/flag_table.h"
#include "parser_utils.h"


/* parser_module : parses the given TokenQueue and fills the Abstract Syntax Tree (AST) that is pointed to
 * by the given **ast argument
 *
 * Arguments :
 *      - tokens : type TokenQueue * : the TokenQueue we are filling the AST from
 *      - ast : type AST ** : a pointer to the AST we are filling
 *      - flagtable : type FlagLookupTable : a flag lookup table built from the command line args
 *
 * Returns :
 *      - returns 0 if everything went well, otherwise returns 1
 */
int parser_module(TokenQueue *tokens, AST **ast, FlagLookupTable flagtable);


#endif
