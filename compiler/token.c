/* token.c : TODO document
 *  
 *  To Do :
 *      
 *      To Implement:
 *          - construct_token
 *          - clean_token
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

    /* TODO set the function pointers */
    
    return ret_token;
} /* TODO implement */


int clean_token(Token *to_clean){
    
    /* clean the info */
    free(to_clean->info);
    to_clean->info = NULL;

    /* clean the token */
    free(to_clean);
    to_clean = NULL;

    return 0; /* TODO add error codes */
} /* TODO implement */

/* TOKEN FUNCTIONS END */





/* TOKEN NODE FUNCTIONS START */

TokenNode * construct_token_node(Token *data, TokenNode *prev, TokenNode *next){
    return NULL;
} /* TODO Implement */


int clean_token_node(TokenNode *to_clean){
    return -1;
} /* TODO implement */

/* TOKEN NODE FUNCTIONS END */





/* TOKEN QUEUE FUNCTIONS START */
/* TOKEN QUEUE FUNCTIONS END */






