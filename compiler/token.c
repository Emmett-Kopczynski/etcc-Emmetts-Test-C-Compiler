/* token.c : TODO document
 *  
 *  To Do :
 *      
 *      To Implement:
 *          - construct_token_queue
 *          - clean_token_queue
 *          - token_queue_enqueue
 *          - token_queue_peek
 *          - token_queue_dequeue
 *          - token_queue_size
 *          - token_queue_to_string
 *
 *
 *      To Update : 
 *          - clean_token
 *          - clean_token_node 
 *
 *      To Test :
 *
 *
 * Known Bugs :
 *
 *
 *
 */


/* c standard inclusions */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* homemade inclusions */
#include "token.h"





/* TOKEN FUNCTIONS START */

Token * construct_token(TokenType type, char *info){
    Token *ret_token; /* the token being built */

    ret_token = (Token *) malloc(sizeof(Token)); /* allocates token memory */
    
    ret_token->info = (char *) malloc( strlen(info) + 1); /* allocates info memory */

    strcpy(ret_token->info, info); /* copies info into ret_token */

    ret_token->type = type; /* sets the tokentype */
    
    return ret_token;
}


int clean_token(Token *to_clean){
    if(to_clean == NULL){
        return 0;
    }

    /* clean the info */
    free(to_clean->info);
    to_clean->info = NULL;

    /* clean the token */
    free(to_clean);
    to_clean = NULL;

    return 0; /* TODO add error codes */
} 

/* TOKEN FUNCTIONS END */





/* TOKEN NODE FUNCTIONS START */

TokenNode * construct_token_node(TokenType type, char *info, TokenNode *prev, TokenNode *next){
    TokenNode *ret_token_node;

    ret_token_node = (TokenNode *) malloc(sizeof(TokenNode)); /* allocates the memory for the token node */

    /* set up the insides of ret_token_node */
    ret_token_node->data = construct_token(type, info);
    ret_token_node->prev = prev;
    ret_token_node->next = next;


    return ret_token_node;
} 


int clean_token_node(TokenNode *to_clean){
    if(to_clean == NULL){
        return 0;
    }
 
    /* clean the stored token */
    clean_token(to_clean->data);
    to_clean->data = NULL;

    /* makes next and prev equal NULL */
    to_clean->next = NULL;
    to_clean->prev = NULL;
    
    /* free the TokenNode itself */
    free(to_clean);
    to_clean = NULL;

    return 0; /* TODO add error codes */
} 

/* TOKEN NODE FUNCTIONS END */






/* TOKEN QUEUE FUNCTIONS START */
/* TOKEN QUEUE FUNCTIONS END */








