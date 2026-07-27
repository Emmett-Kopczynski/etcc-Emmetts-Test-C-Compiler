/* driver_utils.c :: TODO document
 *
 *
 * To Do ::
 *      To Implement :
 *
 *      To Test :
 *          - assemblink
 *          - get_source
 *  
 *      To Update :
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


int parse_flags(char *cmd, FlagLookupTable *flags){
	int i;
    i = 0;
    
    char buffer[strlen(cmd)]; /* buffer to store flags */
    boolean onflag = False;
    memset(buffer, 0, strlen(cmd));

    for(i = 0; i < strlen(cmd); i++){
        if(cmd[i] == '-' && onflag == False)
            onflag = True;
        else if (cmd[i] == ' ' && onflag == True){
            flags->put(flags, detect_flag(buffer));
            if(flags->contains(flags, ERR) ){
                fprintf(stderr, "ERROR :: Unknown Flag :: %s\n", buffer);
                return 1;
            }
            memset(buffer, 0, strlen(buffer));
            onflag = False;
        }

        if(onflag){
            buffer[strlen(buffer)] = cmd[i];
        }
    }
    


    return 0;
} 



int preprocess(char *input_file, FlagLookupTable flags){ 
    int ret;

    char *scmd = "gcc -E -P "; /* scmd : start of the command */
    char *mcmd = " -o "; /* mcmd : middle of the command */

    char *fcmd; /* fcmd : full command, should look like
                   gcc -E -P INPUT_FILE.c -o PREPROCESSED_FILE.i */


    ret = 0;
    fcmd = (char *) malloc( sizeof(char) * (strlen(scmd) + strlen(mcmd) + (2*( strlen(input_file) )) + 1) ); 
    
    /* BUILD fcmd */
    strcpy(fcmd, scmd); /* puts the start of the command into fcmd */
    strcat(fcmd, input_file); /* writes the input file into fcmd*/
    strcat(fcmd, mcmd); /* writes the middle -o  into fcmd */
    strcat(fcmd, input_file);
    
    fcmd[strlen(fcmd) - 1] = 'i'; /* should make the filename of the output .i instead of .c */ 

    /* should call gcc -E -P INPUT_FILE.c -o PREPROCESSED_FILE.i */
    ret = system(fcmd); /* gives ret the exit number of the system call */ 

    /* frees the allocated memory from fcmd */
    free(fcmd);
    fcmd = NULL;


    return ret;
}



int assemblink(char *input_file, FlagLookupTable flags){
    int ret;
    
    char *scmd = "gcc "; /* scmd : start of the command */
    char *mcmd = " -o "; /* mcmd : middle of the command */

    char *fcmd; /* fcmd : full command, should look like
                   gcc ASSEMBLY_FILE.s -o OUTPUT_FILE.o */

    ret = 0;
    fcmd = (char *) malloc( sizeof(char) * (strlen(scmd) + strlen(mcmd) + (2 * strlen(input_file) ) + 1 ) ) ;

    /* BUILD fcmd */
    strcpy(fcmd, scmd); /* puts the start of the command into fcmd */
    strcat(fcmd, input_file); /* writes the input file into fcmd */
    strcat(fcmd, mcmd); /* writes the middle -o into the fcmd */
    strcat(fcmd, input_file);

    fcmd[strlen(fcmd) - 1] = 'o';

    /* should call gcc ASSEMBLY_FILE.s -o OUTPUT_FILE.o */
    ret = system(fcmd); /* gives ret the exit number of the system call */

    /* frees the allocated memory from fcmd */
    free(fcmd);
    fcmd = NULL;

    return ret;
}



int get_source(char *cmd, char *source){
    int i, j;
    j = i = 0;

    char buffer[strlen(cmd)];
    memset(buffer, 0, strlen(cmd));

    boolean insource = False;

    for(i = strlen(cmd) - 1; i >= 0; i--){
        if (cmd[i] == '.' && cmd[i + 1] == 'c') {
            insource = True;
            buffer[strlen(buffer)] = 'c'; 
        } else if (i == 0) {
            fprintf(stderr, "ERROR :: No Input File Detected\n");
            return 1;
        } else if(cmd[i] == ' ' && insource == True){
            break;
        }


        if(insource == True){
            buffer[strlen(buffer)] = cmd[i];
        }
    }   

    /* puts the source from the buffer into the source variable */
    for(i = strlen(buffer) - 1; i >= 0; i --){
        source[j] = buffer[i];
        j ++;
    }
    
    source[j] = '\0';

    return 0;
} 









