#ifndef CODEGEN_UTILS_H_
#define CODEGEN_UTILS_H_
/* codegen_utils.h : TODO document
 *
 * To Do : 
 *      
 *      To Document :
 *          - codegen_utils.h
 *          - assembly_ast_printer
 *          - gen_program
 *          - gen_function
 *          - gen_instructions
 *          - gen_operand
 *          - free_assembly_ast
 *
 */


/* c inclusions */

/* homemade inclusions */
#include "assembly_ast.h"
#include "../parser/ast.h"
#include "../../util/boolean.h"


/* TODO document
 *
 */
void assembly_ast_printer(Assembly_AST *assembly_ast);


/* TODO document
 *
 */
Assembly_AST *gen_program(AST *ast);


/* TODO document
 *
 */
Assembly_AST *gen_function(AST *ast);


/* TODO document
 *
 */
Assembly_AST **gen_instructions(AST *ast);

/* TODO document 
 *
 */
Assembly_AST *gen_operand(AST *ast);


/* TODO document 
 *
 */
int free_assembly_ast(Assembly_AST *assembly_ast);


#endif
