#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#include "locating.h"

/**
 * @brief 
 * 
 * @param argv 
 */
void run(char **argv){

    pid_t pid;
    int exitStatus; 

    //if user specifies basename 
    if (strchr(argv[0], '/') == NULL){
        char* path = "/usr/bin/";
        char* base = argv[0];
        char buffer[1001];

        //make argv[0] /user/bin/BASENAME
        strcpy(buffer, path); 
        strcat(buffer, base);  
        strcpy(argv[0], buffer); 
    } 

    pid = fork();

    // fork failed (this shouldn't happen)
    if (pid < 0) {
        fprintf(stderr, "Error: Failed to fork\n"); 
        fflush(stderr);
        exit(-1);
    } 
    // child (new process)
    else if (pid == 0) {
        execv(argv[0], argv); 
        fprintf(stderr, "Error: invalid program\n"); 
        fflush(stderr);
        exit(-1);
    }

    // parent
     else {
        waitpid(-1, &exitStatus, 0);
    }
}
