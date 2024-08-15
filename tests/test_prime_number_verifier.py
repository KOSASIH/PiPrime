import unittest
from prime_number_verifier import PrimeNumberVerifier

class TestPrimeNumberVerifier(unittest.TestCase):
    def test_verify_prime_number(self):
        verifier = PrimeNumberVerifier()
        self.assertTrue(verifier.verify_prime_number(2))
        self.assertTrue(verifier.verify_prime_number(3))
        self.assertTrue(verifier.verify_prime_number(5))
        self.assertFalse(verifier.verify_prime_number(4))
        self.assertFalse(verifier.verify_prime_number(6))

    def test_verify_prime_number_with_timeout(self):
        verifier = PrimeNumberVerifier(timeout=1)
        self.assertTrue(verifier.verify_prime_number(2))
        self.assertTrue(verifier.verify_prime_number(3))
        self.assertTrue(verifier.verify_prime_number(5))
        self.assertFalse(verifier.verify_prime_number(4))
        self.assertFalse(verifier.verify_prime_number(6))

    def test_verify_prime_number_with_custom_algorithm(self):
        verifier = PrimeNumberVerifier(algorithm='miller-rabin')
        self.assertTrue(verifier.verify_prime_number(2))
        self.assertTrue(verifier.verify_prime_number(3))
        self.assertTrue(verifier.verify_prime_number(5))
        self.assertFalse(verifier.verify_prime_number(4))
        self.assertFalse(verifier.verify_prime_number(6))

if __name__ == '__main__':
    unittest.main()
