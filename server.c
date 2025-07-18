#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <stdbool.h>

#define SERVER_PORT 8080
#define SERVER_PENDING_CONNECTION 10
#define SERVER_BUFFER 30000
#define FILE_NAME "hello.html"
#define FILE_SIZE 153

int main(void)
{

    int server_fd, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addrlen = sizeof(client_addr);
    bool server_active = true;
    FILE *fp;
    char html_data[FILE_SIZE], *hello;
    int ch, i = 0;

    char *header_data = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: 153\r\n\r\n";

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("In socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("In bind");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, SERVER_PENDING_CONNECTION) == -1)
    {
        perror("In listen");
        exit(EXIT_FAILURE);
    }

    while (server_active)
    {
        printf("\n+Waiting for new connection+\n");

        if ((fp = fopen(FILE_NAME, "r")) == NULL)
        {
            printf("Can't open %s\n", FILE_NAME);
            exit(EXIT_FAILURE);
        }

        while ((ch = getc(fp)) != EOF)
        {
            html_data[i] = ch;
            i++;
        }
        i = 0;

        if ((new_socket = accept(server_fd, (struct sockaddr *)&client_addr, &addrlen)) == -1)
        {
            perror("In accept");
            exit(EXIT_FAILURE);
        }

        hello = malloc(sizeof(header_data) + sizeof(html_data));
        strcpy(hello, header_data);
        strcat(hello, html_data);

        char buffer[SERVER_BUFFER] = {0};
        read(new_socket, buffer, SERVER_BUFFER);

        printf("%s\n", buffer);
        write(new_socket, hello, strlen(hello));
        printf("\n-Hello message sent-\n");

        free(hello);
        hello = NULL;

        fclose(fp);

        close(new_socket);
    }

    return 0;
}
