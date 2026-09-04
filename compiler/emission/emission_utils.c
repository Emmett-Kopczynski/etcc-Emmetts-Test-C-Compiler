/* emmision_utils.c : TODO document
 *
 *  To Do :
 *
 *      To Document :
 *          - emmision_utils.c
 *
 *      To Implement :
 *      
 *      To Test :
 *          - emit_program
 *          - emit_function
 *          - emit_instruction
 *          
 */

/* c inclusions */

/* homemade inclusions */
#include "emission_utils.h"


int emit_program(FILE *assembly_source, Assembly_AST *ass_ast){
    if(ass_ast->node_type != A_PROGRAM) goto error;
    
    fprintf(assembly_source, "\n\n");
    int err; err = 0;
    err = emit_function(assembly_source, ass_ast->node.aprog->type.afunc.afunc); 
    if(err != 0) goto error;
    
    fprintf(assembly_source, "\n\n");
    fprintf(assembly_source, "#this line indicates that we don't need an executable stack\n");
    fprintf(assembly_source, ".section .note.GNU-stack,\"\",@progbits\n"); 
    return 0;
error:
    fprintf(stderr, "ERROR EMITING PROGRAM\n");
    return 1;
} /* TODO test */


int emit_function(FILE *assembly_source, Assembly_AST *ass_ast){
    if(ass_ast->node_type != A_FUNCTION) goto error;

    fprintf(assembly_source, "\t.globl %s\n", ass_ast->node.afunc->type.a_tempdef.identifier->info); 
    fprintf(assembly_source, "%s:\n", ass_ast->node.afunc->type.a_tempdef.identifier->info);

    int i; i = 0;
    int err; err = 0;
    for(i = 0; i < INSTCOUNT; i++){
        err = emit_instruction(assembly_source, ass_ast->node.afunc->type.a_tempdef.a_inst[i]);
        if(err != 0) goto error;
    }

    return 0;
error:
    fprintf(stderr, "ERROR EMITING FUNCTION\n");
    return 1;
} /* TODO test */


int emit_instruction(FILE *assembly_source, Assembly_AST *ass_ast){
    if(ass_ast->node_type != A_INSTRUCTION) goto error;  
    
    switch(ass_ast->node.ainst->Instruct_Type){
        case MOV:
            A_Operand *op = ass_ast->node.ainst->type.a_mov.exp_op->node.aoper;

            /* NOTE register %eax is hardcoded here, in future versions this will NOT be the case */
            fprintf(assembly_source, "\tmovl $%s, %%eax\n", op->type.conint.con->info);
            break;

        case RET:
            fprintf(assembly_source, "\tret\n");
            break;

        default:
            goto error;
    }
    return 0;
error:
    fprintf(stderr, "ERROR EMITING INSTRUCTION\n");
    return 1;
} /* TODO test */



