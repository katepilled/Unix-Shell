#include <ctype.h>
#include<stdio.h>
#include <string.h>

/* SOURCES USED:
https://pubs.opengroup.org/onlinepubs/007904975/functions/getcwd.html
https://www.w3schools.com/c/c_user_input.php
//https://www.cyberciti.biz/tips/howto-linux-unix-bash-shell-setup-prompt.html
*/

//docker run -i --name cs202 --privileged --rm -t -v ~/Documents/cs202/labs:/cs202 -w /cs202 ytang/os bash

int main(){
    char command[1000]; 
    char cwd[1024];
    getcwd(cwd, 1024);

    while (1){
        printf("[nyush ");
        printf(cwd);
        printf("]$ ");
        fflush(stdout);
        scanf("%s", command);
    }

    return 0;
}