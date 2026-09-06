#ifndef LEXER_H_
#define LEXER_H_
/* lexer.h : the header file for the lexer module of the compiler
 *
 * To Do :
 *
 */


/* c standard inclusions */
#include <stdio.h>

/* homemade inclusions */
#include "../token.h"
#include "../../driver/flag_table.h"


/* lexer_module : turns the given preprocessed c file (*.i) into a queue of tokens
 *
 * Arguments :
 *      - source : type FILE * : the preprocessed c file (*.i)
 *      - tokenqueue : type TokenQueue * : the empty tokenqueue we are going to fill
 *      - flags : type FlagLookupTable : a flag lookuptable based on the command line args
 *
 * Returns :
 *      - 0 if everything went well, otherwise 1
 *
 */
int lexer_module(FILE *source, TokenQueue *tokenqueue, FlagLookupTable flags); 


#endif
