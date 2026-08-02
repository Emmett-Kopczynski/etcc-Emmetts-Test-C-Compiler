#ifndef TOKEN_H_
#define TOKEN_H_
/* token.h : TODO document
 *
 * To Do :
 *
 *      To Document :
 *          - TokenType
 *          - TokenQueue
 *          - construct_token
 *          - clean_token
 *          - construct_token_node
 *          - clean_token_node
 *          - construct_token_queue
 *          - clean_token_queue
 *          - token_queue_enqueue
 *          - token_queue_peek
 *          - token_queue_dequeue
 *          - token_queue_size
 *          - token_queue_to_string
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



/* Token : represents a single token of a c program, like a semicolon, constant variable, e.t.c
 *
 * Variables : 
 *      - type : type TokenType : the type of token we are storing
 *      - info : type char * : the info stored in the token
 *
 */
typedef struct token {
    TokenType type;
    char *info;
} Token;


/* TokenNode : TODO document 
 *
 *
 */
typedef struct token_node {
    Token *data;
    struct token_node *next;
    struct token_node *prev;
} TokenNode;


/* TokenQueue : TODO document 
 *
 */
typedef struct token_queue {
    TokenNode *first;
    TokenNode *last;
    int size;
} TokenQueue;





/* TOKEN FUNCTIONS START */


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


/* TODO document construct_token_node
 *
 */
TokenNode * construct_token_node(TokenType type, char *info, TokenNode *prev, TokenNode *next);


/* TODO document clean_token_node
 *
 */
int clean_token_node(TokenNode *to_clean);


/* TOKEN NODE FUNCTIONS END */






/* TOKEN QUEUE FUNCTIONS START */


/* TODO document construct_token_queue
 *
 */
TokenQueue * construct_token_queue();


/* TODO document clean_token_queue
 *
 */
int clean_token_queue(TokenQueue *to_clean);


/* TODO document token_queue_enqueue
 *
 */
void token_queue_enqueue(TokenQueue *queue, Token *to_add);


/* TODO document token_queue_peek
 *
 */
Token *token_queue_peek(TokenQueue *queue);


/* TODO document token_queue_dequeue
 *
 */
Token *token_queue_dequeue(TokenQueue *queue);


/* TODO document token_queue_size
 *
 */
int token_queue_size(TokenQueue *queue);


/* TODO document token_queue_to_string
 *
 */
char *token_queue_to_string(TokenQueue *queue);


/* TOKEN QUEUE FUNCTION END */




#endif
