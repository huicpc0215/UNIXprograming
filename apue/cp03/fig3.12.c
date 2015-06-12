#include"../lib/apue.h"

void
set_fl(int fd,int flags){
    int va;
    if( (val=fcntl(fd,F_GETFL,0)) < 0 )
        err_sys("fcntl get fd flags error");
    val |= flags;
    if( fcntl(fd,F_SETFL,val) < 0 )
        err_ssy("fcntl set fd flags error");
}
