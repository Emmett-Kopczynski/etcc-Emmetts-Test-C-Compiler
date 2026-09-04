#ifndef EMISSION_H_
#define EMISSION_H_
/* emision.h : TODO document 
 *  
 *  To Do :
 *      
 *      To Document :
 *          - emision.h
 *          - emission_module
 *
 */

/* c inclusions */
#include <stdio.h>

/* homemade inclusions */
#include "../codegen/assembly_ast.h"
#include "../../driver/flag_table.h"


/* TODO document
 *
 */
int emission_module(char *sourcepath, Assembly_AST *ass_ast, FlagLookupTable flag_table);

#endif
