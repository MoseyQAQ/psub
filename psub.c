//
// Created by m0sey on 4/21/22.
//
#include "psub.h"

#define UNIXSTR_PATH "/tmp/psub.srt"
#define LISTENQ 5
#define  haha "printf(\"test\n\");"
int main(int argc, char **argv)
{
    char *path,*name,*script;
    size_t len;
    path=(char *) malloc(BUFFER_SIZE);
    name=(char *) malloc(BUFFER_SIZE);
    getDir(path);
    if(argc == 2)
        name = getDirName(path,name);
    else if(argc == 3){
        len = sizeof(argv[2]);
        name = (char *) malloc(len);
        memcpy(name,argv[2],len);
    }
    else{
        printf("Error usage!\n");
        exit(-1);
    }
    len = sizeof (argv[1]);
    script = (char *) malloc(len);
    memcpy(script,argv[1],len);
    if(exists(script) == 0){
        printf("Script doesn't exist.\n");
        exit(-1);
    }
    return 0;
}
