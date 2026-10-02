#ifndef ASSEMBLY_AST_H_
#define ASSEMBLY_AST_H_
/* assembly_ast.h : contains the definition
 * of the Assembly_AST and all it's node types
 *
 * To Do :
 *      To Document :
 *          - A_Program
 *          - A_Function
 *          - A_Instruction
 *          - A_Expression
 *
 * Known Bugs :
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


/* A_ASTag : the tag for the
 * Assembly_AST that represents the node type
 *
 */
typedef enum {
    A_PROGRAM,  /* represents a program node for the Assembly_AST */
    A_FUNCTION, /* represents a function node for the Assembly_AST */
    A_INSTRUCTION, /* represents an instruction node for the Assembly_AST */
    A_OPERAND /* represents an operand node type for the Assembly_AST */
} A_ASTag; 


/* Assembly_AST : an Assembly Abstract Syntax Tree
 *
 * Variables :
 *      - node_type : type A_ASTag : signifies the node_type of the Assembly_AST
 *      - node : type union : leads to the node information
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


/* A_Program : a program node for the Assembly_AST
 *
 * Variables :
 *      - type : type union : the relevant info given the Program
 */
typedef struct a_program {
    union{
        struct afunc { Assembly_AST *afunc; } afunc; 
    } type;
} A_Program;


/* A_Function : a function node for the Assembly_AST
 *
 * Variables :
 *      - type : type union : the relevant info given the Function
 *
 */
typedef struct a_function {
    union{
        struct a_tempdef { Token *identifier; Assembly_AST **a_inst; } a_tempdef; 
    } type;
} A_Function;

/* A_Instruction : an instruction node for the Assembly_AST
 *
 * Variables :
 *      - Instruct_Type : type enum : signifies the instruction type
 *      - type : type union : the relevant info given the instruction type
 *
 */
typedef struct a_instruction {
    enum {
        MOV,
        RET
    } Instruct_Type; 

    union{
        struct a_mov { Assembly_AST *exp_op; } a_mov; /* the register for mov is %eax */
    } type;
} A_Instruction;


/* A_Operand : an operand node for the Assembly_AST
 *
 * Variables :
 *      - type : type union : the relevant info given the operand
 */
typedef struct a_operand{
    union{
        struct conint { Token *con; } conint;
    } type;
} A_Operand; 

#endif
