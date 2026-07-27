/* flag_table.c :: The .c file for the FlagLookupTable, see header file for the associated data structure and enum
 * the functions to work with and construct the FlagLookupTable are implemented here
 * 
 * To Do :
 *      To Implement :
 *
 *      To Test :
 *
 *      To Update : 
 *
 * Known Bugs :
 *
 */

/* c standard inclusions */
#include <string.h>

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



Flags detect_flag(char *flag){
    if(strcmp(flag, "-S") == 0){
        return S;
    } else if (strcmp(flag, "--lex") == 0){
        return LEX;
    } else if(strcmp(flag, "--parse") == 0){
        return PARSE;
    } else if(strcmp(flag, "--codegen") == 0){
        return CODEGEN;
    } else if(strcmp(flag, "-P") == 0){
        return P;
    }else{
        return ERR;
    }
}



