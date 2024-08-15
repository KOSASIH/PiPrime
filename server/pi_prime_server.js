const http = require('http');
const url = require('url');

function calculatePi(n) {
    let pi = 0.0;
    for (let k = 0; k < n; k++) {
        pi += 1 / (16 ** k) * (
            4 / (8 * k + 1) -
            2 / (8 * k + 4) -
            1 / (8 * k + 5) -
            1 / (8 * k + 6)
        );
    }
    return pi;
}

function isPrime(num) {
    const n = parseInt(num);
    if (n < 2) {
        return false;
    }
    for (let i = 2; i * i <= n; i++) {
        if (n % i === 0) {
            return false;
        }
    }
    return true;
}

http.createServer((req, res) => {
    const query = url.parse(req.url, true).query;
    if (req.url.startsWith("/pi")) {
        const n = parseInt(query.n);
        const pi = calculatePi(n);
        res.writeHead(200, {'Content-Type': 'text/plain'});
        res.end(pi.toString());
    } else if (req.url.startsWith("/prime")) {
        const num = query.num;
        const prime = isPrime(num);
        res.writeHead(200, {'Content-Type': 'text/plain'});
        res.end(prime.toString());
    } else {
        res.writeHead(404, {'Content-Type': 'text/plain'});
        res.end("Error: Invalid request");
    }
}).listen(8080, () => {
    console.log("Serving at port 8080");
});
