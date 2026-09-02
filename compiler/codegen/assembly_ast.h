#ifndef ASSEMBLY_AST_H_
#define ASSEMBLY_AST_H_
/* assembly_ast.h : TODO document 
 *
 * To Do :
 *
 *      To Document :
 *          - assembly_ast.h
 *          - A_ASTag
 *          - Assembly_AST
 *          - A_Program
 *          - A_Function
 *          - A_Instruction
 *          - A_Expression
 *
 *      To Implement :
 *          - Assembly_AST
 *          - A_Program
 *          - A_Function
 *          - A_Instruction
 *          - A_Expression
 *
 */

/* c inclusions */

/* homemade inclusions */
#include "../token.h"

/* foreward declarations for the nodes */
typedef struct a_program A_Program;
typedef struct a_function A_Function;
typedef struct a_instruction A_Instruction;
typedef struct a_operand A_Operand;


/* TODO document 
 *
 */
typedef enum {
    A_PROGRAM, /* TODO document */
    A_FUNCTION, /* TODO document */
    A_STATEMENT, /* TODO document */
    A_OPERAND /* TODO document */
} A_ASTag; 


/* TODO document
 *
 */
typedef struct assembly_ast{
    A_ASTag node_type;

    union {
        A_Program *aprog;
        A_Function *afunc;
        A_Instruction *ainst;
        A_Operand *aoper;
    } node;
} Assembly_AST;


////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// NODE DEFINITIONS START HERE /////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////


/* TODO document
 *
 */
typedef struct a_program {
    union{
        struct afunc { Assembly_AST *afunc; } afunc; 
    } type;
} A_Program;


/* TODO document
 *
 */
typedef struct a_function {
    union{
        struct a_tempdef { Token *identifier; Assembly_AST **a_inst; } a_tempdef; 
    } type;
} A_Function;

/* TODO document 
 *
 */
typedef struct a_instruction {
    enum {
        MOV,
        RET
    } Instruct_Type; 

    union{
        struct a_mov { Assembly_AST *exp_op; } a_mov; /* the register for mov is %eax */
        struct a_ret { } a_ret;
    } type;
} A_Instruction;


/* TODO document 
 *
 */
typedef struct a_operand{
    union{
        struct conint { Token *con; } conint;
    } type;
} A_Operand; 

#endif
