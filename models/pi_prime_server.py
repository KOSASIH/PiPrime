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
       
