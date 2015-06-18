#include "../lib/apue.h"
int
main(void){
    pid_t pid;
    if( (pid=fork())<0 )
        err_sys("fork error");
    else if( pid == 0 ){
        if( execl("./testinterp","testinterp","myarg1","My arg2",(char *)0 ) < 0 )
            err_sys("waitpid error");
    }
    exit(0);
}
