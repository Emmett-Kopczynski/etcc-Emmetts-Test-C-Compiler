#ifndef TOKEN_H_
#define TOKEN_H_ 
/* token.h : the .h file for the 3 Token data structures, Token, TokenNode, and TokenQueue
 *
 * To Do :
 *
 *      To Document :
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


/* construct_token_node : constructs a token node with the given properties
 * 
 * Arguments : 
 *      - type : type TokenType : the type of token that the node is storing
 *      - info : type char * : the info that the inner token is storing
 *      - prev : type TokenNode * : the reference to the previous node
 *      - next : type TokenNode * : the reference to the next node
 *
 * Returns : 
 *      - the TokenNode pointer constructed to the given specs
 *
 */
TokenNode * construct_token_node(TokenType type, char *info, TokenNode *prev, TokenNode *next);


/* clean_token_node : cleans the given token node, freeing all memory that the 
 * token node took up
 *
 * Arguments :
 *      - to_clean : type TokenNode * : the TokenNode pointer we are cleaning
 *
 * Returns : 
 *      - 0 if everything went well, otherwise a different number
 *
 */
int clean_token_node(TokenNode *to_clean);


/* TOKEN NODE FUNCTIONS END */






/* TOKEN QUEUE FUNCTIONS START */


/* construct_token_queue : constructs an empty TokenQueue
 *
 * Returns : 
 *      - an empty TokenQueue
 *
 */
TokenQueue * construct_token_queue();


/* clean_token_queue : cleans the memory for a TokenQueue, 
 * freeing all memory it took up in the heap
 *
 * Arguments : 
 *      - to_clean : type TokenQueue * : the TokenQueue to be cleaned 
 *
 * Returns : 
 *      - 0 if everything went well, otherwise another number
 *
 */
int clean_token_queue(TokenQueue *to_clean);


/* token_queue_enqueue : adds a token with the given specs into a new node at the back of
 * the TokenQueue
 *
 * Arguments :
 *      - queue : type TokenQueue * : the TokenQueue we are adding to
 *      - type : type TokenType : the type of token we are adding
 *      - info : type char * : the info the new token will store
 *
 */
void token_queue_enqueue(TokenQueue *queue, TokenType type, char *info);


/* token_queue_peek : return the token at the front of the given TokenQueue
 *
 * Arguments :
 *      - queue : type TokenQueue * : the TokenQueue we are peeking from
 *
 * Returns : 
 *      - a Token * that is a copy of the one stored at the front of the TokenQueue, 
 *      you must clean this new token at some point
 *
 */
Token *token_queue_peek(TokenQueue *queue);


/* token_queue_dequeue : removes the token at the front of the given
 * TokenQueue, and returns a copy of it
 *
 * Arguments :
 *      - queue : type TokenQueue * : the TokenQueue we are dequeueing from
 *
 * Returns : 
 *      - A Token * that is a copy of the Token that was stored at the front of the TokenQueue
 *       before we just removed it
 *
 */
Token *token_queue_dequeue(TokenQueue *queue);


/* token_queue_size : returns the number of TokenNodes in the given
 * TokenQueue
 *
 * Arguments : 
 *      - queue : TokenQueue * : the TokenQueue we are checking the size of
 *
 * Returns : 
 *      - an integer that represents the number of elements in the given 
 *      TokenQueue
 *
 */
int token_queue_size(TokenQueue *queue);


/* token_queue_print : prints the given TokenQueue to the console from front to back; that is, 
 * in the order that the elements were enqueued
 *
 * Arguments : 
 *      - queue : type TokenQueue * : the TokenQueue that we are printing
 *
 * Return : 
 *      - a 0 if everyghing went well, otherwise a different number
 *
 */
int token_queue_print(TokenQueue *queue);


/* TOKEN QUEUE FUNCTION END */




#endif
