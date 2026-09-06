/* parser.c : the main c file for the parser module of the compiler
 *
 *  To Do :
 *  
 *  Known Bugs :
 *
 */

/* c inclusions */
#include <stdio.h>

/* homemade inclusions */
#include "parser.h"


int parser_module(TokenQueue *tokens, AST **ast, FlagLookupTable flagtable){
    
    *ast = parse_program(tokens);
    
    if(*ast == NULL || tokens->get_size(tokens) > 0){
        return 1;
    } else{
        return 0;
    }
}
