//
// Created by m0sey on 4/20/22.
//

#include "psub.h"

#define UNIXSTR_PATH "/tmp/psub.srt"
#define LISTENQ 5

int listenfd,connfd;
socklen_t len;
struct sockaddr_un servaddr, cliaddr;
char *code_from_client;
char *localTime;
int job_count;

int socket_establish();
int listenClient();
int code_translator();
int scheduler();
int psubit(int id);

int main(int argc, char **argv)
{
    if(socket_establish() != 0){
        printf("Can not establish socket.\n");
        exit(-1);
    }

    while(1){
        listen(listenfd,LISTENQ);
        len = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr *) &cliaddr, &len);
        listenClient();
        scheduler();
    }
    return 0;
}

int socket_establish()
{
    listenfd = socket(AF_LOCAL, SOCK_STREAM, 0);
    unlink(UNIXSTR_PATH);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sun_family = AF_LOCAL;
    strcpy(servaddr.sun_path, UNIXSTR_PATH);
    bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    return 0;
}
int listenClient()
{
    while(1)
    {
        if(read(connfd,code_from_client, BUFFER_SIZE) == 0)
            break;
        else
            write(connfd,"Psub-server: Data written successfully.\n",BUFFER_SIZE);
        code_translator();
    }
}
int code_translator()
{

}