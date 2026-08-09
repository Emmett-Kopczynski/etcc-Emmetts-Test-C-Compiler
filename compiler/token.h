#ifndef TOKEN_H_
#define TOKEN_H_ 
/* token.h : TODO document
 *
 * To Do :
 *
 *      To Document :
 *          - construct_token_node
 *          - clean_token_node
 *          - construct_token_queue
 *          - clean_token_queue
 *          - token_queue_enqueue
 *          - token_queue_peek
 *          - token_queue_dequeue
 *          - token_queue_size
 *          - token_queue_print
 *
 */



/* TokenType : the different types of token that the Token data 
 * structure might store
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
 * Related Functions : 
 *      - construct_token
 *      - clean_token
 *
 */
typedef struct token {
    TokenType type;
    char *info;
} Token;


/* TokenNode : a single node that stores a token, and 2 refrences
 * to other TokenNodes, a prev and a next. Mainly used in the TokenQueue
 * data structure
 *
 *  Related Functions :
 *      - construct_token_node
 *      - clean_token_node 
 *
 */
typedef struct token_node {
    Token *data;
    struct token_node *next;
    struct token_node *prev;
} TokenNode;


/* TokenQueue : The main structure for orderly storing tokens, in
 * a FIFO queue
 *
 * Variables : 
 *      - first : type TokenNode * : back of the queue
 *      - last : type TokenNode * : front of the queue
 *      - size : type int : the number of elements in the queue
 *
 * Function Pointers :
 *      - enqueue : see token_queue_enqueue
 *      - dequeue : see token_queue_dequeue
 *      - get_size : see token_queue_size
 *      - peek : see token_queue_peek
 *      - print : see token_queue_print
 *
 */
typedef struct token_queue {
    TokenNode *first;
    TokenNode *last;
    int size;

    /* function pointers */
    void (*enqueue)(struct token_queue *queue, TokenType type, char *info);
    Token *(*peek)(struct token_queue *queue);
    Token *(*dequeue)(struct token_queue *queue);
    int (*get_size)(struct token_queue *queue);
    int (*print)(struct token_queue *queue);

} TokenQueue;





/* TOKEN FUNCTIONS START */


/* construct_token : constructs a token data structure with the 
 * given information
 *
 * Arguments : 
 *      - type : type TokenType : the type of token we are making
 *      - info : type char * : the info stored in the token
 *
 * Returns :
 *      - a token pointer with allocated memory, MUST BE CLEANED
 *
 */
Token * construct_token(TokenType type, char *info);


/* clean_token : cleans the given token, freeing all memory that the
 * token took up
 *
 * Arguments : 
 *      - to_clean : type Token * : the Token we are cleaning
 *
 * Returns :
 *      - 0 if everything went well, otherwise a different number
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
void token_queue_enqueue(TokenQueue *queue, TokenType type, char *info);


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
int token_queue_print(TokenQueue *queue);


/* TOKEN QUEUE FUNCTION END */




#endif
