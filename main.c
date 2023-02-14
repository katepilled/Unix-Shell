#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "prompt.h"


/* SOURCES USED:
https://pubs.opengroup.org/onlinepubs/007904975/functions/getcwd.html
https://www.w3schools.com/c/c_user_input.php
//https://www.cyberciti.biz/tips/howto-linux-unix-bash-shell-setup-prompt.html
https://stackoverflow.com/questions/22452314/how-to-get-the-current-working-directorycurrent-working-folder-name-instead-of
https://www.qnx.com/developers/docs/6.4.0/neutrino/lib_ref/g/getcwd.html
*/

//docker run -i --name cs202 --privileged --rm -t -v ~/Documents/cs202/labs:/cs202 -w /cs202 ytang/os bash

int main(){
    while (1){
        createPrompt();
    }

    return 0;
}