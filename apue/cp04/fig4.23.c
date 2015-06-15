#include"../lib/apue.h"
char buf[2000];
#define BUFFSIZE 2000
int
main(void){
    printf("cwd=%s\n",getcwd(buf,BUFFSIZE));
    if( chdir("/tmp") < 0 )
        err_sys("chdir failed");
    printf("cwd=%s\n",getcwd(buf,BUFFSIZE));
    printf("chdir to /tmp succeeded\n");
    exit(0);
}

