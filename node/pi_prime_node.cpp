#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <functional>
#include <http/http.h>

using namespace std;

class PiPrimeNode {
public:
    PiPrimeNode(int port) : port_(port) {}

    void start() {
        thread t([this] {
            http::Server server(port_);
            server.setHandler("/pi", [this](http::Request req, http::Response res) {
                double pi = calculatePi(1000000);
                res.setStatus(200);
                res.setBody(to_string(pi));
            });
            server.setHandler("/prime", [this](http::Request req, http::Response res) {
                string num = req.getQueryParameter("num");
                bool isPrime = isPrime(num);
                res.setStatus(200);
                res.setBody(to_string(isPrime));
            });
            server.start();
            cout << "Serving at port " << port_ << endl;
        });
        t.detach();
    }

private:
    int port_;

    double calculatePi(int n) {
        double pi = 0.0;
        for (int k = 0; k < n; k++) {
            pi += 1 / pow(16, k) * (
                4 / (8 * k + 1) -
                2 / (8 * k + 4) -
                1 / (8 * k + 5) -
                1 / (8 * k + 6)
            );
        }
        return pi;
    }

    bool isPrime(string num) {
        int n = stoi(num);
        if (n < 2) {
            return false;
        }
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    PiPrimeNode node(8080);
    node.start();
    return 0;
} 
