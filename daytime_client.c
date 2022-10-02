#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main(){

    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_fd == -1){
        perror("socket");
        exit(1);
    }

    //assign ip, port
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(PORT);
    
    //connect
    int conn_fd = connect(sock_fd, (struct sockaddr *) &addr, sizeof(addr));
    if(conn_fd == -1){
        printf("Connection to server failed...\n");
        perror("connect");
        exit(1);
    }
    else printf("Connection to server successful...\n");

    //Daytime Code
    char buffer[100];
    
    read(sock_fd, buffer, sizeof(buffer));
    // write(sock_fd, buffer, sizeof(buffer));

    printf("Data recieved to client...\n\n");
    printf("Client Daytime from recieved data = %s\n", buffer);
    //Daytime Code

    close(sock_fd);

    return 0;
}
