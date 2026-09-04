#ifndef EMISSION_UTILS_H_
#define EMISSION_UTILS_H_
/* emission_utils.h : TODO document
 *  
 *  To Do :
 *
 *      To Document :
 *          - emission.h
 *          - emit_program
 *          - emit_function
 *          - emit_instruction
 *
 */

/* c inclusions */
#include <stdio.h>

/* homemade inclusions */
#include "../codegen/assembly_ast.h"
#include "../codegen/codegen_utils.h"


/* TODO Document 
 *
 */
int emit_program(FILE *assembly_source, Assembly_AST *ass_ast);


/* TODO Document 
 *
 */
int emit_function(FILE *assembly_source, Assembly_AST *ass_ast);


/* TODO Document 
 *
 */
int emit_instruction(FILE *assembly_source, Assembly_AST *ass_ast);


#endif
