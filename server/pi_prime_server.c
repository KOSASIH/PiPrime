#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double calculate_pi(int n) {
    double pi = 0.0;
    for (int k = 0; k < n; k++) {
        pi += 1 / pow(16, k) * (
            4 / (8 * k + 1) -
            2 / (8 * k + 4) -
            1 / (8 * k + 5) -
            1 / (8 * k + 6)
        );
    }
    return pi;
}

int is_prime(int num) {
    if (num < 2) {
        return 0;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int port = 8080;

    // Create a socket
    int sockfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t clilen;
    char buffer[256];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error creating socket\n");
        return 1;
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        fprintf(stderr, "Error binding socket\n");
        return 1;
    }

    if (listen(sockfd, 3) < 0) {
        fprintf(stderr, "Error listening on socket\n");
        return 1;
    }

    printf("Server started on port %d\n", port);

    while (1) {
        clilen = sizeof(cliaddr);
        connfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);
        if (connfd < 0) {
            fprintf(stderr, "Error accepting connection\n");
            return 1;
        }

        char request[256];
        recv(connfd, request, 256, 0);

        char response[256];
        char* token = strtok(request, "?");
        if (token != NULL) {
            token = strtok(NULL, "&");
            if (token != NULL) {
                char* keyValue[2];
                keyValue[0] = strtok(token, "=");
                keyValue[1] = strtok(NULL, "=");

                if (strcmp(keyValue[0], "n") == 0) {
                    int n = atoi(keyValue[1]);
                    double pi = calculate_pi(n);
                    sprintf(response, "{\"pi\": %f}", pi);
                } else if (strcmp(keyValue[0], "num") == 0) {
                    int num = atoi(keyValue[1]);
                    int prime = is_prime(num);
                    sprintf(response, "{\"prime\": %d}", prime);
                }
            }
        }

        send(connfd, response, strlen(response), 0);
        close(connfd);
    }

    return 0;
}
