#ifndef CODEGEN_H_
#define CODEGEN_H_
/* codegen.h : the definition of the codegen module's 
 * main function
 *
 * To Do :
 *
 */

/* c inclusions */

/* homemade inclusions */
#include "assembly_ast.h"
#include "../parser/ast.h"
#include "../../driver/flag_table.h"


/* codegen_module : the codegen module of the compoiler
 *
 * Arguments : 
 *      - ast : type AST * : the AST from the parser
 *      - ass_ast : type Assembly_AST ** : the Assembly_AST we are going to fill
 *      - flagtable : type FlagLookupTable : the flag lookup table generated from the cmd args
 *
 * Returns : 
 *      - an integer, 0 if everything went well and 1 if there was an error
 */
int codegen_module(AST *ast, Assembly_AST **ass_ast, FlagLookupTable flagtable);

#endif
