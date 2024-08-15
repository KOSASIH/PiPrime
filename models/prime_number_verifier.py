import numpy as np

class PrimeNumberVerifier:
    def __init__(self):
        self.prime_numbers = set()

    def add_prime(self, num):
        self.prime_numbers.add(num)

    def is_prime(self, num):
        return num in self.prime_numbers

    def verify(self, inputs, outputs):
        prime_labels = np.array([self.is_prime(num) for num in inputs])
        accuracy = np.mean(prime_labels == outputs)
        return accuracy
