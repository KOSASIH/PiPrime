import socket
import struct

class PiPrimeNetwork:
    def __init__(self, port):
        self.listener = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.listener.bind(("localhost", port))
        self.listener.listen(5)

    def listen(self):
        while True:
            conn, addr = self.listener.accept()
            self.handle_connection(conn)

    def handle_connection(self, conn):
        input_bytes = conn.recv(16)
        input_int = struct.unpack("<Q", input_bytes)[0]
        output_bool = self.is_prime(input_int)
        output_bytes = struct.pack("<?", output_bool)
        conn.sendall(output_bytes)

    def is_prime(self, n):
        if n < 2:
            return False
        for i in range(2, int(n ** 0.5) + 1):
            if n % i == 0:
                return False
        return True

if __name__ == "__main__":
    network = PiPrimeNetwork(8080)
    network.listen()
