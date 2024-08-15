#include <iostream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

class PiPrimeNetwork {
public:
    PiPrimeNetwork(int port) {
        socket_ = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);
        bind(socket_, (struct sockaddr*)&addr, sizeof(addr));
        listen(socket_, 5);
    }

    void listen() {
        while (true) {
            struct sockaddr_in client_addr;
            socklen_t client_len = sizeof(client_addr);
            int client_socket = accept(socket_, (struct sockaddr*)&client_addr, &client_len);
            handleConnection(client_socket);
        }
    }

    void handleConnection(int client_socket) {
        char input_bytes[16];
        read(client_socket, input_bytes, 16);
        long long input = *((long long*)input_bytes);
        bool output = isPrime(input);
        char output_bytes[1] = {(char)(output ? 1 : 0)};
        write(client_socket, output_bytes, 1);
    }

    bool isPrime(long long n) {
        if (n < 2) return false;
        for (long long i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

private:
    int socket_;
};

int main() {
    PiPrimeNetwork network(8080);
    network.listen();
    return 0;
}
