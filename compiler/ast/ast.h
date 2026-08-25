#ifndef AST_H_
#define AST_H_
/* ast.h : TODO document 
 *
 * To Do :
 *      
 *      To Document :
 *          - ASTag
 *          - AST
 *      
 *      To Implement :
 *          - AST
 */

/* c inclusions */

/* homemade inclusions */
#include "../token.h"

/* foreward declarations for the nodes */
typedef struct program Program;
typedef struct function Function;
typedef struct statement Statement;
typedef struct expression Expression;

/* TODO document 
 *
 */
typedef enum {
    PROGRAM, /* TODO document */
    FUNCTION, /* TODO document */
    STATEMENT, /* TODO document */
    EXP /* TODO document */
} ASTag;


/* TODO document 
 *
 */
typedef struct ast {
    ASTag node_type;
    
    union {
        Program *prog;
        Function *func;
        Statement *stat;
        Expression *expr;
    } node;
 
} AST;


////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// NODE DEFINITIONS START HERE ////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////


/* TODO document
 *
 */
typedef struct program{
    union {
        struct func { AST *func; } func; /* <program> ::= <function> */
    } type;
} Program; /* TODO implement */


/* TODO document
 *
 */
typedef struct function{
    union {
        struct tempdef { Token *identifier; AST *stat; } tempdef; /* <function> ::= "int" <identifier:Token> "(" "void" ")" "{" <statement> "}" */ /* NOTE : not a permanant definition */
    } type;
} Function; /* TODO implement */


/* TODO document
 *
 */
typedef struct statement{
    union {
        struct ret { AST *exp; } ret; /* <statement> ::= "return" <exp> */ 
    } type;
} Statement;


/* TODO document
 *
 */
typedef struct expression{
    union {
        struct conint { Token *con; } conint; /* <exp> ::= <int:Token> */
    } type;
} Expression;
#endif
