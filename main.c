#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "prompt.h"
#include "locating.h"


/* SOURCES USED:
https://pubs.opengroup.org/onlinepubs/007904975/functions/getcwd.html
https://www.w3schools.com/c/c_user_input.php
https://stackoverflow.com/questions/22452314/how-to-get-the-current-working-directorycurrent-working-folder-name-instead-of
https://www.qnx.com/developers/docs/6.4.0/neutrino/lib_ref/g/getcwd.html
https://www.tutorialspoint.com/c_standard_library/string_h.htm
tutorialspoint.com/c_standard_library/c_function_strtok.htm

*/

//docker run -i --name cs202 --privileged --rm -t -v ~/Documents/cs202/labs:/cs202 -w /cs202 ytang/os bash
//cd OS-lab2-nyush
//gcc main.c prompt.c locating.c

int main(){
    char command[1001];
    char **argv = NULL; 

    while (1){

        createPrompt();
        
        //get user input/command
        fgets(command, 1001, stdin);
        argv = formatCommand(command);
        printf("%s", argv[1]);
    

        //ls function
        if (strcmp(argv[0], "ls\n") == 0 || strcmp(argv[0], "ls") == 0){
            ls(argv);
        }
    }
    return 0;
}
