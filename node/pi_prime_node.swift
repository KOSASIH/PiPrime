import Foundation

let port = 8080

let server = HTTPServer()

server.get("/pi") { request in
    let pi = calculatePi(50)
    return HTTPResponse(status: .ok, body: pi.description)
}

server.get("/prime") { request in
    let num = request.queryParameters["num"]
    let isPrime = isPrime(num)
    return HTTPResponse(status: .ok, body: isPrime.description)
}

server.listen(port: port)

func calculatePi(_ n: Int) -> Double {
    var pi = 0.0
    for k in 0..<n {
        pi += 1 / (16 ** k) * (
            4 / (8 * k + 1) -
            2 / (8 * k + 4) -
            1 / (8 * k + 5) -
            1 / (8 * k + 6))
    }
    return pi
}

func isPrime(_ num: String?) -> Bool {
    guard let num = num, let n = Int(num) else { return false }
    if n < 2 { return false }
    for i in 2...Int(sqrt(Double(n))) {
        if n % i == 0 { return false }
    }
    return true
}
