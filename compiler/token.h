#ifndef TOKEN_H_
#define TOKEN_H_
/* token.h : TODO document
 *
 * To Do :
 *
 *      To Document :
 *          - Token
 *          - TokenType
 *          - TokenQueue
 *
 */



/* TokenType : TODO document
 *
 */
typedef enum {
    KEYWORD, /* keywords for the language, like int, void, and return */
    IDENTIFYER, /* ASCII identifiers for variables, functions, and more */
    CONSTANT, /* numeric literals throughout the code */
    SEMICOLON ./* Semicolons, the end of a phrase */
} TokenType;



/* Token : TODO document
 *
 */
typedef struct token {
    TokenType type;
    char *info;
    char *(*toString)(struct token *);
    /* TODO implement */
} Token;



/* TokenQueue : TODO document 
 *
 */
typedef struct token_queue {
    /* TODO implement */
} TokenQueue;





/* TOKEN FUNCTIONS START */
/* TODO make the token functions */
/* function possibiliteis :
 * - clean token 
 * - construct token 
 * - to string for the token
 *
 *
 */
/* TOKEN FUNCTIONS END */






/* TOKEN QUEUE FUNCTIONS START */
/* TODO make the TokenQueue functions */
/* function possibilities :
 * - clean queue function
 * - add to back of the queue
 * - peek from queue
 * - pop from front of the queue
 * - tostring function for the queue, line breaks on semicolons
 * - get size function
 *
 */
/* TOKEN QUEUE FUNCTION END */

#endif
