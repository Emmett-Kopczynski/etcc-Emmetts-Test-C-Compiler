/* emission.c : the main c file for the emission module of the compiler
 *  
 *  To Do :
 *
 *  Known Bugs : 
 */

/* c inclusions */
#include <stdio.h>
#include <string.h>

/* homemade inclusions */
#include "emission.h"
#include "emission_utils.h"


int emission_module(char *sourcepath, Assembly_AST *ass_ast, FlagLookupTable flag_table){
    int len; 
    len = strlen(sourcepath);
    /* makes the sourcepath .s for assembly instead of the .i it was */
    sourcepath[len - 1] = 's';

    FILE *assembly_src;
    assembly_src = fopen(sourcepath, "w");
    if(assembly_src == NULL) goto error;
    
    int err; err = 0;
    err = emit_program(assembly_src, ass_ast);
    if(err != 0) goto error;
    
    fclose(assembly_src);

    return 0;
error:
    if(assembly_src != NULL) fclose(assembly_src);
    return 1;
} 

