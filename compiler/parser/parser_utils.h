#ifndef PARSER_UTILS_H_
#define PARSER_UTILS_H_
/* parser_utils.h : the header file that defines
 * all the utility functions for the Abstract 
 * Syntax Tree (AST) and for parsing
 *
 * To Do : 
 *
 *      To Document : TODO
 *          - parse_program
 *          - parse_function
 *          - parse_statement
 *          - parse_expression
 *
 */


/* c inclusions */


/* homemade inclusions */
#include "ast.h"
#include "../../util/boolean.h"
#include "../token.h"

/* ast_printer : prints the given AST (Abstract Syntax Tree) to stdout
 *
 * Arguments :
 *      - ast : type AST * : the Abstract Syntax tree to be printed
 *
 */
void ast_printer(AST *ast);


/* expect : compares the token at the front of a TokenQueue to a given Token,
 *  returning True if they are the same, and False if they are not
 *
 * Arguments :
 *      - expected : type Token * : the token we expect to be next in tokens
 *      - tokens ; type TokenQueue * : the TokenQueue we are grabing from
 *
 * Returns :
 *      - True if tokens.dequeue(tokens) returns a token equal to expected, otherwise
 *      returns False
 *
 */
boolean expect(Token *expected, TokenQueue *tokens);


/* TODO document
 *
 */
AST *parse_program(TokenQueue *tokens);


/* TODO document 
 *
 */
AST *parse_function(TokenQueue *tokens);


/* TODO document
 *
 */
AST *parse_statement(TokenQueue *tokens);


/* TODO document
 *
 */
AST *parse_expression(TokenQueue *tokens);


/* free_ast : free's all the allocated memory in the given Abstract Syntax Tree
 *
 * Arguments : 
 *      - to_clean : type AST * : the Abstract Syntax Tree to be freed
 *
 * Returns :
 *      - an integer, 0 if there were no errors, 1 if there were errors.
 */
int free_ast(AST *to_clean);


#endif
