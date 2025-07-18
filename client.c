#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

#define SERVER_PORT 8080
#define CLIENT_BUFFER 1024

int main(void)
{
    int client_fd;
    struct sockaddr_in server_addr;
    char *hello = "Hello from client";
    char buffer[CLIENT_BUFFER] = {0};

    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        printf("\n Socket creation error \n");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0)
    {
        printf("\nInvalid address/Address is not supported\n");
        exit(EXIT_FAILURE);
    }

    if (connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("\nConnection failed\n");
        exit(EXIT_FAILURE);
    }

    send(client_fd, hello, strlen(hello), 0);
    printf("\nHello message sent\n");
    read(client_fd, buffer, CLIENT_BUFFER);
    printf("%s", buffer);

    close(client_fd);

    return 0;
}
