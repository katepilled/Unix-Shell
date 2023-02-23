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
 * @param argv 
 */
void ls(char **argv){

    pid_t pid;
    int exitStatus; 
    argv[0] = "/bin/ls";
    
    pid = fork();

    // fork failed (this shouldn't happen)
    if (pid < 0) {
        fprintf(stderr, "Error: Failed to fork\n"); 
        exit(-1);
    } 
    // child (new process)
    else if (pid == 0) {
        execv(argv[0], argv); 
        fprintf(stderr, "Error: Invalid Program\n"); 
        exit(-1);
    
    // parent
    } else {
        waitpid(-1, &exitStatus, 0);
    }
}

