#ifndef CODEGEN_UTILS_H_
#define CODEGEN_UTILS_H_
/* codegen_utils.h : contains the definitions for all 
 * the utilty function for the Assembly_AST and the 
 * codegen module of the compiler
 *
 * To Do : 
 *      
 *      To Document :
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


/* symbolic constants */
#define INSTCOUNT 2 /* a temporary constant for this verison, describes
                       the amount of instructions to return from gen_instructions */


/* gen_program : generates the Assembly_AST version of the given AST program node,
 * uses recursive decent parsing to generate all child nodes as well
 *
 * Arguments :
 *      - ast : type AST * : the abstract syntax tree from the parser
 *
 * Returns : 
 *      - an Assembly_AST * version of the given AST *
 *
 */
Assembly_AST *gen_program(AST *ast);


/* gen_function : generates the Assembly_AST version of the given AST funcion node, uses 
 * recursive decent parsing to generate all child nodes as well
 *
 * Arguments :
 *      - ast : type AST * : the AST from the parser at a function node
 *
 * Returns :
 *      - a function node for an Assembly_AST
 *
 */
Assembly_AST *gen_function(AST *ast);


/* gen_instructions : generates the Assembly_AST version of an AST statement node, 
 * called an Instruction Node in the Assembly_AST. uses recursive decent parsing to generate all child
 * nodes as well
 *
 * Argument :
 *      - ast : type AST * : the AST from the parser at a statement node
 *
 * Returns : 
 *      - an instruction node for the Assembly AST
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
