<?php

$port = 8080;

http_response_code(200);
header('Content-Type: text/plain');

if ($_SERVER['REQUEST_URI'] == '/pi') {
    $pi = calculatePi(50);
    echo $pi;
} elseif ($_SERVER['REQUEST_URI'] == '/prime') {
    $num = $_GET['num'];
    $isPrime = isPrime($num);
    echo $isPrime;
} else {
    http_response_code(404);
    echo 'Error: Invalid request';
}

function calculatePi($n) {
    $pi = 0.0;
    for ($k = 0; $k < $n; $k++) {
        $pi += 1 / (16 ** $k) * (
            4 / (8 * $k + 1) -
            2 / (8 * $k + 4) -
            1 / (8 * $k + 5) -
            1 / (8 * $k + 6));
    }
    return $pi;
}

function isPrime($num) {
    $n = (int) $num;
    if ($n < 2) {
        return false;
    }
    for ($i = 2; $i * $i <= $n; $i++) {
        if ($n % $i == 0) {
            return false;
        }
    }
    return true;
}

?>
