#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <libgen.h>

#include "prompt.h"

/**
 * @brief Generate a shell prompt
 * 
 */
void createPrompt(){

    char cwd[1024];

    //get current working directory
    getcwd(cwd, sizeof(cwd));

    //print prompt
    printf("[nyush ");
    printf("%s", basename(cwd));
    printf("]$ ");
    fflush(stdout);

}


/**
 * @brief Checks is user inputted command is valid or not
 * 
 * @param char array , user inputted command
 * @return int; 1 if command is valid, 0 if invalid 
 */
//int validCommand(char *command){

  //  return 1;
//}

