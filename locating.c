#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <unistd.h>

#include "locating.h"

/**
 * @brief 
 * 
 */
void ls(char *command){

    pid_t pid;
    pid = fork();

    //fork fails
    if (pid < 0) {
        fprintf(stderr, "Error: Failed to fork\n"); 
        exit(0);
    
    // child (new process)
    } else if (pid == 0) {
        execv("/bin/ls", "", ...); 

        printf("execv() failed\n"); //exec failed


    } else {
        //wait for child process
        waitpid(-1, ...); 
  }
}




