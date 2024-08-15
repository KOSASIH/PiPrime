#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 512

void calculate_pi(int n, char* buffer) {
    double pi = 0.0;
    for (int k = 0; k < n; k++) {
        pi += 1 / pow(16, k) * (
            4 / (8 * k + 1) -
            2 / (8 * k + 4) -
            1 / (8 * k + 5) -
            1 / (8 * k + 6)
        );
    }
    sprintf(buffer, "%f", pi);
}

int is_prime(char* num) {
    int n = atoi(num);
    if (n < 2) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int sockfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t clilen;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(1);
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);

    if (bind(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(sockfd, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Serving at port %d\n", PORT);

    while (1) {
        clilen = sizeof(cliaddr);
        connfd = accept(sockfd, (struct sockaddr*) &cliaddr, &clilen);
        if (connfd < 0) {
            perror("accept failed");
            continue;
        }

        read(connfd, buffer, BUFFER_SIZE);
        if (strcmp(buffer, "/pi") == 0) {
            calculate_pi(1000000, buffer);
            write(connfd, buffer, strlen(buffer));
        } else if (strncmp(buffer, "/prime?num=", 11) == 0) {
            char* num = buffer + 11;
            int is_prime_result = is_prime(num);
            sprintf(buffer, "%d", is_prime_result);
            write(connfd, buffer, strlen(buffer));
        } else {
            write(connfd, "Error: Invalid request", 20);
        }

        close(connfd);
    }

    return 0;
}
