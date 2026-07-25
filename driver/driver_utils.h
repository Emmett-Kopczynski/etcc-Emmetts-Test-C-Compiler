#ifndef DRIVER_UTILS_H_
#define DRIVER_UTILS_H_
/* driver_utils.h :: the header file for the driver_utils.c
 * file, this file contains function headers and detailed docs
 * on all functions in the driver_utils.c file
 *
 * To Document : 
 *
 */

/* inclusions from c standart */
#include <stdio.h>

/* homemade inclusions */
#include "../util/boolean.h"

/* Symbolic constants */
#define FLAGSNUM 4 /* The Amount of Possible Flags for the compiler driver */



/* FLAG STUFF START */ 
typedef enum{
    LEX = 0, PARSE, 
    CODEGEN, S   
} Flag;


/* FlagLookupTable :: 
 * TODO document
 *  Variables :
 *  - flags :: type boolean [] :: TODO document
 *
 *  Function Pointers :
 *  - cointains :: type boolean (*)(Flag) :: TODO document
 *  - put :: type void (*)(Flag) :: TODO document
 *
 */
typedef struct flag_lookup_table{
    boolean flags[FLAGSNUM];

    /* function pointers */
    boolean (*contains)(Flag);
    void (*put)(Flag);

} FlagLookupTable;

/* TODO document construct_flag_lookup_table
 *
 * NOTE :: purposefully build in a way to avoid malloc, so it works a little weird
 *
 * Mainly to set everything to false
 */
void construct_flag_lookup_table(FlagLookupTable flags); /* TODO check if this would even work */


/* TODO document the parse_flags function
 *
 * NOTE : function takes a boolean array of size FLAGSNUM, with different numbers associated with different flags
 *
 * The Flags Are As Follows (number is index in array) :
 * 0 -- { --lex }
 * 1 -- { --parse }
 * 2 -- { --codegen }
 * 3 -- { -S }
 */
int parse_flags(char *cmd, FlagLookupTable flags); /* TODO  figure out the required arguments */

/* TODO asses if a parse term helper function is required for parse_flags to work  */

/* FLAG STUFF END */





#endif
