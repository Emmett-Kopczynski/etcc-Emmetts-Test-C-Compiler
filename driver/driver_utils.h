#ifndef DRIVER_UTILS_H_
#define DRIVER_UTILS_H_
/* driver_utils.h :: the header file for the driver_utils.c
 * file, this file contains function headers and detailed docs
 * on all functions in the driver_utils.c file
 *
 * To Document : 
 *      - parse_flags
 *
 */

/* inclusions from c standart */
#include <stdio.h>

/* homemade inclusions */
#include "../util/boolean.h"
#include "flag_table.h"



/* TODO document the parse_flags function
 *
 * NOTE : function takes a boolean array of size FLAGSNUM, with different numbers associated with different flags
 *
 */
int parse_flags(char *cmd, FlagLookupTable flags); 


/* preprocess :: runs the gcc preprocessor on our input file (the .c file)
 *
 * Arguments :
 *      - input_file : type char * : the .c file we are preprocessing
 *      - flags : type FlagLookupTable : the lookup table of cmd line flags 
 *
 * Returns : 0 if nothing went wrong, otherwise the error code for the gcc command
 *
 */
int preprocess(char *input_file, FlagLookupTable flags); /* TODO figure out the required arguments */




#endif
