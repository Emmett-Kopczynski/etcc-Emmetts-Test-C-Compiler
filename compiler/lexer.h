#ifndef LEXER_H_
#define LEXER_H_
/* lexer.h : TODO document
 *
 * To Do :
 *
 *      To Document :
 *
 */


/* c standard inclusions */
#include <stdio.h>

/* homemade inclusions */
#include "token.h"
#include "../driver/flag_table.h"

/* TODO document lexer_module
 *
 * NOTE : likely argumets include
 * - an empty token queue
 * - the flag lookup table
 * -
 *
 */
int lexer_module(FILE *source, TokenQueue *tokqueue, FlagLookupTable flags); 


#endif
