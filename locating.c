#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <unistd.h>
#include <string.h>

#include "locating.h"

/**
 * @brief 
 * 
 */
void ls(char **argv){
    pid_t pid;
    int exitStatus; 
    
    pid = fork();

    // fork failed (this shouldn't happen)
    if (pid < 0) {
        fprintf(stderr, "Error: Failed to fork\n"); 
        exit(0);
    } 
    // child (new process)
    else if (pid == 0) {
        execv("/bin/ls", argv); 
        fprintf(stderr, "Error: Invalid Program\n"); 
    
    // parent
    } else {
        waitpid(-1, &exitStatus ,0);
    }
}

