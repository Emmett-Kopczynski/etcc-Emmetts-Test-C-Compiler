#ifndef LEXER_UTILS_H_
#define LEXER_UTILS_H_
/* lexer_utils.h : TODO document
 *
 * To Do :
 *      
 *      To Document :
 *          - is_keyword
 *          - is_integer
 *          - get_pretoken
 *          - get_token_type
 *          - is_token_break
 *
 */


/* c standard inclusions */
#include <stdio.h>

/* homemade inclusions */
#include "token.h"
#include "../util/boolean.h"


/* TODO document is_keyword
 *
 *
 * Implemented Keywords ::
 *      - void
 *      - int
 */
boolean is_keyword(char *string);


/* TODO document is_integer
 *
 *
 */
boolean is_integer(char *string);


/* TODO document is_token_break 
 *
 *
 */
boolean is_token_break(char next);


/* TODO document get_pretoken
 *
 * NOTE :: this function gets the string that will be turned into a token (the pretoken)
 *
 */
char *get_pretoken(char *line, int *start);



/* TODO document get_token_type
 *
 * NOTE :: this function figures out what the tokentype of the given pretoken is
 *
 */
TokenType get_token_type(char *pretoken);




#endif
