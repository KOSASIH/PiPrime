import socket
import numpy as np

class PiPrimeClient:
    def __init__(self, host, port):
        self.host = host
        self.port = port
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    def connect(self):
        self.socket.connect((self.host, self.port))

    def send(self, inputs):
        self.socket.sendall(inputs.tobytes())

    def receive(self):
        outputs = self.socket.recv(1024)
        return np.frombuffer(outputs, dtype=np.float32)

    def close(self):
        self.socket.close()
