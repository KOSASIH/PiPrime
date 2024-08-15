const http = require('http');
const url = require('url');

const port = 8080;

http.createServer((req, res) => {
  const query = url.parse(req.url, true).query;
  if (req.url === '/pi') {
    const pi = calculatePi(50);
    res.writeHead(200, {'Content-Type': 'text/plain'});
    res.end(pi.toString());
  } else if (req.url === '/prime') {
    const num = query.num;
    const isPrime = isPrime(num);
    res.writeHead(200, {'Content-Type': 'text/plain'});
    res.end(isPrime.toString());
  } else {
    res.writeHead(404, {'Content-Type': 'text/plain'});
    res.end('Error: Invalid request');
  }
}).listen(port, () => {
  console.log(`Serving at port ${port}`);
});

function calculatePi(n) {
  let pi = 0.0;
  for (let k = 0; k < n; k++) {
    pi += 1 / (16 ** k) * (
      4 / (8 * k + 1) -
      2 / (8 * k + 4) -
      1 / (8 * k + 5) -
      1 / (8 * k + 6));
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
