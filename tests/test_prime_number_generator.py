import unittest
from prime_number_generator import PrimeNumberGenerator

class TestPrimeNumberGenerator(unittest.TestCase):
    def test_generate_prime_numbers(self):
        generator = PrimeNumberGenerator()
        primes = generator.generate_prime_numbers(10)
        self.assertEqual(len(primes), 10)
        self.assertTrue(all(prime > 1 for prime in primes))
        self.assertTrue(all(generator.is_prime(prime) for prime in primes))

    def test_generate_prime_numbers_with_seed(self):
        generator = PrimeNumberGenerator(seed=42)
        primes = generator.generate_prime_numbers(10)
        self.assertEqual(len(primes), 10)
        self.assertTrue(all(prime > 1 for prime in primes))
        self.assertTrue(all(generator.is_prime(prime) for prime in primes))

    def test_is_prime(self):
        generator = PrimeNumberGenerator()
        self.assertTrue(generator.is_prime(2))
        self.assertTrue(generator.is_prime(3))
        self.assertTrue(generator.is_prime(5))
        self.assertFalse(generator.is_prime(4))
        self.assertFalse(generator.is_prime(6))

if __name__ == '__main__':
    unittest.main()
