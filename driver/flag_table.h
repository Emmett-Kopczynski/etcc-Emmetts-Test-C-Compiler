#ifndef FLAG_TABLE_H_
#define FLAG_TABLE_H_
/* flag_table.h :: The header file for the FlagLookupTable data structure, the Flags enum, and the associated
 * utility functions
 *
 * To Do : 
 *
 *      To Document :
 *          - FlagLookupTable
 *          - contains
 *          - puts
 *          - FlagLookupTable_construct_new
 *          - FlagLookupTable_contains
 *          - FlagLookupTable_put
 */

/* homemade inclusions */
#include "../util/boolean.h"

/* symbolic constants */
#define FLAGNUM 4 /* the amount of command line flags */


/* Flags : symbolic representations of the flags one might input when using command line arguments
 * The amount of elements in this enum should ALWAYS be equal to the FLAGNUM symbolic constant
 *
 * NOTE :: See the docs for information on what each flag does
 */
typedef enum {
    S = 0, /* -s */
    LEX, /* --lex */
    PARSE, /* --parse */
    CODEGEN /* --codegen */
} Flags;


/* FlagLookupTable :  TODO document
 *
 */
typedef struct flaglookuptable {
    
    boolean flaglist[FLAGNUM]; 

    /* TODO document */
    boolean (*contains)(struct flaglookuptable *, Flags);

    /* TODO document */
    boolean (*put)(struct flaglookuptable *, Flags);
    
} FlagLookupTable;

/* TODO document
 *
 */
void FlagLookupTable_construct_new(FlagLookupTable *flagtable);

/*  TODO document
 *
 */
boolean FlagLookupTable_contains(FlagLookupTable *flagtable, Flags flag);

/* TODO document
 *
 */
boolean FlagLookupTable_put(FlagLookupTable *flagtable, Flags flag);



#endif
