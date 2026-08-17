/* lexer_utils.c : TODO document
 *
 *
 * To Do : 
 *
 * To Implement: 
 *  
 * To Test :
 *      - get_pretoken
 *      - is_token_break
 *      - is_integer
 *      - get_token_type
 *      - is_keyword
 *
 */


/* c standard inclusions */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* homemade inclusions */
#include "lexer_utils.h"
#include "token.h"
#include "../util/boolean.h"


boolean is_keyword(char *string){
    
    /* if tree to see if it matches a keyword */
    /* start with the type definitions */
    if( strcmp(string, "void") == 0
            || strcmp(string, "int") == 0){
        return True;
    } else {
        return False;
    }

} /* TODO test */


boolean is_integer(char *string){
    int i;
    i = 0;
    for ( i = 0; i < strlen(string); i++){
        if(isdigit(string[i]) == 0){
            return False;
        } 
    }
    return True;
    
} /* TODO test */


boolean is_token_break(char next){
    switch(next){
        case ';':
        case '(':
        case ')':
        case '{':
        case '}':
        case ' ':
        case '\n':
        case '\t':
            return True;
            break;

        default:
            return False;
    }

} /* TODO test */


char *get_pretoken(char *line, int *start){
    char *pretoken = NULL; /* string to be returned */

    /* start by figuring out how long the pretoken will be */
    int j, i, size, end;
    j = i = size = end = 0;

    for(i = *start; !is_token_break(line[i]) || i >= strlen(line) ; i++){
        size ++;
    }

    /* this is for if our only character was a token break like ; or { */
    if(size == 0){
        size = 1; 
    }
    
    /* allocate memory for the pretoken */
    pretoken = (char *) malloc(size * sizeof(char) );
      
    /* end is the end index of our pretoken */
    end = size + *start;

    /* copy into the pretoken */
    for(i = *start, j = 0; i <= end; i++, j++){
        /* j is the index of the pretoken, i is the index of the line */
        pretoken[j] = line[i];
    }

    /* re-assigns the start int for our next go through */
    *start += size;

    return pretoken;
} /* TODO test */


TokenType get_token_type(char *pre_token){
    
    /* selection tree to figure out the token_type */
    if(is_keyword(pre_token)){
        return KEYWORD;
    } else if(is_token_break(pre_token[0])){ 
        /* deals with all the token break tokens */
        switch(pre_token[0]){
            case ';':
                return SEMICOLON;
                break;
            case '(':
                return OPEN_PAR;
                break;
            case ')':
                return CLOSE_PAR;
                break;
            case '{':
                return OPEN_BRACE;
                break;
            case '}':
                return CLOSE_BRACE;
                break;

            default:
                return NONE;
        }
        
    } else if(is_integer(pre_token)){
        /* for integer constants */
        return CONSTANT;
    } else{
        /* if none of the above, it must be an identifier */
        return IDENTIFYER;
    }

}  /* TODO test */





