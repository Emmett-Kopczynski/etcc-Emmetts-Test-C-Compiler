#ifndef LEXER_UTILS_H_
#define LEXER_UTILS_H_
/* lexer_utils.h : the header file that contains the documentation and declarations for the functions 
 * in the lexer_utils.c file
 *
 * To Do :
 *      
 */


/* c standard inclusions */
#include <stdio.h>

/* homemade inclusions */
#include "../token.h"
#include "../../util/boolean.h"


/* is_keyword : returns True if the given string is a keyword, otherwise False
 *
 * Arguments :
 *      - string : type char * : the string we are checking
 *
 * Returns :
 *      - True if the given string is a keyword, otherwise returns False
 *
 * Implemented Keywords :
 *      - void
 *      - int
 *      - return
 *
 */
boolean is_keyword(char *string);


/* is_integer : checks if the given string is an integer
 *
 * Arguments :
 *      - string : type char * : the string we are checking
 *
 * Returns : 
 *      - True if the given string is an integer, otherwise False
 *
 */
boolean is_integer(char *string);


/* valid_identifier : checks if the given string is a valid identifier (name of function or variable)
 *
 * Arguments :
 *      - string : type char * : the string we are checking
 *
 * Returns :
 *      - True if the given string is a valid identifier, otherwise False
 *
 * NOTE :: will mark most keywords as valid despite keywords being invalid identifiers
 *
 */
boolean valid_identifier(char *string);


/* is_token_break : returns True if the given character is a "Token Break" (a character that splits up tokens
 * like whitespace, (, ;, e.t.c)
 *
 * Arguments :
 *      - next : type char : the character we are checking
 *
 * Returns : 
 *      - True if the given character is a Token Break, otherwise False
 *
 */
boolean is_token_break(char next);


/* get_pretoken : gets a substring from the given string that will become the data stored in 
 * a token 
 *
 * Arguments :
 *      - line : type char * : the string we are getting a substring from 
 *      - start : type int * : a pointer to an integer that represents the starting point 
 *                             for our search in line
 *
 * Returns : 
 *      - a substring that will be turned into a Token in the future
 *
 */
char *get_pretoken(char *line, int *start);



/* get_token_type : returns the token type of the given string if that string was a token
 *  
 * Arguments :
 *      - pretoken : type char * : the string that we are examining
 *
 * Returns :
 *      - the TokenType of the given string if it was a token
 *
 *
 * TLDR :: this function figures out what the tokentype of the given pretoken is
 *
 */
TokenType get_token_type(char *pretoken);


#endif
