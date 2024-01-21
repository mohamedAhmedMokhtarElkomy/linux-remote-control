#include <iostream>
#include<sys/socket.h>
#include <netdb.h> //getaddrinfo()
#include<string.h> //memset()
#include "command.h"


using namespace std;

#define PORT "5000"
#define BACKLOG 5
// #define BUFFER_SIZE 10
#define MSG_SOCK_FAILED     "ERROR: failed to start socket "
#define MSG_BIND_FAILED     "ERROR: failed to bind socket "
#define MSG_LISTEN_FAILED   "Error: failed to listen socket "
#define MSG_ACCEPT_FAILED   "Error: failed to accept socket "
#define MSG_RECEIVED_FAILED "Error: failed to receive socket "


int main(){
    
    Command cmd = Command();
    std::cout << cmd.execute("ls") << std::endl;   

    return 0;
}

// int main(){

// /*******************************************************************************
//  *                             Socket server steps                             *
//  *******************************************************************************/
// /*
//     SOCKET()
//     BIND()
//     LISTEN()
//     ACCEPT()
//     READ_WRITE_DATA()
//     CLOSE()
// */

// /*******************************************************************************
//  *                            define local variables                           *
//  *******************************************************************************/
//     struct addrinfo hints, *res;
//     struct sockaddr_storage storage_addr;
//     socklen_t addr_size;
    
//     int sockfd = 0, clientfd = 0; /* socket and client file descriptor */
//     int msg_len = BUFFER_SIZE;
//     int receive_result = 0;
//     char msg[BUFFER_SIZE];
    
    
    
//     addr_size = sizeof storage_addr;

//     memset(&hints, 0, sizeof hints);
//     hints.ai_family = AF_UNSPEC;        // use IPv4 or IPv6, whichever
//     hints.ai_socktype = SOCK_STREAM;
//     hints.ai_flags = AI_PASSIVE;        // fill in my IP for me by taking host ip address

//     getaddrinfo(NULL, PORT, &hints, &res);
//     /****************************************
//      * "domain" is PF_INET or PF_INET6,
//      * "type" is SOCK_STREAM or SOCK_DGRAM,
//      * "protocol" can be set to 0 to choose the proper protocol for the given type. Or you can call getprotobyname() to look up the protocol you want, “tcp” or “udp”.)
//      ****************************************/        
//     sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

//     if(sockfd == -1){
//         perror(MSG_SOCK_FAILED);
//         exit(errno);
//     }
//     /****************************************
//      * "sockfd" is the socket file descriptor returned by socket()
//      * "my_addr" is a pointer to a struct sockaddr that contains information about your address, namely, port and IP address
//      * "addrlen" is the length in bytes of that address
//      ****************************************/ 
//     if( bind(sockfd, res->ai_addr, res->ai_addrlen) == -1){
//         perror(MSG_BIND_FAILED);
//         shutdown(sockfd, SHUT_RDWR);
//         exit(errno);
//     }

//     /****************************************
//      * "sockfd" is the socket file descriptor returned by socket()
//      * "backlog" is the number of connections allowed on the incoming queue
//      ****************************************/
//     if( listen(sockfd, BACKLOG) == -1){
//         perror(MSG_LISTEN_FAILED);
//         shutdown(sockfd, SHUT_RDWR);
//         exit(errno);

//     }

    
//     clientfd = accept(sockfd, (struct sockaddr *)&storage_addr, &addr_size);

//     if(clientfd == -1){
//         perror(MSG_ACCEPT_FAILED);
//         shutdown(sockfd, SHUT_RDWR);
//         exit(errno);
//     }

    
//     char *msgg = "hello there!";
//     int len, bytes_sent;
//     len = strlen(msgg);
//     bytes_sent = send(clientfd, msgg, len, 0);

//     /****************************************
//      * "sockfd" is the socket file descriptor returned by socket()
//      * "buf" is the buffer to read the information into
//      * "len" is the maximum length of the buffer
//      * "flags" can again be set to 0
//      ****************************************/
//     do{
//         receive_result = recv(clientfd, msg, msg_len, 0);        
//         if(receive_result == -1){
//             perror(MSG_RECEIVED_FAILED);
//             shutdown(sockfd, SHUT_RDWR);
//             exit(errno);
//         }else if (receive_result == 0){
//             cout << "user closed the session" << endl;
//             shutdown(sockfd, SHUT_RDWR);
//             exit(0);
//         }else{
//             cout << msg << endl;
//         }
//     }while(1);
//     return 0;
// }