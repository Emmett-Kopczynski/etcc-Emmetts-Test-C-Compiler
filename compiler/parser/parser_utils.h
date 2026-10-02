#ifndef PARSER_UTILS_H_
#define PARSER_UTILS_H_
/* parser_utils.h : the header file that defines
 * all the utility functions for the Abstract 
 * Syntax Tree (AST) and for parsing
 *
 * To Do : 
 *
 * Known Bugs :
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


/* parse_program : generates a Program node for an AST given a TokenQueue, uses recursive decent parsing to 
 * generate all the nodes below it in the tree as well
 *
 * Arguments :
 *      - tokens : type TokenQueue * : the Queue of Tokens we are parsing to make the tree
 *
 * Returns :
 *      - a program node for an Abstract Syntax Tree and all the nodes below it, returns NULL if there
 *      was an error
 *
 */
AST *parse_program(TokenQueue *tokens);


/* parse_function : generates a Function node for an AST given a TokenQueue, uses recursive decent parsing 
 * to generate all the nodes below it in the tree as well
 *
 * Arguments : 
 *      - tokens : type TokenQueue *  : the Queue of Tokens we are parsing to make the tree
 *
 * Returns : 
 *      - a function node for an Abstract Syntax Tree and all the nodes below it, returns NULL if there
 *      was an error
 *
 */
AST *parse_function(TokenQueue *tokens);


/* parse_statement : generates a Statement node for an AST given a TokenQueue, uses recursive decent parsing
 * to genrate all the nodes below it in the tree as well
 *
 * Arguments :
 *      - tokens : type TokenQueue * : the Queue of Tokens we are parsing to make the tree
 *
 * Returns : 
 *      - a statement node for an Abstract Syntax Tree and all the nodes below it, returns NULL if there was an 
 *      error
 *
 */
AST *parse_statement(TokenQueue *tokens);


/* parse_expression : generates an Expression node for an AST given a TokenQueue
 *
 * Aruments :
 *      - token : type TokenQueue * : the Queue of TOkens we are parsing to make the tree
 *
 * Returns :
 *      - an Expression node for an AST, returns NULL if there was an error 
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
