#ifndef EMISSION_H_
#define EMISSION_H_
/* emission.h : defines the main method used in the
 * emission module of the compiler
 *  
 *  To Do :
 *      
 *      To Document :
 *          - emission_module
 *
 */

/* c inclusions */
#include <stdio.h>

/* homemade inclusions */
#include "../codegen/assembly_ast.h"
#include "../../driver/flag_table.h"


/* emission_module : runs the emission module of the compiler, emiting a working
 * asssembly  (.s) file from the given Assembly_AST
 *
 * Arguments :
 *      - sourcepath : type char * : the path to the .i sourcefile
 *      - ass_ast : type : Assembly_AST * : the Assembly_AST we are going to generate
 *      our assembly code from
 *      - flag_table : type FlagLookupTable : the FlagLookupTable generated from the command
 *      line arguments
 *
 * Returns :
 *      - an int, 0 if everything went well and 1 if there was an error
 *
 */
int emission_module(char *sourcepath, Assembly_AST *ass_ast, FlagLookupTable flag_table);

#endif
