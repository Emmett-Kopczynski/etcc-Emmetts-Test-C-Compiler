/* etcc_driver c file :: a main file for running The Compiler Driver for the etcc compiler
 *
 * What a Compiler Driver Does :: A compiler driver does  quite a few things, it parses command line operations that are passed to the compiler, 
 * it runs the preprocessor, it runs the compiler itself, it assembles the assembly file, and then it runs the linker
 * 
 * 
 * To Do :
 * - Implement the gcc preprocessor
 * - Implement the running of the etcc compiler
 * - implement the gcc assembler and linker
 * - implement a basic error messaging system for the compiler
 * 
 *  
 */

/* symbolic constants */


/* inclusions from c standard */
#include <stdio.h>
#include <string.h>

/* homemade inclusions */
#include "../util/boolean.h"
#include "driver_utils.h"
#include "flag_table.h"

/* Symbolic constants */

int main(int argc, char *argv[]){
    
    /* builds the cmd */
    char cmd[10000];
    int i;
    i = 0;
    for(i = 0; i < argc; i ++){
        strcat(cmd, argv[i]);
        strcat(cmd, " ");
        
    }

    /* declare and construct the flag lookup table */
    FlagLookupTable flags;
    FlagLookupTable_construct_new(&flags);

    /* put the used flags in the flag lookup table */
    if( parse_flags(cmd, &flags) != 0)
        return 1;

    /* find the source file */
    char source[strlen(cmd)];
    /* TODO make a find source function */
    
    

    return 0;   
}

