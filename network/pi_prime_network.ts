import * as net from "net";

class PiPrimeNetwork {
    private server: net.Server;

    constructor(private port: number) {}

    listen() {
        this.server = net.createServer((socket) => {
            this.handleConnection(socket);
        });
        this.server.listen(this.port, () => {
            console.log(`PiPrimeNetwork listening on port ${this.port}`);
        });
    }

    private handleConnection(socket: net.Socket) {
        socket.on("data", (data: Buffer) => {
            const input: number = parseInt(data.toString("utf8"), 10);
            const output: boolean = this.isPrime(input);
            socket.write(`${output}\n`);
        });
    }

    private isPrime(n: number): boolean {
        if (n < 2) return false;
        for (let i = 2; i * i <= n; i++) {
            if (n % i === 0) return false;
        }
        return true;
    }
}

const network = new PiPrimeNetwork(8080);
network.listen();
