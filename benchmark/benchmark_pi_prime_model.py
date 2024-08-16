import time
from pi_prime_model import PiPrimeModel

def benchmark_pi_prime_model(n):
    model = PiPrimeModel()
    start_time = time.time()
    pi = model.calculate_pi(n)
    end_time = time.time()
    return end_time - start_time

def benchmark_pi_prime_model_random(n, iterations):
    model = PiPrimeModel()
    total_time = 0
    for _ in range(iterations):
        start_time = time.time()
        pi = model.calculate_pi(random.randint(1, n))
        end_time = time.time()
        total_time += end_time - start_time
    return total_time / iterations

if __name__ == '__main__':
    n = 1000000
    iterations = 100
    print(f"Benchmarking PiPrimeModel for {n} iterations...")
    time_taken = benchmark_pi_prime_model(n)
    print(f"Time taken: {time_taken:.6f} seconds")
    print(f"Benchmarking PiPrimeModel for random iterations up to {n} over {iterations} iterations...")
    time_taken_random = benchmark_pi_prime_model_random(n, iterations)
    print(f"Average time taken: {time_taken_random:.6f} seconds")
