import Foundation
import HTTPServer

class PiPrimeServer {
    func calculatePi(_ n: Int) -> Double {
        var pi = 0.0
        for k in 0..<n {
            pi += 1 / pow(16, Double(k)) * (
                4 / (8 * k + 1) -
                2 / (8 * k + 4) -
                1 / (8 * k + 5) -
                1 / (8 * k + 6)
            )
        }
        return pi
    }

    func isPrime(_ num: Int) -> Bool {
        if num < 2 {
            return false
        }
        for i in 2...Int(sqrt(Double(num))) {
            if num % i == 0 {
                return false
            }
        }
        return true
    }
}

let server = PiPrimeServer()

HTTPServer.listen(on: 8080) { request in
    if request.method == "GET" {
        if let n = request.queryParams["n"] {
            let pi = server.calculatePi(Int(n)!)
            return HTTPResponse(body: "{\"pi\": \(pi)}", headers: ["Content-Type": "application/json"])
        } else if let num = request.queryParams["num"] {
            let prime = server.isPrime(Int(num)!)
            return HTTPResponse(body: "{\"prime\": \(prime)}", headers: ["Content-Type": "application/json"])
        } else {
            return HTTPResponse(statusCode: 404, body: "Error: Invalid request", headers: ["Content-Type": "text/plain"])
        }
    }
}
