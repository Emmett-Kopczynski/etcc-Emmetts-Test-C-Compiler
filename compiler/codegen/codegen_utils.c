/* codegen_utils.c : TODO document
 *
 * To Do :
 *
 *      To Document :
 *          - codegen_utils.c
 *
 *      To Implement :
 *          - free_assembly_ast
 *
 *      To Test :
 *          - gen_program
 *          - gen_function
 *          - gen_instructions
 *          - gen_operand
 *
 */


/* c inclusions */
#include <stdio.h>
#include <stdlib.h>


/* homemade inclusions */
#include "codegen_utils.h"


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
    
    /* declares and assigns memory to the assembly ast */
    Assembly_AST *assembly_ast;
    assembly_ast = (Assembly_AST *) malloc(sizeof(Assembly_AST));

    assembly_ast->node_type = A_FUNCTION; /* set nodetype */

    assembly_ast->node.afunc = (A_Function *) malloc(sizeof(A_Function));

    if(ast->node_type != FUNCTION) goto error; /* double checks ast */
    
    /* gets the identifier token */
    assembly_ast->node.afunc->type.a_tempdef.identifier = ast->node.func->type.tempdef.identifier;
    
    /* gets the instructions */
    assembly_ast->node.afunc->type.a_tempdef.a_inst = gen_instructions(ast->node.func->type.tempdef.stat);
    if(assembly_ast->node.afunc->type.a_tempdef.a_inst == NULL) goto error;

    return assembly_ast;

error:
    free_assembly_ast(assembly_ast);
    return NULL;
} /* TODO test */ 


Assembly_AST **gen_instructions(AST *ast){
    
    /* declares and assigns memory to the assembly ast */
    Assembly_AST **assembly_ast;
    assembly_ast = (Assembly_AST **) malloc(sizeof(Assembly_AST *) * INSTCOUNT);
    assembly_ast[0] = (Assembly_AST *) malloc( sizeof(Assembly_AST));
    assembly_ast[1] = (Assembly_AST *) malloc( sizeof(Assembly_AST));
    assembly_ast[0]->node_type = A_INSTRUCTION; 
    assembly_ast[1]->node_type = A_INSTRUCTION;
    
    assembly_ast[0]->node.ainst = (A_Instruction *) malloc(sizeof(A_Instruction));
    assembly_ast[1]->node.ainst = (A_Instruction *) malloc(sizeof(A_Instruction));

    assembly_ast[0]->node.ainst->Instruct_Type = MOV;
    assembly_ast[1]->node.ainst->Instruct_Type = RET;
    

    if(ast->node_type != STATEMENT) goto error; /* double checks ast */

    /* get the A_Operand */
    assembly_ast[0]->node.ainst->type.a_mov.exp_op = gen_operand(ast->node.stat->type.ret.exp);
    if(assembly_ast[0]->node.ainst->type.a_mov.exp_op == NULL) goto error;

    return assembly_ast;

error:
    free_assembly_ast(assembly_ast[0]);
    free_assembly_ast(assembly_ast[1]);
    return NULL; 
} /* TODO test */


Assembly_AST *gen_operand(AST *ast){
    /* declare and assign memory */
    Assembly_AST *assembly_ast;
    assembly_ast = (Assembly_AST *) malloc(sizeof(Assembly_AST));   
        
    assembly_ast->node_type = A_OPERAND;
    assembly_ast->node.aoper = (A_Operand *) malloc(sizeof(A_Operand));
    
    if(ast->node_type != EXP) goto error;    

    assembly_ast->node.aoper->type.conint.con = ast->node.expr->type.conint.con;
    if(assembly_ast->node.aoper->type.conint.con == NULL) goto error;

    return assembly_ast;

error:
    free_assembly_ast(assembly_ast);
    return NULL;
} /* TODO test */


int free_assembly_ast(Assembly_AST *assembly_ast){
    if(assembly_ast == NULL) return 0;

    switch(assembly_ast->node_type){
        case A_PROGRAM:
            break; /* TODO implement branch */

        case A_FUNCTION:
            break; /* TODO implement branch */

        case A_INSTRUCTION:
            break; /* TODO implement branch */

        case A_OPERAND:
            break; /* TODO implement branch */
    }
    return 0;
} /* TODO implement */

