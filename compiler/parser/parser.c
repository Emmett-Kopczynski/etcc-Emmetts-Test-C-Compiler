/* parser.c : TODO document 
 *
 *  To Do :
 *      
 *      To Document :
 *          - parser.c
 *
 *      To Test :
 *          - parser_module
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
