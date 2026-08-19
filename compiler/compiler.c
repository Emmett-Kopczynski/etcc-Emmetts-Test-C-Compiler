/* compiler.c : the .c file that runs the compilation steps for the main compiler
 *
 * To Do : 
 *      
 *      To Implement :
 *          - compile
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

/* homemade inclusions */
#include "compiler.h"
#include "lexer.h"
#include "token.h"
#include "../driver/flag_table.h"
    

int compile(char *sourcepath, FlagLookupTable flags){      
    int err = 0; /* if ever not 0, something has gone wrong */

    FILE *source = fopen(sourcepath, "r");  /* open the preprocessed file */
    TokenQueue *tqueue = construct_token_queue();  /* constructs the TokenQueue */


    /* runs stage 1 of the compiler, the lexer, filling up the tokenqueue */
    err = lexer_module(source, tqueue, flags);
    if(err != 0){
        fprintf(stderr, "LEXER ERROR :: %s is invalid\n", tqueue->first->data->info );
        fclose(source); /* close the preprocessed file */
        clean_token_queue(tqueue);  /* cleans up the TokenQueue */
        return 1;
    }
        

    /* TODO REMOVE THE DEBUG PRINT */
    tqueue->print(tqueue);



    /* TODO implement stage 2 */
    /* TODO implement stage 3 */
    /* TODO implement stage 4 */
    


    /* MASS CLEAN UP */ 
    fclose(source); /* close the preprocessed file */
    clean_token_queue(tqueue);  /* cleans up the TokenQueue */


    return 0;
} /* TODO implement */

