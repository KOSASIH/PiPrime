const net = require("net");

class PiPrimeNetwork {
    constructor(port) {
        this.server = net.createServer((socket) => {
            this.handleConnection(socket);
        });
        this.server.listen(port, () => {
            console.log(`PiPrimeNetwork listening on port ${port}`);
        });
    }

    handleConnection(socket) {
        socket.on("data", (data) => {
            const input = parseInt(data.toString("utf8"), 10);
            const output = this.isPrime(input);
            socket.write(`${output}\n`);
        });
    }

    isPrime(n) {
        if (n < 2) return false;
        for (let i = 2; i * i <= n; i++) {
            if (n % i === 0) return false;
        }
        return true;
    }
}

const network = new PiPrimeNetwork(8080);
