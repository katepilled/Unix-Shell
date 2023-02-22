#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libgen.h>
#include <string.h>
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
 * @brief makes user inputted command into a format that is like argv
 * 
 * @param command user input, prompted by shell prompt
 * @return char** argv, newly formatted command
 */
char ** formatCommand(char *command){
  //tokenize by white space char
  char *temp = strtok(command, " ");
  char **argv = malloc(strlen(command)* sizeof(char *));

  //get user command formatted as argv
  int i = 0;
  while (temp != NULL){
      argv[i] = (char *) malloc(strlen(temp) + 1);
      strcpy(argv[i], temp);
      temp = strtok(NULL, command);
      i++;
  }
  return argv;
}

//NOTE: FREE THE THINGS!!
