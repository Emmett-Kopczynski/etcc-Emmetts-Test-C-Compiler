#ifndef AST_H_
#define AST_H_
/* ast.h : the header file for the definition of the
 * Abstract Syntax Tree primarily used by the parser module 
 * of the compiler
 *
 * To Do :
 *
 * Known Bugs :      
 *
 */

/* c inclusions */

/* homemade inclusions */
#include "../token.h"

/* foreward declarations for the nodes */
typedef struct program Program;
typedef struct function Function;
typedef struct statement Statement;
typedef struct expression Expression;

/* ASTag : the tag used in the AST data
 * structure to indicate the type of AST node
 *
 */
typedef enum {
    PROGRAM, /* signifies a Program node for the AST */
    FUNCTION, /* signifies a Function node for the AST */
    STATEMENT, /* signifies a Statement node for the AST */
    EXP /* signifies an Expression node for the AST */
} ASTag;


/* AST : an Abstract Syntax Tree used to represent a C program
 *
 * Variables :
 *      - node_type : type ASTag : signifies the type of node it is
 *      - node : type union : stores different node info based on the node type
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


/* Program : a Program node for an Abstract  Syntax Tree (AST) for the C programming language
 *
 * Variables :
 *      - type : type union : the node information for the Program node
 *
 */
typedef struct program{
    union {
        struct func { AST *func; } func; /* <program> ::= <function> */
    } type;
} Program; 


/* Function : a Function node for an Abstract Syntax Tree (AST) for the C programming language
 *
 * Variables :
 *      - type : type union : the node information for the Function node
 *
 */
typedef struct function{
    union {
        struct tempdef { Token *identifier; AST *stat; } tempdef; /* <function> ::= "int" <identifier:Token> "(" "void" ")" "{" <statement> "}" */ /* NOTE : not a permanant definition */
    } type;
} Function; 


/* Statement : a Statement ndoe for an Abstract Syntax Tree (AST) for the C programming language
 *
 * Variables :
 *      - type : type union : the node information for the Program node
 *
 */
typedef struct statement{
    union {
        struct ret { AST *exp; } ret; /* <statement> ::= "return" <exp> */ 
    } type;
} Statement;


/* Expression : an Expression node for an Abstract Syntax Tree (AST) for the C programming language
 *
 * Variables :
 *      - type : type union : the node information fo the Expression node
 *
 */
typedef struct expression{
    union {
        struct conint { Token *con; } conint; /* <exp> ::= <int:Token> */
    } type;
} Expression;


#endif
