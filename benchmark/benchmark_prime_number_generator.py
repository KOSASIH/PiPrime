import time
import random
from prime_number_generator import PrimeNumberGenerator

def benchmark_prime_number_generator(n):
    generator = PrimeNumberGenerator()
    start_time = time.time()
    primes = generator.generate(n)
    end_time = time.time()
    return end_time - start_time

def benchmark_prime_number_generator_random(n, iterations):
    generator = PrimeNumberGenerator()
    total_time = 0
    for _ in range(iterations):
        start_time = time.time()
        primes = generator.generate(random.randint(1, n))
        end_time = time.time()
        total_time += end_time - start_time
    return total_time / iterations

if __name__ == '__main__':
    n = 10000
    iterations = 100
    print(f"Benchmarking PrimeNumberGenerator for {n} primes...")
    time_taken = benchmark_prime_number_generator(n)
    print(f"Time taken: {time_taken:.6f} seconds")
    print(f"Benchmarking PrimeNumberGenerator for random {n} primes over {iterations} iterations...")
    time_taken_random = benchmark_prime_number_generator_random(n, iterations)
    print(f"Average time taken: {time_taken_random:.6f} seconds")
