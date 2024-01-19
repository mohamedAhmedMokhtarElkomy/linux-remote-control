// #include<stdio.h>
#include <iostream>
#include<sys/socket.h>
#include <netdb.h> //getaddrinfo()
#include<string.h> //memset()
#include <errno.h>



using namespace std;

#define PORT "5001"
#define BACKLOG 5

int main(){

/*******************************************************************************
 *                             Socket server steps                             *
 *******************************************************************************/
/*
    SOCKET()
    BIND()
    LISTEN()
    ACCEPT()
    READ_WRITE_DATA()
    CLOSE()
*/




/*******************************************************************************
 *                            define local variables                           *
 *******************************************************************************/
    /* sockfd => socket file descriptor */
    int sockfd = 0, clientfd; 
    char msg[10];
    int msg_len;    
    struct addrinfo hints, *res;
    struct sockaddr_storage storage_addr;
    socklen_t addr_size;
    



    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;        // use IPv4 or IPv6, whichever
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;        // fill in my IP for me by taking host ip address

    getaddrinfo(NULL, PORT, &hints, &res);
    
    /****************************************
     * "domain" is PF_INET or PF_INET6,
     * "type" is SOCK_STREAM or SOCK_DGRAM,
     * "protocol" can be set to 0 to choose the proper protocol for the given type. Or you can call getprotobyname() to look up the protocol you want, “tcp” or “udp”.)
     ****************************************/ 
    cout << "socket()" << endl;   
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    if(sockfd == -1){
        cout << "Error: failed to start socket" << endl;
        return 0;
    }

    /****************************************
     * "sockfd" is the socket file descriptor returned by socket()
     * "my_addr" is a pointer to a struct sockaddr that contains information about your address, namely, port and IP address
     * "addrlen" is the length in bytes of that address
     ****************************************/ 
    cout << "bind()" << endl;
    if( bind(sockfd, res->ai_addr, res->ai_addrlen) == -1){
        cout << errno << endl;
        cout << "Error: failed to bind socket" << endl;
        return 0;
    }

    /****************************************
     * "sockfd" is the socket file descriptor returned by socket()
     * "backlog" is the number of connections allowed on the incoming queue
     ****************************************/
    cout << "listen()" << endl;
    if( listen(sockfd, BACKLOG) == -1){
        cout << "Error: failed to listen" << endl;
        shutdown(sockfd, SHUT_RDWR);
        return 0;
    }

    cout << "accept()" << endl;
    addr_size = sizeof storage_addr;
    clientfd = accept(sockfd, (struct sockaddr *)&storage_addr, &addr_size);

    if(clientfd == -1){
        cout << "Error: failed to accept" << endl;
        shutdown(sockfd, SHUT_RDWR);
        return 0;
    }

    cout << "send()" << endl;
    char *msgg = "hello there!";
    int len, bytes_sent;
    len = strlen(msgg);
    bytes_sent = send(clientfd, msgg, len, 0);

    /****************************************
     * "sockfd" is the socket file descriptor returned by socket()
     * "buf" is the buffer to read the information into
     * "len" is the maximum length of the buffer
     * "flags" can again be set to 0
     ****************************************/

    cout << "receive()" << endl;
    msg_len = 10;
    int receive_result = recv(clientfd, msg, msg_len, 0);
    cout << receive_result << endl;
    cout << errno << endl;
    // while(receive_result > 0){
    //     cout << "while()" << endl;
    //     receive_result = recv(clientfd, msg, msg_len, 0);

    //     // if(receive_result == -1){
    //     //     cout << "Error: failed to receive" << endl;
    //     //     cout << errno << endl;
    //     //     shutdown(sockfd, SHUT_RDWR);
    //     //     return 0;
    //     // }
    // }
    cout << msg << endl;
    cout << "END OF CODE" << endl;
    cout << errno << endl;


    shutdown(sockfd, SHUT_RDWR); 

    return 0;
}