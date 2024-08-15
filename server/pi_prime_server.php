<?php
class PiPrimeServer {
    public function calculatePi($n) {
        $pi = 0.0;
        for ($k = 0; $k < $n; $k++) {
            $pi += 1 / (16 ** $k) * (
                4 / (8 * $k + 1) -
                2 / (8 * $k + 4) -
                1 / (8 * $k + 5) -
                1 / (8 * $k + 6)
            );
        }
        return $pi;
    }

    public function isPrime($num) {
        $n = intval($num);
        if ($n < 2) {
            return false;
        }
        for ($i = 2; $i * $i <= $n; $i++) {
            if ($n % $i === 0) {
                return false;
            }
        }
        return true;
    }
}

$server = new PiPrimeServer();

if ($_SERVER['REQUEST_METHOD'] === 'GET') {
    if (isset($_GET['n'])) {
        $n = intval($_GET['n']);
        $pi = $server->calculatePi($n);
        header('Content-Type: text/plain');
        echo $pi;
    } elseif (isset($_GET['num'])) {
        $num = $_GET['num'];
        $prime = $server->isPrime($num);
        header('Content-Type: text/plain');
        echo $prime ? 'true' : 'false';
    } else {
        header('HTTP/1.0 404 Not Found');
        echo 'Error: Invalid request';
    }
}
