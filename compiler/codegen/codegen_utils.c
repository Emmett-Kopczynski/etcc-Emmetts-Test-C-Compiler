/* codegen_utils.c : TODO document
 *
 * To Do :
 *
 *      To Document :
 *          - codegen_utils.c
 *
 *      To Implement :
 *          - assembly_ast_printer
 *          - gen_instructions
 *          - gen_operand
 *          - free_assembly_ast
 *
 *      To Test :
 *          - gen_program
 *          - gen_function
 *
 */


/* c inclusions */
#include <stdio.h>
#include <stdlib.h>


/* homemade inclusions */
#include "codegen_utils.h"


void assembly_ast_printer(Assembly_AST *assembly_ast){
    return;
} /* TODO implement */


Assembly_AST *gen_program(AST *ast){
    
    /* declares and assigns memory to the assembly ast */
    Assembly_AST *assembly_ast;
    assembly_ast = (Assembly_AST *) malloc(sizeof(Assembly_AST));
    
    if(ast->node_type != PROGRAM) goto error;  /* double checks ast */
    
    assembly_ast->node_type = A_PROGRAM; /* set nodetype */

    assembly_ast->node.aprog = (A_Program *) malloc(sizeof(A_Program));

    /* gets the function node */
    assembly_ast->node.aprog->type.afunc.afunc = gen_function(ast->node.prog->type.func.func);
    if(assembly_ast->node.aprog->type.afunc.afunc == NULL) goto error;

    return assembly_ast;
error:
    fprintf(stderr, "Something Went Seriously Wrong With Codegen\n");
    free_assembly_ast(assembly_ast);
    return NULL;
} /* TODO test */


Assembly_AST *gen_function(AST *ast){
    
    if(ast->node_type != FUNCTION) goto error; /* double checks ast */
    
    /* declares and assigns memory to the assembly ast */
    Assembly_AST *assembly_ast;
    assembly_ast = (Assembly_AST *) malloc(sizeof(Assembly_AST));


    assembly_ast->node_type = A_FUNCTION; /* set nodetype */

    assembly_ast->node.afunc = (A_Function *) malloc(sizeof(A_Function));

    /* gets the identifier token */
    assembly_ast->node.afunc->type.a_tempdef.identifier = ast->node.func->type.tempdef.identifier;
    
    /* gets the instructions */
    assembly_ast->node.afunc->type.a_tempdef.a_inst = gen_instructions(ast->node.func->type.tempdef.stat);
    if(assembly_ast->node.afunc->type.a_tempdef.a_inst == NULL) goto error;

    return assembly_ast;

error:
    return NULL; /* clean up happens at gen_program when we return null */
} /* TODO test */ 


Assembly_AST **gen_instructions(AST *ast){
    return NULL;
} /* TODO implement */


Assembly_AST *gen_operand(AST *ast){
    return NULL;
} /* TODO implement */


int free_assembly_ast(Assembly_AST *assembly_ast){
    return -1;
} /* TODO implement */

