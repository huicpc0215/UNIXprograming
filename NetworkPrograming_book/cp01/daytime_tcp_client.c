/*=============================================================================
#     FileName: daytime_tcp_client.c
#         Desc: client for daytime
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: huicpc0215.uni.me
#      Version: 0.0.1
#   LastChange: 2015-06-08 23:13:36
#      History:
=============================================================================*/

#include"unp.h"

int main(int argc,char **argv){
    int sockfd, n;
    char recline[MAXLINE+1];
    struct sockaddr_in servaddr;

    if( argc !=2 )
        err_quit("usage: a.out <IPaddress>");
}
