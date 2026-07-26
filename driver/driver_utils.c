/* driver_utils.c :: TODO document
 *
 *
 * To Do ::
 *      To Implement :
 *          - parse_flags
 *
 *      To Test :
 *      
 *      To Update :
 *          - preprocess
 *
 *
 * Known Bugs :
 *
 */

/* inclustions from c standard */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* homemade inclustions */
#include "../util/boolean.h"
#include "driver_utils.h"
#include "flag_table.h"


int parse_flags(char *cmd, FlagLookupTable flags){
	return -1;
} /* TODO implement */



int preprocess(char *input_file, FlagLookupTable flags){ /* TODO figure out the required arguments */
    int ret;

    char *scmd = "gcc -E -P "; /* scmd : start of the command */
    char *mcmd = " -o "; /* mcmd : middle of the command */

    char *fcmd; /* fcmd : full command, should look like
                   gcc -E -P INPUT_FILE.c -o PREPROCESSED_FILE.i */


    ret = 0;
    fcmd = (char *) malloc( sizeof(char) * (strlen(scmd) + strlen(mcmd) + (2*( strlen(input_file) )) + 1) ); 
    
    /* BUILD fcmd */
    strcpy(fcmd, scmd); /* puts the start of the command into fcmd */
    strcat(fcmd, input_file); /* writes in the input file into fcmd*/
    strcat(fcmd, mcmd); /* writes the middle -o  into fcmd */
    strcat(fcmd, input_file);
    
    fcmd[strlen(fcmd) - 1] = 'i'; /* should make the filename of the output .i instead of .c */ /* TODO mabye 
                                                                                                make it so that
                                                                                               the input file has
                                                                                              no file ext at 
                                                                                             the end of it, so we
                                                                                            add theose ourselves */


    /* should call gcc -E -P INPUT_FILE.c -o PREPROCESSED_FILE.i */
    ret = system(fcmd); /* gives ret the exit number of the system call */ 
    /* TODO add flag support to the preprocess function */

    /* frees the allocated memory from fcmd */
    free(fcmd);
    fcmd = NULL;


    return ret;
} /* TODO immplement */





