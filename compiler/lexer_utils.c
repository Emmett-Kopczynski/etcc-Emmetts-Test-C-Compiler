/* lexer_utils.c : TODO document
 *
 *
 * To Do : 
 *
 * To Implement: 
 *
 * To Test :
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
    
    if( strcmp(string, "void") == 0
            || strcmp(string, "int") == 0){
        /* type definition keywords 
         *  - void
         *  - int
         */
        return True;
    }  else if( strcmp(string, "return") == 0){
        /* get out of function/loop keywords
         *  - return 
         */
        return True;
    } else {
        return False;
    }

}


boolean is_integer(char *string){
    int i;
    i = 0;
    for ( i = 0; i < strlen(string); i++){
        if(isdigit(string[i]) == 0){
            return False;
        } 
    }
    return True;
    
}


boolean valid_identifier(char *string){
    
    /* all cases check if the first character is a legal first character */
    switch(string[0]){
        
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return False;
            break;

        
        /* default branch checks that all other characters are legal */
        default:
            int i;
            i = 0;
            for(i = 0; string[i] != '\0' ; i++){
                /* checks against all illegal characters */
                if(string[i] == '\\' || 
                        string[i] == '\'' || 
                        string[i] == '"' ||
                        string[i] == ':' || 
                        string[i] == '!' ||
                        string[i] == '@' || 
                        string[i] == '#' ||
                        string[i] == '$' || 
                        string[i] == '%' ||  
                        string[i] == '^' || 
                        string[i] == '&' ||
                        string[i] == '*' || 
                        string[i] == '(' ||
                        string[i] == ')' || 
                        string[i] == '-' ||
                        string[i] == '_' || 
                        string[i] == '+' ||   
                        string[i] == '=' || 
                        string[i] == '{' ||
                        string[i] == '[' || 
                        string[i] == '}' ||
                        string[i] == ']' || 
                        string[i] == '|' ||
                        string[i] == ';' || 
                        string[i] == ',' ||
                        string[i] == '<' || 
                        string[i] == '.' ||
                        string[i] == '>' || 
                        string[i] == '/' ||    
                        string[i] == '?' || 
                        string[i] == '`' ||
                        string[i] == '~' )
                    return False;
            }
    }
    
    /* if we make it here, it is assumed that the identifier is legal */
    return True;
} 


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

}


char *get_pretoken(char *line, int *start){
    char *pretoken = NULL; /* string to be returned */

    /* start by figuring out how long the pretoken will be */
    int j, i, size, end;
    j = i = size = end = 0;

    for(i = *start; !is_token_break(line[i]) && i < strlen(line) ; i++){
        size ++;
    }

    /* this is for if our only character was a token break like ; or { */
    if(size == 0){
        size = 1; 
    }
    
    /* allocate memory for the pretoken */
    pretoken = (char *) malloc(size * sizeof(char) + 1);
      
    /* end is the end index of our pretoken */
    end = size + *start;

    /* copy into the pretoken */
    for(i = *start, j = 0; i < end; i++, j++){
        /* j is the index of the pretoken, i is the index of the line */
        pretoken[j] = line[i];
    }
    pretoken[j] = '\0';

    /* re-assigns the start int for our next go through */
    *start += size;

    return pretoken;
} 


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
    } else if (valid_identifier(pre_token) ){ 
        /* if none of the above, and a valid id, then it is an identifier */
        return IDENTIFYER;
    } else {
        return NONE;
    }

}





