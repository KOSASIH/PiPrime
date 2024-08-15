import http.server
import socketserver
import math

PORT = 8080

class PiPrimeNode(http.server.BaseHTTPRequestHandler):
    def do_GET(self):
        if self.path == '/pi':
            self.send_response(200)
            self.send_header('Content-type', 'text/plain')
            self.end_headers()
            pi = calculate_pi(50)
            self.wfile.write(pi.encode())
        elif self.path == '/prime':
            self.send_response(200)
            self.send_header('Content-type', 'text/plain')
            self.end_headers()
            num = self.path.split('=')[1]
            is_prime = is_prime(num)
            self.wfile.write(str(is_prime).encode())
        else:
            self.send_response(404)
            self.send_header('Content-type', 'text/plain')
            self.end_headers()
            self.wfile.write(b'Error: Invalid request')

def calculate_pi(n):
    pi = 0.0
    for k in range(n):
        pi += 1 / (16 ** k) * (
            4 / (8 * k + 1) -
            2 / (8 * k + 4) -
            1 / (8 * k + 5) -
            1 / (8 * k + 6))
    return str(pi)

def is_prime(num):
    n = int(num)
    if n < 2:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

with socketserver.TCPServer(("", PORT), PiPrimeNode) as httpd:
    print("Serving at port", PORT)
    httpd.serve_forever()
