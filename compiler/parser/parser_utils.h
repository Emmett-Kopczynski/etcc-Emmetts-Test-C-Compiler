#ifndef PARSER_UTILS_H_
#define PARSER_UTILS_H_
/* parser_utils.h : TODO document 
 *
 * To Do : 
 *
 *      To Document :
 *          - parser_utils.h
 *          - ast_printer
 *          - expect
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

/* TODO document
 *
 */
void ast_printer(AST *ast);


/* TODO document
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


/* TODO document 
 *
 */
int free_ast(AST *to_clean);


#endif
