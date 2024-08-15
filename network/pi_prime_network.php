<?php

class PiPrimeNetwork {
    private $socket;

    public function __construct($port) {
        $this->socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
        socket_bind($this->socket, "127.0.0.1", $port);
        socket_listen($this->socket);
    }

    public function listen() {
        while (true) {
            $client = socket_accept($this->socket);
            $this->handleConnection($client);
        }
    }

    private function handleConnection($client) {
        $input = socket_read($client, 16);
        $input = unpack("N*", $input);
        $output = $this->isPrime($input[1]);
        socket_write($client, pack("C", $output));
    }

    private function isPrime($n) {
        if ($n < 2) return false;
        for ($i = 2; $i * $i <= $n; $i++) {
            if ($n % $i === 0) return false;
        }
        return true;
    }
}

$network = new PiPrimeNetwork(8080);
$network->listen();

?>
