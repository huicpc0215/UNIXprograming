#include "../lib/apue.h"

int
main(void){
    pid_t pid;
    if( (pid=fork())<0 )
        err_sys("fork error");
    else if( pid != 0 ){        /*parent*/
        sleep(2);
        exit(2);
    }

    if( (pid = fork()) < 0 )
        err_sys("fork error");
    else if( pid != 0  ){       /*first child*/
        sleep(4);
        abort();
    }

    if( (pid=fork()) < 0 )
        err_sys("fork error");
    else if( pid != 0 ){        /*second child*/
        execl("/bin/dd","dd","if=/etc/passwd","of=/dev/null",(char*)0);
        exit(7);
    }

    if( (pid=fork()) < 0 )
        err_sys("fork error");
    else if( pid != 0 ){        /*third child*/
        sleep(8);
        exit(0);
    }

    /*fourth child*/
    sleep(6);
    kill(getpid(),SIGKILL);
    exit(6);
}
