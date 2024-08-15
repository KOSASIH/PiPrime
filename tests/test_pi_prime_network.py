import unittest
from pi_prime_network import PiPrimeNetwork

class TestPiPrimeNetwork(unittest.TestCase):
    def test_send_request(self):
        network = PiPrimeNetwork()
        response = network.send_request('calculate_pi', {'n': 1000})
        self.assertEqual(response['status'], 'success')
        self.assertAlmostEqual(response['result'], 3.14159, places=4)

    def test_send_request_with_custom_algorithm(self):
        network = PiPrimeNetwork()
        response = network.send_request('calculate_pi', {'n': 1000, 'algorithm': 'bbp'})
        self.assertEqual(response['status'], 'success')
        self.assertAlmostEqual(response['result'], 3.14159, places=4)

    def test_send_request_with_invalid_algorithm(self):
        network = PiPrimeNetwork()
        response = network.send_request('calculate_pi', {'n': 1000, 'algorithm': 'invalid'})
        self.assertEqual(response['status'], 'error')
        self.assertEqual(response['error'], 'Invalid algorithm')

if __name__ == '__main__':
    unittest.main()
