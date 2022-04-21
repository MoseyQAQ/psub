//
// Created by m0sey on 4/20/22.
//
/*
 * Define some functions:
 *    1. getDirName(char *PATH,char *dirName)
 *             return the dir's name;
 *    2. getDir(char *PATH)
 *             return the working dir;
 *    3. getTime(char *TimeString)
 *             return the current time; (not precise)
 */
#include "time.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "linux/limits.h"
#include "sys/types.h"
#include "sys/socket.h"
#include "sys/un.h"
#define BUFFER_SIZE 256

#ifndef PSUB_PSUB_H
#define PSUB_PSUB_H
typedef struct job_info{
    int ID;
    char *sub_time;
    char *start_time;
    char *end_time;
    char *user;
    char *path;
    char *name;
    char *script;
    char *status;
    struct job_info *next;
}job_info;
char *getDirName(char *dir,char *dirName)
{
    char *token;
    size_t length;
    token = strrchr(dir, '/');
    length = strlen(token);
    dirName = malloc(length);
    memcpy(dirName,token+1, length);
    return dirName;

}
char *getDir(char *path)
{
    getcwd(path,BUFFER_SIZE);
    return path;
}
char *getTime(char *timeString)
{
    time_t rawtime;
    timeString = ctime(&rawtime);
    timeString[strlen(timeString)-1] = '\0';
    return timeString;
}
int exists(char *name)
{
    FILE *open;
    open = fopen(name,"r");
    if(open == NULL)
        return 0;
    else{
        fclose(open);
        return 1;
    }
}
#endif //PSUB_PSUB_H
