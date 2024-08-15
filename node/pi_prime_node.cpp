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
                4 / (8 * k + 
