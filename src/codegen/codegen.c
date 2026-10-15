/* codegen.c : the codegen module (AKA assembly generation) of
 * the compiler
 *
 * To Do :
 *
 * Known Bugs :
 *
 */


/* c inclusions */
#include <stdio.h>

/* homemade inclusions */
#include "codegen.h"
#include "codegen_utils.h"


int codegen_module(AST *ast, Assembly_AST **ass_ast, FlagLookupTable flagtable){
    
    *ass_ast = gen_program(ast);
    
    if(*ass_ast == NULL) goto error;

    return 0;

error:
    fprintf(stderr, "Something Went Seriously Wrong With Codegen\n");
    return 1;
} 
