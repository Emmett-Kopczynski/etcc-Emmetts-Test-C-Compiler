/* flag_table.c :: The .c file for the FlagLookupTable, see header file for the associated data structure and enum
 * the functions to work with and construct the FlagLookupTable are implemented here
 * 
 * To Do :
 *      To Implement :
 *
 *      To Test :
 *          - FlagLookupTable_construct_new
 *          - FlagLookupTable_contains
 *          - FlagLookupTable_put 
 *
 *      To Update : 
 *
 * Known Bugs :
 *
 */

/* homemeade indclusions */
#include "flag_table.h"
#include "../util/boolean.h"


void FlagLookupTable_construct_new(FlagLookupTable *flagtable){
    int i;
    /* sets all elements in the flaglist to false */
    for(i = 0; i < FLAGNUM; i++){
        flagtable->flaglist[i] = False;
    }

    flagtable->contains = FlagLookupTable_contains;
    flagtable->put = FlagLookupTable_put;

    return;
} 



boolean FlagLookupTable_contains(FlagLookupTable *flagtable, Flags flag){
    if(flagtable->flaglist[flag] == True){
        return True;
    } else{
        return False;
    }
} 



boolean FlagLookupTable_put(FlagLookupTable *flagtable, Flags flag){
    if(flagtable->flaglist[flag] == False){
        flagtable->flaglist[flag] = True;
        return True; /* becuase it wasn't there yet */
    } else{
        return False; /* because it was already True */
    }
} 






