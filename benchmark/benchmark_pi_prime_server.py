import time
from pi_prime_server import PiPrimeServer

def benchmark_pi_prime_server(n):
    server = PiPrimeServer()
    start_time = time.time()
    result = server.handle_request({'method': 'calculate_pi', 'params': {'n': n}})
    end_time = time.time()
    return end_time - start_time

def benchmark_pi_prime_server_random(n, iterations):
    server = PiPrimeServer()
    total_time = 0
    for _ in range(iterations):
        start_time = time.time()
        result = server.handle_request({'method': 'calculate_pi', 'params': {'n': random.randint(1, n)}})
        end_time = time.time()
        total_time += end_time - start_time
    return total_time / iterations

if __name__ == '__main__':
    n = 1000000
    iterations = 100
    print(f"Benchmarking PiPrimeServer for {n} iterations...")
    time_taken = benchmark_pi_prime_server(n)
    print(f"Time taken: {time_taken:.6f} seconds")
    print(f"Benchmarking PiPrimeServer for random iterations up to {n} over {iterations} iterations...")
    time_taken_random = benchmark_pi_prime_server_random(n, iterations)
    print(f"Average time taken: {time_taken_random:.6f} seconds")
