#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

class PiPrimeServer {
public:
    double calculatePi(int n) {
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

    bool isPrime(int num) {
        if (num < 2) {
            return false;
        }
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    PiPrimeServer server;
    int port = 8080;

    // Create a socket
    int sockfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t clilen;
    char buffer[256];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        std::cerr << "Error creating socket" << std::endl;
        return 1;
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        std::cerr << "Error binding socket" << std::endl;
        return 1;
    }

    if (listen(sockfd, 3) < 0) {
        std::cerr << "Error listening on socket" << std::endl;
        return 1;
    }

    std::cout << "Server started on port " << port << std::endl;

    while (true) {
        clilen = sizeof(cliaddr);
        connfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);
        if (connfd < 0) {
            std::cerr << "Error accepting connection" << std::endl;
            return 1;
        }

        std::string request;
        recv(connfd, buffer, 256, 0);
        request = buffer;

        std::string response;
        size_t pos = request.find("?");
        if (pos != std::string::npos) {
            std::string queryParams = request.substr(pos + 1);
            size_t pos2 = queryParams.find("&");
            if (pos2 != std::string::npos) {
                std::string param1 = queryParams.substr(0, pos2);
                std::string param2 = queryParams.substr(pos2 + 1);

                std::string keyValue1[2];
                std::string keyValue2[2];
                splitParam(param1, keyValue1);
                splitParam(param2, keyValue2);

                if (keyValue1[0] == "n") {
                    int n = std::stoi(keyValue1[1]);
                    double pi = server.calculatePi(n);
                    response = "{\"pi\": " + std::to_string(pi) + "}";
                } else if (keyValue1[0] == "num") {
                    int num = std::stoi(keyValue1[1]);
                    bool prime = server.isPrime(num);
                    response = "{\"prime\": " + (prime ? "true" : "false") + "}";
                }
            }
        }

        send(connfd, response.c_str(), response.size(), 0);
        close(connfd);
    }

    return 0;
}

void splitParam(const std::string& param, std::string keyValue[]) {
    size_t pos = param.find("=");
    if (pos != std::string::npos) {
        keyValue[0] = param.substr(0, pos);
        keyValue[1] = param.substr(pos + 1);
    }
}
