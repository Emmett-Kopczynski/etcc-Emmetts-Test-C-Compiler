#ifndef FLAG_TABLE_H_
#define FLAG_TABLE_H_
/* flag_table.h :: The header file for the FlagLookupTable data structure, the Flags enum, and the associated
 * utility functions
 *
 * To Do : 
 *
 *      To Document :
 *          - FlagLookupTable_construct_new
 *          - detect_flag
 *
 */

/* homemade inclusions */
#include "../util/boolean.h"

/* symbolic constants */
#define FLAGNUM 5 /* the amount of command line flags */


/* Flags : symbolic representations of the flags one might input when using command line arguments
 * The amount of elements in this enum should ALWAYS be equal to the FLAGNUM symbolic constant
 *
 * NOTE :: See the docs for information on what each flag does
 */
typedef enum {
    ERR = 0, /* Error code, Not A Flag */
    S , /* -s */
    LEX, /* --lex */
    PARSE, /* --parse */
    CODEGEN /* --codegen */
} Flags;


/* FlagLookupTable :  A lookup table for the command line flags
 *
 * Variables :
 *      - flaglist : type boolean [] : a list of booleans indicating whether a certain 
 *      flag has been turned on or off
 *
 * Function Pointers : 
 *      - contains : returns boolean : returns True if the given flag is marked as on in the table, and False if it is not
 *      - put : returns boolean : marks the given flag as on in the table, if it was already on, returns False, otherwise returns True
 *
 */
typedef struct flaglookuptable {
    
    boolean flaglist[FLAGNUM]; 

    boolean (*contains)(struct flaglookuptable *, Flags);

    boolean (*put)(struct flaglookuptable *, Flags);
    
} FlagLookupTable;


/* FlagLookupTable_construct_new :  TODO document
 *
 */
void FlagLookupTable_construct_new(FlagLookupTable *flagtable);

/* FlagLookupTable_contains : 
 *
 * Arguments : 
 *      - flagtable : type FlagLookupTable * : the flagtable we are searching in
 *      - flag : type Flags : the flag we are searching for in the table
 *
 * Returns : 
 *      - True if it was in the table, False if it was not
 */
boolean FlagLookupTable_contains(FlagLookupTable *flagtable, Flags flag);

/* FlagLookupTable_put : puts the given flag in the table
 *
 * Arguments : 
 *      - flagtable : type FlagLookupTable * : the flag lookup table we are putting a flag in
 *      - flag : type Flags : the flag we are marking as on in the table
 *
 * Returns :
 *      - if the flag was already in the table, returns False, otherwise it returns True
 */
boolean FlagLookupTable_put(FlagLookupTable *flagtable, Flags flag);

/* TODO document 
 *
 */
Flags detect_flag(char *flag);

#endif
