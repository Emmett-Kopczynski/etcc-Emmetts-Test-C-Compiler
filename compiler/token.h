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
    /* TODO implement */
} Token;



/* TokenQueue : TODO document 
 *
 */
typedef struct token_queue {
    /* TODO implement */
} TokenQueue;



#endif
