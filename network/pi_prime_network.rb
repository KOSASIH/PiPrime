require "socket"

class PiPrimeNetwork
    def initialize(port)
        @socket = TCPServer.new("localhost", port)
    end

    def listen
        loop do
            client = @socket.accept
            handle_connection(client)
        end
    end

    private

    def handle_connection(client)
        input = client.recv(16)
        input = input.unpack("N")[0]
        output = is_prime(input)
        client.write([output].pack("C"))
    end

    def is_prime(n)
        return false if n < 2
        (2..Math.sqrt(n)).none? { |i| n % i == 0 }
    end
end

network = PiPrimeNetwork.new(8080)
network.listen
