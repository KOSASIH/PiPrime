import unittest
from pi_prime_node import PiPrimeNode
from pi_prime_model import PiPrimeModel

class TestPiPrimeNode(unittest.TestCase):
    def setUp(self):
        self.node = PiPrimeNode()

    def test_handle_request_calculate_pi(self):
        request = {'method': 'calculate_pi', 'params': {'n': 1000}}
        response = self.node.handle_request(request)
        self.assertEqual(response['status'], 'success')
        self.assertAlmostEqual(response['result'], 3.14159, places=4)

    def test_handle_request_generate_prime_numbers(self):
        request = {'method': 'generate_prime_numbers', 'params': {'n': 10}}
        response = self.node.handle_request(request)
        self.assertEqual(response['status'], 'success')
        self.assertEqual(len(response['result']), 10)
        self.assertTrue(all(prime > 1 for prime in response['result']))

    def test_handle_request_verify_prime_number(self):
        request = {'method': 'verify_prime_number', 'params': {'number': 5}}
        response = self.node.handle_request(request)
        self.assertEqual(response['status'], 'success')
        self.assertTrue(response['result'])

    def test_handle_request_invalid_method(self):
        request = {'method': 'invalid_method', 'params': {}}
        response = self.node.handle_request(request)
        self.assertEqual(response['status'], 'error')
        self.assertEqual(response['error'], 'Invalid method')

    def test_handle_request_missing_params(self):
        request = {'method': 'calculate_pi'}
        response = self.node.handle_request(request)
        self.assertEqual(response['status'], 'error')
        self.assertEqual(response['error'], 'Missing parameters')

    def test_node_model(self):
        self.assertIsInstance(self.node.model, PiPrimeModel)

if __name__ == '__main__':
    unittest.main()
