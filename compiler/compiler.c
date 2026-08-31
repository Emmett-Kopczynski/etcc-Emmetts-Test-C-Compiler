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
#include "lexer/lexer.h"
#include "token.h"
#include "../driver/flag_table.h"
#include "parser/parser.h"    

int compile(char *sourcepath, FlagLookupTable flags){      
    int err = 0; /* if ever not 0, something has gone wrong */

    FILE *source = fopen(sourcepath, "r");  /* open the preprocessed file */
    TokenQueue *tqueue = construct_token_queue();  /* constructs the TokenQueue */
    AST *ast = NULL; /* declares the abstract sytnax tree */

    /* runs stage 1 of the compiler, the lexer, filling up the tokenqueue */
    err = lexer_module(source, tqueue, flags);
    if(err != 0){
        fprintf(stderr, "LEXER ERROR :: %s is invalid\n", tqueue->first->data->info );
        goto error;
    }
    
    /* TODO implement the --lex flag here */    

    /* TODO REMOVE THE DEBUG PRINT */
    //tqueue->print(tqueue);
    
    /* runs stage 2 of the compiler, the parser building the abstract syntax tree */
    err = parser_module(tqueue, &ast, flags);
    if(err != 0){
        fprintf(stderr, "PARSER ERROR\n");
        goto error;
    }
    clean_token_queue(tqueue);  /* cleans up the TokenQueue at the end of stage 2 */
    
    /* TODO remove the debug print */
    ast_printer(ast);

    /* TODO implement stage 3 */
    /* TODO implement stage 4 */
    


    /* MASS CLEAN UP */ 
    fclose(source); /* close the preprocessed file */
    free_ast(ast); /* frees up the abstract syntax tree */

    return 0;

error:
    fclose(source); /* close the preprocessed file */
    clean_token_queue(tqueue);  /* cleans up the TokenQueue */
    free_ast(ast); /* cleans up the ast */
    return 1;
} /* TODO implement */

