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
scaler.com/topics/strcmp-in-c/
*/

//docker run -i --name cs202 --privileged --rm -t -v ~/Documents/cs202/labs:/cs202 -w /cs202 ytang/os bash
//gcc main.c prompt.c locating.c

int main(){
    char command[1001];

    while (1){

        createPrompt();
        
        //get user input/command
        fgets(command, 1001, stdin);
        
        //if (fgets(command, 1001, stdin) != NULL){
        //    printf("%c", command[0]);
        //}

        //if (validCommand(command) == 0){
        //    fprintf(stderr, "Error: invalid command\n");
        //}

        //write ls function
        printf(command);
        if (strcmp(command, "ls\n") == 0){
            ls(command);
        }
    }

    return 0;
}