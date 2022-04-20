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
#define BUFFER_SIZE 256

#ifndef PSUB_PSUB_H
#define PSUB_PSUB_H

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
#endif //PSUB_PSUB_H
