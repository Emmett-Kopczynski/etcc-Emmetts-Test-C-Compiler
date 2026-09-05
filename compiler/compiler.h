#ifndef COMPILER_H_
#define COMPILER_H_
/* compiler.h : the .h file for the compiler function
 *
 * To Do : 
 *
 */


/* c standard inclusions */
#include <stdio.h>

/* homemade inclusions */
#include "../driver/flag_table.h"


/* compile : compiles the given preprocessed c file (*.i), this process might be modified
 * or incomplete depending on the contents of flags
 *
 * Arguments : 
 *      - sourcepath : type char * : the sourcepath to the .i preprocessed c file to be compiled
 *      - flags : type FlagLookupTable : the lookup table for the command line flags
 *
 * Returns :
 *      - 0 if everything went well, otherwise 1
 *
 */
int compile(char *sourcepath, FlagLookupTable flags);



#endif
