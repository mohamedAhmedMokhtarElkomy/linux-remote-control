#include<stdio.h>
#include<iostream>
// #include<string>

#define BUFFER_SIZE 1000

class Command{
private:
    FILE *stream;
    char buffer[BUFFER_SIZE];
    int status; //TODO may remove the status
public:
    Command(){
        status = 0;
    }
    //TODO shall i add const
    char* execute(const char *command){
        stream = popen(command, "r");

    if(stream == NULL){
        status = -1;
        return "Failed to execute the command";
    }
    
    status = 0;

    fread(buffer, BUFFER_SIZE, 1, stream);
    
    return buffer;
    
    }
    ~Command(){
        pclose(stream);
    }
};


int main(){
    
    Command* cmd = new Command();

    std::cout << cmd->execute("ls") << std::endl;

    delete cmd;    

    return 0;
}