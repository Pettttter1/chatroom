#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <log.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int create_connection() {
        int server_fd, new_socket;
        struct sockaddr_in address;
        int opt = 1;
        int addrlen = sizeof(address);
        char buffer[BUFFER_SIZE] = {0};

        // 创建socket文件描述符
        if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
                jj_log("socket failed");
                exit(EXIT_FAILURE);
        }

        // 强制绑定端口
        if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
                jj_log("setsockopt failed");
                close(server_fd);
                exit(EXIT_FAILURE);
        }

        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(PORT);

        // 绑定socket到指定的端口
        if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
                jj_log("bind failed");
                close(server_fd);
                exit(EXIT_FAILURE);
        }

        // 开始监听，最多5个挂起连接
        if (listen(server_fd, 5) < 0) {
                jj_log("listen failed");
                close(server_fd);
                exit(EXIT_FAILURE);
        }

        printf("Server is listening on port %d\n", PORT);

        // 接受客户端连接
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
                jj_log("accept failed");
                close(server_fd);
                exit(EXIT_FAILURE);
        }

        // 读取客户端发送的消息
        int valread = read(new_socket, buffer, BUFFER_SIZE);
        printf("Received message: %s\n", buffer);

        // 向客户端发送回复
        char *response = "Hello from server";
        send(new_socket, response, strlen(response), 0);
        printf("Hello message sent\n");

        // 关闭socket
        close(new_socket);
        close(server_fd);

        return 0;
}
