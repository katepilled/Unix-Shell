#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <libgen.h>

#include "prompt.h"

void createPrompt(){

    char command[1001]; 

    //get current working directory
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    char * cwd_basename = basename(cwd);


    printf("[nyush ");
    printf("%s", cwd_basename);
    printf("]$ ");
    fflush(stdout);
    scanf("%s", command);

}
