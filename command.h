#ifndef CMD_H
#define CMD_H

#include<stdio.h>
#include<iostream>
#include<string.h> //memset()

#define BUFFER_SIZE 100

class Command{
private:
    FILE *stream;
    char buffer[BUFFER_SIZE];
    int status; //TODO may remove the status
public:
    Command();
    char* execute(const char *command);
    ~Command();
};


#endif