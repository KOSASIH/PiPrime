import http.server
import socketserver
import math

class PiPrimeServer(http.server.BaseHTTPRequestHandler):
    def do_GET(self):
        if self.path.startswith("/pi"):
            n = int(self.path.split("=")[1])
            pi = self.calculate_pi(n)
            self.send_response(200)
            self.send_header("Content-type", "text/plain")
            self.end_headers()
            self.wfile.write(str(pi).encode())
        elif self.path.startswith("/prime"):
            num = self.path.split("=")[1]
            prime = self.is_prime(num)
            self.send_response(200)
            self.send_header("Content-type", "text/plain")
            self.end_headers()
            self.wfile.write(str(prime).encode())
        else:
            self.send_response(404)
            self.send_header("Content-type", "text/plain")
            self.end_headers()
            self.wfile.write(b"Error: Invalid request")

    def calculate_pi(self, n):
        pi = 0.0
        for k in range(n):
            pi += 1 / (16 ** k) * (
                4 / (8 * k + 1) -
                2 / (8 * k + 4) -
                1 / (8 * k + 5) -
                1 / (8 * k + 6)
            )
        return pi

    def is_prime(self, num):
        n = int(num)
        if n < 2:
            return False
        for i in range(2, int(math.sqrt(n)) + 1):
            if n % i == 0:
                return False
        return True

def run_server():
    server_address = ('', 8080)
    httpd = http.server.HTTPServer(server_address, PiPrimeServer)
    print("Serving at port 8080")
    httpd.serve_forever()

if __name__ == "__main__":
    run_server()
