#include "./fig8.5.c"

int
main(void){
    pid_t pid;
    int status;
    if( (pid = fork()) < 0)
        err_sys("fork error");
    else if( pid == 0)       /*   child*/
        exit(7);                /*ternimate normal*/

    if( wait(&status) != pid )
        err_sys("wait error");
    pr_exit(status);

    if( (pid=fork()) < 0 )
        err_sys("fork error");
    else if( pid == 0 )         /*ternimate abnormal*/
        abort();

    if( wait(&status) != pid)
        err_sys("wait error");
    pr_exit(status);

    if( (pid=fork()) < 0)
        err_sys("fork error");
    else if( pid == 0)
        status /= 0;            /*ternimate devied zero*/

    if( wait(&status) != pid)
        err_sys("wait error");
    pr_exit(status);
    exit(0);
}
