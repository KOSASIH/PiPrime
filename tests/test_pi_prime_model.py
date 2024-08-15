import unittest
from pi_prime_model import PiPrimeModel

class TestPiPrimeModel(unittest.TestCase):
    def test_calculate_pi(self):
        model = PiPrimeModel()
        pi = model.calculate_pi(1000)
        self.assertAlmostEqual(pi, 3.14159, places=4)

    def test_calculate_pi_with_custom_algorithm(self):
        model = PiPrimeModel(algorithm='bbp')
        pi = model.calculate_pi(1000)
        self.assertAlmostEqual(pi, 3.14159, places=4)

    def test_generate_prime_numbers(self):
        model = PiPrimeModel()
        primes = model.generate_prime_numbers(10)
        self.assertEqual(len(primes), 10)
        self.assertTrue(all(prime > 1 for prime in primes))

if __name__ == '__main__':
    unittest.main()
