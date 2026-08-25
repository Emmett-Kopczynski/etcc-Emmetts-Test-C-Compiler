#ifndef AST_H_
#define AST_H_
/* ast.h : TODO document 
 *
 * To Do :
 *      
 *      To Document :
 *          - ASTag
 *          - AST
 *          - Program
 *      
 *      To Implement :
 *          - AST
 */

/* c inclusions */

/* homemade inclusions */


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
    
    } node;

} AST;


#endif
