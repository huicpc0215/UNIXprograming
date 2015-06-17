#include "../lib/apue.h"

int globvar = 6;

int
main(void){
    int var;
    pid_t pid;
    var = 88;
    printf("before vfork\n");
    if( ( pid = vfork() ) < 0 ){
        err_sys("vfork error");
    }
    else if( pid == 0 ){           /* child*/
        printf("in child\n");
        globvar ++ ;
        var ++;
        exit(0);
    }
    /*parent process */
    printf("pid = %ld , glob=%d , var = %d child pid=%ld\n",(long)getpid(),globvar,var,(long)pid);
    exit(0);
}
