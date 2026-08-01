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
 *          -construct_token
 *
 */



/* TokenType : TODO document
 *
 */
typedef enum {
    KEYWORD, /* keywords for the language, like int, void, and return */
    IDENTIFYER, /* ASCII identifiers for variables, functions, and more */
    CONSTANT, /* numeric literals throughout the code */
    SEMICOLON, /* Semicolons, the end of a phrase */
    OPEN_BRACE, /* the open brace { */ 
    CLOSE_BRACE, /* the close brace } */
    OPEN_PAR, /* the open parenthasis ( */
    CLOSE_PAR /* the closed parenthasis ) */
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


/* TokenNode : TODO document 
 *
 *
 */
typedef struct token_node {
    Token data;
    Token next;
    Token prev;
} TokenNode;


/* TokenQueue : TODO document 
 *
 */
typedef struct token_queue {
    TokenNode first;
    TokenNode last;
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

/* TODO document construct_token 
 *
 */
Token * construct_token(TokenType type, char *info);


/* TODO document clean_token
 *
 */
int clean_token(Token *to_clean);


/* TOKEN FUNCTIONS END */






/* TOKEN NODE FUNCTIONS START */
/* TODO make the token node functions */
/* TOKEN NODE FUNCTIONS END */






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
