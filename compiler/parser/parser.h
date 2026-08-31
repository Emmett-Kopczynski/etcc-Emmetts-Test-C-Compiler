#ifndef PARSER_H_
#define PARSER_H_
/* parser.h : TODO document
 *
 *      To Do :
 *          
 *          To Document :
 *              - parser.h
 *              - parser_module
 */

/* c inclusions */


/* homemade incluxions */
#include "../../driver/flag_table.h"
#include "parser_utils.h"


/* TODO document 
 *
 */
int parser_module(TokenQueue *tokens, AST **ast, FlagLookupTable flagtable);


#endif
