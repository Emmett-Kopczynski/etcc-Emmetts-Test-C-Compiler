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
#include "codegen/codegen.h"
#include "codegen/codegen_utils.h"
#include "emission/emission.h"

int compile(char *sourcepath, FlagLookupTable flags){      
    int err = 0; /* if ever not 0, something has gone wrong */

    FILE *source = fopen(sourcepath, "r");  /* open the preprocessed file */
    TokenQueue *tqueue = construct_token_queue();  /* constructs the TokenQueue */
    AST *ast = NULL; /* declares the abstract sytnax tree */
    Assembly_AST *ass_ast = NULL; /* declares the assembly abstract syntax tree */

    /* runs stage 1 of the compiler, the lexer, filling up the tokenqueue */
    err = lexer_module(source, tqueue, flags);
    if(err != 0){
        fprintf(stderr, "LEXER ERROR :: %s is invalid\n", tqueue->first->data->info );
        goto error;
    }
    
    /* checks if the --lex flag was used, if so, stop now */
    if(flags.contains(&flags, LEX)){
        clean_token_queue(tqueue);
        fclose(source);
        return 0;
    }

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
    //ast_printer(ast);
    
    /* runs stage 3 of the compiler, generating the assembly abstract syntax tree from the abstract syntax tree */
    err = codegen_module(ast, &ass_ast, flags);
    if(err != 0){
        fprintf(stderr, "CODEGEN ERROR\n");
        goto error;
    }

    /* runs stage four, emitting the assembly abstract sytnax tree to a file, generating assembly code */
    err = emission_module(sourcepath, ass_ast, flags);
    if(err != 0) {
        fprintf(stderr, "EMISSION ERROR\n");
        goto error;
    }

    /* MASS CLEAN UP */ 
    fclose(source); /* close the preprocessed file */
    free_ast(ast); /* frees up the abstract syntax tree */
    free_assembly_ast(ass_ast);   

    return 0;

error:
    fclose(source);
    clean_token_queue(tqueue);  
    free_ast(ast); 
    free_assembly_ast(ass_ast); 
    return 1;
} /* TODO implement */

