#ifndef CMD_H
#define CMD_H

#include<stdio.h>
#include<iostream>

#define BUFFER_SIZE 1000

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