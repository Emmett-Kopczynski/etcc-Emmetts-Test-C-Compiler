/* etcc_driver c file :: a main file for running The Compiler Driver for the etcc compiler
 *
 * What a Compiler Driver Does :: A compiler driver does  quite a few things, it parses command line operations that are passed to the compiler, 
 * it runs the preprocessor, it runs the compiler itself, it assembles the assembly file, and then it runs the linker
 * 
 * 
 * To Do :
 * - Implement a system to find what flags are being used, make the system highly scaleable, likely done in a different source file
 * - Implement the gcc preprocessor
 * - Implement the running of the etcc compiler
 * - implement the gcc assembler and linker
 * - implement a basic error messaging system for the compiler
 * 
 *
 */

/* inclusions from c standard */
#include <stdio.h>


/* homemade inclusions */
#include "../util/boolean.h"

/* definitions */
#define FLAGSNUM 0 /* The Amount of Possible Flags for the compiler driver */


int main(int argc, char *argv[]){
    
    if(True){
        printf("True Works!\n");
    } else{
        printf("Truth Fails\n");
    }

    return 0;   
}

