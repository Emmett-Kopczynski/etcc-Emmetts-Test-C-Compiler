/* etcc_driver c file :: a main file for running The Compiler Driver for the etcc compiler
 *
 * What a Compiler Driver Does :: A compiler driver does  quite a few things, it parses command line operations that are passed to the compiler, 
 * it runs the preprocessor, it runs the compiler itself, it assembles the assembly file, and then it runs the linker
 * 
 * 
 * To Do :
 * - Implement the running of the etcc compiler
 *  
 */

/* symbolic constants */
#define BUFFERLEN 10000

/* inclusions from c standard */
#include <stdio.h>
#include <string.h>

/* homemade inclusions */
#include "../util/boolean.h"
#include "driver_utils.h"
#include "flag_table.h"
#include "../compiler/compiler.h" /* the compiler */

int main(int argc, char *argv[]){
    
    /* builds the cmd */
    char cmd[BUFFERLEN];
    int i;
    i = 0;
    for(i = 0; i < argc; i ++){
        strcat(cmd, argv[i]);
        strcat(cmd, " ");
        
    }

    /* declare and construct the flag lookup table */
    FlagLookupTable flagtable;
    FlagLookupTable_construct_new(&flagtable);

    /* put the used flags in the flag lookup table */
    if( parse_flags(cmd, &flagtable) != 0)
        return 1;

    /* find the source file */
    char source[strlen(cmd)];
    if(get_source(cmd, source) != 0)
        return 1;
    

    /* call the preprocessor */
    if( preprocess(source, flagtable) != 0)
        return 1;

    /* STOP AFTER PREPROCESSOR IF -P is active */
    if(flagtable.contains(&flagtable, P))
        return 0;

    /* call the compiler */
    // TODO implement the compiler */
    
    /* deletes the preprocessed file */
    /* TODO delete the .i file */
        
    
    if(flagtable.contains(&flagtable, S) == False){
        /* link and assemble */
        // TODO implement the gcc assembler/linker
    
        /* TODO delete the assembly file */
    }

    return 0;   
}

