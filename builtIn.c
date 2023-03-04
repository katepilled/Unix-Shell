#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "builtIn.h"

/**
 * @brief 
 * 
 * @param argv user inputted command which specifies cd
 */
void changeDirectory(char **argv){
    //if there are no args
    if (argv[1] == NULL){
        fprintf(stderr, "Error: invalid command\n");
        fflush(stderr);
    }
    
    //if there are 2+ args
    else if (argv[2] != NULL){
        fprintf(stderr, "Error: invalid command\n");
        fflush(stderr);
    }

    //if chdir fails
    else if (chdir(argv[1]) == -1){
        fprintf(stderr, "Error: invalid directory\n");
        fflush(stderr);
    }
}

/**
 * @brief 
 * 0 = false 
 * 1 = true
 */
int exitCheck(char **argv){

    //if program accepts args
    if (argv[1] != NULL){
        fprintf(stderr, "Error: invalid command\n");
        fflush(stderr);
        return 1;
    }

    else{
        return 0;
    }
}
