import time
from prime_number_verifier import PrimeNumberVerifier

def benchmark_prime_number_verifier(n):
    verifier = PrimeNumberVerifier()
    start_time = time.time()
    result = verifier.verify(n)
    end_time = time.time()
    return end_time - start_time

def benchmark_prime_number_verifier_random(n, iterations):
    verifier = PrimeNumberVerifier()
    total_time = 0
    for _ in range(iterations):
        num = random.randint(1, n)
        start_time = time.time()
        result = verifier.verify(num)
        end_time = time.time()
        total_time += end_time - start_time
    return total_time / iterations

if __name__ == '__main__':
    n = 1000000
    iterations = 100
    print(f"Benchmarking PrimeNumberVerifier for {n}...")
    time_taken = benchmark_prime_number_verifier(n)
    print(f"Time taken: {time_taken:.6f} seconds")
    print(f"Benchmarking PrimeNumberVerifier for random numbers up to {n} over {iterations} iterations...")
    time_taken_random = benchmark_prime_number_verifier_random(n, iterations)
    print(f"Average time taken: {time_taken_random:.6f} seconds")
