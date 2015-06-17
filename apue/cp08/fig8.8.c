#include"../lib/apue.h"
int
main(void){
    pid_t pid;
    if( (pid=fork()) < 0 )
        err_sys("fork error");
    else if( pid == 0 ){        /*first child*/
        if( (pid=fork() ) < 0)
            err_sys("fork error");
        else if( pid > 0 )
            exit(0);            /*second process's parent == first child*/

        /*now is second child*/
        /*our parent becomes init as soon as real parent calls exit(0)*/
        sleep(5);
        printf("second child, parent pid = %ld\n",(long)getppid());
        exit(0);
    }

    if( waitpid(pid,NULL,0)!=pid ) /*wait for first child*/
        err_sys("waitpid error");
    printf("first child ends\n");

    exit(0);
}
