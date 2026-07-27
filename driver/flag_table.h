#ifndef FLAG_TABLE_H_
#define FLAG_TABLE_H_
/* flag_table.h :: The header file for the FlagLookupTable data structure, the Flags enum, and the associated
 * utility functions
 *
 * To Do : 
 *
 *      To Document :
 *
 */

/* homemade inclusions */
#include "../util/boolean.h"

/* symbolic constants */
#define FLAGNUM 6 /* the amount of command line flags */


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
    CODEGEN, /* --codegen */
    P /* -P */
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


/* FlagLookupTable_construct_new : constructs the given FlagLookupTable with 
 * FlagLookupTable_put in the put pointer, FlagLookupTable_contains in the contain pointer, and
 * it makes all elements of the flaglist variable equal false
 *
 * Arguments : 
 *      - flagtable : type FlagLookupTable * : the FlagLookupTable we are constructing
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


/* detect_flag : given the flag, this function returns the symbolic enum representation 
 * of that flag, used in the process of parsing the command line arguments
 *
 * Arguments :
 *      - flag : type char * : the given flag from the command line
 *
 * Returns : 
 *      - the symbolic representation of the flag as a Flags enum, returning the 
 *      ERR flag if it is ureconized
 *
 */
Flags detect_flag(char *flag);


#endif
