import time
import random
from pi_prime_network import PiPrimeNetwork

def benchmark_pi_prime_network_request_response(n):
    network = PiPrimeNetwork()
    start_time = time.time()
    response = network.send_request('calculate_pi', {'n': n})
    end_time = time.time()
    return end_time - start_time

def benchmark_pi_prime_network_request_response_random(n, iterations):
    network = PiPrimeNetwork()
    total_time = 0
    for _ in range(iterations):
        num = random.randint(1, n)
        start_time = time.time()
        response = network.send_request('calculate_pi', {'n': num})
        end_time = time.time()
        total_time += end_time - start_time
    return total_time / iterations

def benchmark_pi_prime_network_node_communication(n, nodes):
    network = PiPrimeNetwork()
    total_time = 0
    for _ in range(nodes):
        node = network.create_node()
        start_time = time.time()
        response = node.handle_request({'method': 'calculate_pi', 'params': {'n': n}})
        end_time = time.time()
        total_time += end_time - start_time
    return total_time / nodes

def benchmark_pi_prime_network_node_communication_random(n, nodes, iterations):
    network = PiPrimeNetwork()
    total_time = 0
    for _ in range(iterations):
        node = network.create_node()
        num = random.randint(1, n)
        start_time = time.time()
        response = node.handle_request({'method': 'calculate_pi', 'params': {'n': num}})
        end_time = time.time()
        total_time += end_time - start_time
    return total_time / iterations

if __name__ == '__main__':
    n = 1000000
    iterations = 100
    nodes = 10

    print(f"Benchmarking PiPrimeNetwork request-response for {n} iterations...")
    time_taken = benchmark_pi_prime_network_request_response(n)
    print(f"Time taken: {time_taken:.6f} seconds")

    print(f"Benchmarking PiPrimeNetwork request-response for random {n} iterations over {iterations} iterations...")
    time_taken_random = benchmark_pi_prime_network_request_response_random(n, iterations)
    print(f"Average time taken: {time_taken_random:.6f} seconds")

    print(f"Benchmarking PiPrimeNetwork node communication for {n} iterations over {nodes} nodes...")
    time_taken_node_communication = benchmark_pi_prime_network_node_communication(n, nodes)
    print(f"Time taken: {time_taken_node_communication:.6f} seconds")

    print(f"Benchmarking PiPrimeNetwork node communication for random {n} iterations over {nodes} nodes over {iterations} iterations...")
    time_taken_node_communication_random = benchmark_pi_prime_network_node_communication_random(n, nodes, iterations)
    print(f"Average time taken: {time_taken_node_communication_random:.6f} seconds")
