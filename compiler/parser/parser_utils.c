/* parser_utils.c : the c file that holds all the main utilities for the parser module,
 * this file mainly concerns itself with building the abstract syntax tree defined in ast.h
 * using the parse_NODETYPE functions. Functions for printing and freeing the 
 * abstract syntax tree can also be found here
 *
 * To Do : 
 *
 *      To Implement :
 *
 *      To Test :
 *          - free_ast
 *          - ast_printer
 *          - expect
 *          - parse_program
 *          - parse_function
 *          - parse_statement
 *          - parse_expression
 *
 */

/* c inclusions */
#include <stdio.h>
#include <stdlib.h>


/* homemade inclusions */
#include "parser_utils.h"


void ast_printer(AST *ast){
    if(ast == NULL){
        printf("NULL()\n");
        return;
    }

    switch(ast->node_type){
        case PROGRAM: 
            printf("Program(\n");
            ast_printer(ast->node.prog->type.func.func);
            printf(")\n");
            break;

        case FUNCTION:
            printf("Function(\n");
            printf("name=\"%s\"\n", ast->node.func->type.tempdef.identifier->info);
            printf("Body = ");
            ast_printer(ast->node.func->type.tempdef.stat);
            printf(")\n");
            break;


        case STATEMENT: 
            printf("Statement(\nReturn ");
            ast_printer(ast->node.stat->type.ret.exp);
            printf(")\n");
            break;

        case EXP: 
            printf("Constant(%d)\n", atoi(ast->node.expr->type.conint.con->info)); 
            break;

        default:
            fprintf(stderr, "ERROR\n");
            return; 

    }
}


boolean expect(Token *expected, TokenQueue *tokens){
    Token *actual = tokens->dequeue(tokens);

    boolean comp;
    comp = tokens_equal(actual, expected);


    if(comp == False){ /* the token was unexpected */
        fprintf(stderr, "Syntax Error\n%s was not the expected %s\n", actual->info, expected->info);
        clean_token(actual); clean_token(expected);
        return False;
    } else{
        clean_token(actual); clean_token(expected);
        return True;
    }

} 


AST *parse_program(TokenQueue *tokens){
    AST *prog;
    prog = (AST *) malloc(sizeof(AST));
    
    prog->node_type = PROGRAM;    

    /* we expect a program node to contain a function node, hence the following */
    prog->node.prog = (Program *) malloc(sizeof(Program));
    prog->node.prog->type.func.func = parse_function(tokens);

    if(prog->node.prog->type.func.func == NULL){ /* if something failed */
        free(prog->node.prog);
        free(prog); 
        return NULL;
    }

    return prog;
} 


AST *parse_function(TokenQueue *tokens){
    AST *func;
    func = (AST *) malloc(sizeof(AST));

    func->node_type = FUNCTION;
    func->node.func = (Function *) malloc(sizeof(Function));

    func->node.func->type.tempdef.identifier = NULL;

    /* we expect the function node to have a sieries of tokens, hence the following */
    if(expect( construct_token(KEYWORD, "int"), tokens) == False){
        goto error;
    }
    
    /* get the identifier token */
    func->node.func->type.tempdef.identifier = tokens->dequeue(tokens);
    if(func->node.func->type.tempdef.identifier->type != IDENTIFYER){
        goto error;
    }
    
    if( expect( construct_token(OPEN_PAR, "("), tokens) == False || 
            expect( construct_token(KEYWORD, "void"), tokens) == False ||
            expect( construct_token(CLOSE_PAR, ")"), tokens) == False ||
            expect( construct_token(OPEN_BRACE, "{"), tokens) == False)
    {
        goto error;
    }
    
    /* get the statement node */
    func->node.func->type.tempdef.stat = parse_statement(tokens);
    if(func->node.func->type.tempdef.stat == NULL)
        goto error;

    if( expect( construct_token(CLOSE_BRACE, "}"), tokens) == False )
        goto error;
    
    return func;

error:
    if( func->node.func->type.tempdef.identifier != NULL)
        clean_token(func->node.func->type.tempdef.identifier);
    
    free(func->node.func);
    free(func);
    return NULL;
} 


AST *parse_statement(TokenQueue *tokens){
    AST *stat;
    stat = (AST *) malloc(sizeof(AST));

    stat->node_type = STATEMENT;
    stat->node.stat = (Statement *) malloc(sizeof(Function));

    stat->node.stat->type.ret.exp = NULL;

    if(expect( construct_token(KEYWORD, "return"), tokens) == False)
        goto error;
    
    /* gets the expression */
    stat->node.stat->type.ret.exp = parse_expression(tokens);
    if(stat->node.stat->type.ret.exp == NULL)
        goto error;
    if(expect( construct_token(SEMICOLON, ";"), tokens) == False)
        goto error;
    
    return stat;

error:
    if(stat->node.stat->type.ret.exp != NULL)
        free_ast(stat->node.stat->type.ret.exp);     
    fprintf(stderr, "ERROR :: Something wrong with return statement\n");
    free(stat->node.stat);
    free(stat);
    stat = NULL;
    return NULL;

} 


AST *parse_expression(TokenQueue *tokens){
    AST *exp;
    exp = (AST *) malloc(sizeof(AST));

    exp->node_type = EXP;
    exp->node.expr = (Expression *) malloc(sizeof(Expression));
    
    exp->node.expr->type.conint.con = NULL;

    /* fill in the constant token */
    exp->node.expr->type.conint.con = tokens->dequeue(tokens);
    if(exp->node.expr->type.conint.con == NULL) goto error;
    if(exp->node.expr->type.conint.con->type != CONSTANT)
        goto error;

    return exp;

error:
    fprintf(stderr, "ERROR :: Nothing returned from main\n");
    if(exp->node.expr->type.conint.con != NULL)
        clean_token(exp->node.expr->type.conint.con);

    free(exp->node.expr);
    free(exp);
    exp = NULL;
    return NULL;
} 


int free_ast(AST *to_clean){
    if(to_clean == NULL)
                return 0;

    switch(to_clean->node_type){
        case PROGRAM: 
            free_ast(to_clean->node.prog->type.func.func);
            free(to_clean->node.prog);
            free(to_clean);
            to_clean = NULL;
            break;

        case FUNCTION: 
            free_ast(to_clean->node.func->type.tempdef.stat);
            clean_token(to_clean->node.func->type.tempdef.identifier);
            free(to_clean->node.func);
            free(to_clean);
            to_clean = NULL;
            break;

        case STATEMENT: 
            free_ast(to_clean->node.stat->type.ret.exp);
            free(to_clean->node.stat);
            free(to_clean);
            to_clean = NULL;
            break;

        case EXP: 
            clean_token(to_clean->node.expr->type.conint.con);
            free(to_clean->node.expr);
            free(to_clean);
            break;

        default: 
            fprintf(stderr, "ERROR\n");
            return 1;

    }
    return 0;
} 
