/* token.c : the c file for the 3 token data structures, Token, TokenNode, and TokenQueue.
 * All three of these must be used carefully as a lot of the memory used by them must be given back
 *  
 *  To Do :
 *      
 *      To Implement:
 *
 *
 *      To Update : 
 *          - clean_token
 *          - clean_token_node 
 *          - clean_token_queue
 *
 *      To Test :
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

TokenQueue * construct_token_queue(){
    TokenQueue *ret_queue;
    
    /* allocates memory to ret_queue */
    ret_queue = malloc(sizeof(TokenQueue)); 
    
    /* sets elements of ret_queue */
    ret_queue->first = NULL;
    ret_queue->last = NULL;
    ret_queue->size = 0;
    
    /* does the function pointers */
    ret_queue->peek = &token_queue_peek;
    ret_queue->enqueue = &token_queue_enqueue;
    ret_queue->get_size = &token_queue_size;
    ret_queue->dequeue = &token_queue_dequeue;
    ret_queue->print = &token_queue_print;

    return ret_queue;
} 


int clean_token_queue(TokenQueue *to_clean){
    /* loop through entire queue to clean/remove all tokens */
    while(to_clean->size > 0){
        clean_token( token_queue_dequeue(to_clean) );
    }

    /* sets all inner data to null or 0 */
    to_clean->size = 0;
    to_clean->first = NULL;
    to_clean->last = NULL;

    /* free the memory taken up by the TokenQueue itself */
    free(to_clean);
    to_clean = NULL;

    return 0; /* TODO add error codes */
} 


void token_queue_enqueue(TokenQueue *queue, TokenType type, char *info){
    if(queue->size == 0){
        /* makes the first node in the queue */
       queue->last = construct_token_node(type, info, NULL, NULL); 
       queue->first = queue->last;
    } else {
        /* adds to the beginning of the queue */
        
        /* makes a node right before the first one */
        queue->first->prev = construct_token_node(type, info, NULL, queue->first);
        
        /* reassigns first */
        queue->first = queue->first->prev;
    }

    /* updates size */
    queue->size += 1;

} 


Token *token_queue_peek(TokenQueue *queue){
    /* NOTE :: this memeory must be deleted outside of this function*/
    Token *ret_token = construct_token(queue->last->data->type, queue->last->data->info); 
        
    return ret_token;
} 


Token *token_queue_dequeue(TokenQueue *queue){
    if(queue->size == 0){
        return NULL; /* not supposed to happen */
    }

    /* extracts the needed node */
    TokenNode *ret_node = queue->last;
    
    /* moves last back one */
    queue->last = queue->last->prev;

    /* extracts the token from the node */
    Token *ret_token = construct_token(ret_node->data->type, ret_node->data->info);
    
    /* cleans up the now uneeded node */
    clean_token_node(ret_node);
    

    queue->size -= 1;
    return ret_token;
}


int token_queue_size(TokenQueue *queue){
    return queue->size;
} 


int token_queue_print(TokenQueue *queue){
    TokenNode *cur = queue->last;
    
    /* goes through every node in the queue */
    while(cur != NULL){
        printf("%d(%s) ", cur->data->type, cur->data->info);
        
        /* makes a newline if info is ;, {, or } */
        if( cur->data->type == SEMICOLON
                || cur->data->type == OPEN_BRACE
                || cur->data->type == CLOSE_BRACE) {
            printf("\n");
        }
        
        /* moves on to the next node */
        cur = cur->prev;
    }

    return 0;   
}

/* TOKEN QUEUE FUNCTIONS END */








