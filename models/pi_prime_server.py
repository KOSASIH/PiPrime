import socket
import numpy as np
from models.pi_prime_model import PiPrimeModel

class PiPrimeServer:
    def __init__(self, host, port):
        self.host = host
        self.port = port
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.model = PiPrimeModel(num_bits=1024)

    def listen(self):
        self.socket.bind((self.host, self.port))
        self.socket.listen(5)

    def accept(self):
        conn, addr = self.socket.accept()
        return conn

    def handle_request(self, conn):
        inputs = conn.recv(1024)
        inputs = np.frombuffer(inputs, dtype=np.float32)
        outputs = self.model.predict(inputs)
        conn.sendall(outputs.tobytes())

    def close(self):
        self.socket.close()
       
