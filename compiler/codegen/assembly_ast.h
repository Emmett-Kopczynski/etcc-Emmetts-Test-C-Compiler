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

/* foreward declarations for the nodes */
typedef struct a_program A_Program;
typedef struct a_function A_Function;
typedef struct a_instruction A_Instruction;
typedef struct a_expression A_Expression;


/* TODO document 
 *
 */
typedef enum {
    A_PROGRAM, /* TODO document */
    A_FUNCTION, /* TODO document */
    A_STATEMENT, /* TODO document */
    A_EXP /* TODO document */
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
        A_Expression *aexpr;
    } node;
} Assembly_AST; /* TODO implement */


////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// NODE DEFINITIONS START HERE /////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////


/* TODO document
 *
 */
typedef struct a_program {
} A_Program; /* TODO implement */


/* TODO document
 *
 */
typedef struct a_function {
} A_Function; /* TODO implement */

/* TODO document 
 *
 */
typedef struct a_instruction {
} A_Instruction; /* TODO implement */


/* TODO document 
 *
 */
typedef struct a_expression{
} A_Expression; /* TODO implement */

#endif
