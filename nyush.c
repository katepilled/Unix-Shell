#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "prompt.h"
#include "locating.h"
#include "builtIn.h"


/* SOURCES USED:
https://pubs.opengroup.org/onlinepubs/007904975/functions/getcwd.html
https://www.w3schools.com/c/c_user_input.php
https://stackoverflow.com/questions/22452314/how-to-get-the-current-working-directorycurrent-working-folder-name-instead-of
https://www.qnx.com/developers/docs/6.4.0/neutrino/lib_ref/g/getcwd.html
https://www.tutorialspoint.com/c_standard_library/string_h.htm
https://stackoverflow.com/questions/2693776/removing-trailing-newline-character-from-fgets-input
*/

//docker run -i --name cs202 --privileged --rm -t -v ~/Documents/cs202/labs:/cs202 -w /cs202 ytang/os bash
//gcc nyush.c prompt.c locating.c builtIn.c

int main(){
    char **argv = NULL; 

    while (1){

        argv = createPrompt();

        if (argv == NULL){
            continue;
        }

        //cd function
        else if (strcmp(argv[0], "cd") == 0){
            changeDirectory(argv);
        }
        
        else if (strcmp(argv[0], "exit") == 0){
            if (exitCheck(argv) == 0){
                exit(0);
            }
        }

        else {
            run(argv);
        } 

    }
    return 0;
}

