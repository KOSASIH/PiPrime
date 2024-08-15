#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void handleConnection(int client_socket) {
    char input_bytes[16];
    read(client_socket, input_bytes, 16);
    long long input = *((
