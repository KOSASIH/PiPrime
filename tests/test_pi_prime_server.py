import unittest
from pi_prime_server import PiPrimeServer

class TestPiPrimeServer(unittest.TestCase):
    def test_handle_request(self):
        server = PiPrimeServer()
        request = {'method': 'calculate_pi', 'params': {'n': 1000}}
        response = server.handle_request(request)
        self.assertEqual(response['status'], 'success')
        self.assertAlmostEqual(response['result'], 3.14159, places=4)

    def test_handle_request_with_custom_algorithm(self):
        server = PiPrimeServer()
        request = {'method': 'calculate_pi', 'params': {'n': 1000, 'algorithm': 'bbp'}}
        response = server.handle_request(request)
        self.assertEqual(response['status'], 'success')
        self.assertAlmostEqual(response['result'], 3.14159, places=4)

    def test_handle_request_with_invalid_algorithm(self):
        server = PiPrimeServer()
        request = {'method': 'calculate_pi', 'params': {'n': 1000, 'algorithm': 'invalid'}}
        response = server.handle_request(request)
        self.assertEqual(response['status'], 'error')
        self.assertEqual(response['error'], 'Invalid algorithm')

if __name__ == '__main__':
    unittest.main()
