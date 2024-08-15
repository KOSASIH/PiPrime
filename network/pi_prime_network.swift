import Foundation

class PiPrimeNetwork {
    let socket: Socket

    init(port: Int) {
        socket = Socket()
        socket.bind(to: port)
        socket.listen()
    }

    func listen() {
        while true {
            let client = socket.accept()
            handleConnection(client: client)
        }
    }

    private func handleConnection(client: Socket) {
        let input = client.recv(16)
        let input = Int(input!.withUnsafeBytes { $0.load(as: UInt.self) })
        let output = isPrime(input!)
        client.send([output].withUnsafeBytes { $0 })
    }

    private func isPrime(_ n: Int) -> Bool {
        if n < 2 { return false }
        for i in 2...Int(sqrt(Double(n))) {
            if n % i == 0 { return false }
        }
        return true
    }
}

let network = PiPrimeNetwork(port: 8080)
network.listen()
