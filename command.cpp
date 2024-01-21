#include "command.h"


Command::Command(){
    status = 0;
}
//TODO shall i add const
char* Command::execute(const char *command){
    memset(buffer, '\0', BUFFER_SIZE);
    stream = popen(command, "r");

    if(stream == NULL){
        status = -1;
        return "Failed to execute the command";
    }

    status = 0;

    fread(buffer, BUFFER_SIZE, 1, stream);

    return buffer;

}
Command::~Command(){
    pclose(stream);
}
