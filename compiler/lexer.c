/* lexer.c : TODO document
 *
 * To Do :
 *  
 *      To Implement :
 *          - lexer_module
 *
 *      To Test :
 *
 *
 * Known Bugs : 
 *
 *
 */

/* c standard inclusions */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* homemade inclusions */
#include "lexer.h"
#include "token.h"
#include "../driver/flag_table.h"
#include "lexer_utils.h"


int lexer_module(FILE *source, TokenQueue *tokenqueue, FlagLookupTable flags){
    /* Setup Variables */

    char *line = NULL;
    int line_num = 0;
    ssize_t bytes_read;
    size_t bytes_stored;
    
    int line_start;
    
    char *pretoken = NULL;

    /* the lexer loop */
    while( (bytes_read = getline( &line, &bytes_stored, source )) != -1 ){
        line_start = 0; /* reset linestart */
        line_num++;
        while(line_start < strlen(line)){
            if(line[line_start] == ' ' || line[line_start] == '\n'){
                /* NOTE :: keep in mind this will need to be changed when we add 
                 * string support */
                line_start += 1;
                continue;
            } else{
                pretoken = get_pretoken(line, &line_start);
                
                /* add a new token to the queue */
                tokenqueue->enqueue(tokenqueue, get_token_type(pretoken), pretoken);
                
                if(tokenqueue->first->data->type == NONE){
                    fprintf(stderr, "ERROR ON LINE %d IN PREPROCESSED FILE (check source.i) \n", line_num);
                    free(pretoken);
                    free(line);
                    return 1;
                }

                /* reset the pretoken */
                free(pretoken);
                pretoken = NULL;

            }
        }
    }
    

    /* free the line buffer */
    free(line);
    line = NULL;

    return 0;
}



