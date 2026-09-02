#ifndef CODEGEN_H_
#define CODEGEN_H_
/* codegen.h : TODO document 
 *
 * To Do :
 *
 *      To Document :
 *          - codegen.h
 *          - codegen_module
 */

/* c inclusions */

/* homemade inclusions */
#include "assembly_ast.h"
#include "../parser/ast.h"
#include "../../driver/flag_table.h"


/* TODO document 
 *
 */
int codegen_module(AST *ast, Assembly_AST **ass_ast, FlagLookupTable flagtable);

#endif
