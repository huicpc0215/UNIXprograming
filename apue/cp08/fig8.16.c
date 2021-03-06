#include "../lib/apue.h"

char * env_init[]={"UNSER=unknown","PATH=/tmp",NULL};

int
main(void){
    pid_t  pid;
    if( (pid=fork()) < 0 )
        err_sys("fork error");
    else if( pid == 0 ){
        if( execle("./echoall","echoall","myarg1","MY arg2",(char*)0,env_init)  < 0)
            err_sys("execle error");
    }
    if( waitpid(pid,NULL,0) < 0 )
        err_sys("wait error");
    else if( pid == 0 ){
        if( execlp("echoall","echoall","only 1 arg",(char *)0 ) < 0 )
            err_sys("execlp error");
    }
    exit(0);
}

