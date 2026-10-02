#ifndef EMISSION_UTILS_H_
#define EMISSION_UTILS_H_
/* emission_utils.h : the definitions of all the function to be implemented in emission_utils.c
 *  
 * To Do :
 *
 * Known Bugs :
 *
 *
 */

/* c inclusions */
#include <stdio.h>

/* homemade inclusions */
#include "../codegen/assembly_ast.h"
#include "../codegen/codegen_utils.h"


/* emit_program : emits the program to the given assembly file from the given Program
 * Assembly_AST node, uses recursive decent parsing to emit the rest of the tree as well
 *
 * Arguments :
 *      - assembly_source : type FILE * : the file we are emitting to
 *      - ass_ast : type Assembly_AST * : the Program node of an Assembly_AST
 *
 * returns :
 *      - an integer, 0 if everything went well, 1 if there was an error 
 *
 */
int emit_program(FILE *assembly_source, Assembly_AST *ass_ast);


/* emit_function : emits the function to the given assembly file from the given Function
 * Assembly_AST node, uses recursive decent parsing to emit the rest of the tree below it as well
 *
 * Arguments :
 *      - assembly_source : type FILE * : the file we are emitting to
 *      - ass_ast : type Assembly_AST * : the function node of an Assembly_AST
 *
 * returns :
 *      - an integer, 0 if everything went well, 1 if there was an error
 *
 */
int emit_function(FILE *assembly_source, Assembly_AST *ass_ast);


/* emit_instruction : emits the instruction to the given assembly file from the given Instruction
 * Assembly_AST node
 *
 * Arguments :
 *      - assembly_source : type FILE * : the file being emited to 
 *      - ass_ast : type Assembly_AST * : the function node of an Assembly_AST
 *
 * returns :
 *      - an integer, 0 if everything went wll, 1 if there was an error
 *
 */
int emit_instruction(FILE *assembly_source, Assembly_AST *ass_ast);


#endif
