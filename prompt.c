#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libgen.h>
#include <string.h>

#include "prompt.h"

/**
 * @brief creates shell prompt and accepts user input
 * 
 * @return char** argv, command entered by user for shell to execute
 */
char ** createPrompt(){

    char command[1001];
    char **argv = NULL;
    char cwd[1024];

    //get current working directory
    getcwd(cwd, sizeof(cwd));

    //print prompt
    printf("[nyush ");
    printf("%s", basename(cwd));
    printf("]$ ");
    fflush(stdout);

    //get user input/command
    fgets(command, sizeof(command), stdin);

    //remove terminating newline char
    command[strcspn(command, "\n")] = 0;

    //format to char**
    argv = formatCommand(command);
    return argv;    
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
      temp = strtok(NULL, " ");
      i++;
  }
  return argv;
}

//NOTE: FREE THE THINGS!!

