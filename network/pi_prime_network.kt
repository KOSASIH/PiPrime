import java.net.ServerSocket
import java.net.Socket

class PiPrimeNetwork(private val port: Int) {
    private val serverSocket = ServerSocket(port)

    fun listen() {
        while (true) {
            val clientSocket = serverSocket.accept()
            handleConnection(clientSocket)
        }
    }

    private fun handleConnection(clientSocket: Socket) {
        val inputBytes = ByteArray(16)
        clientSocket.getInputStream().read(inputBytes)
        val input = ByteBuffer.wrap(inputBytes).long
        val output = isPrime(input)
        val outputBytes = byteArrayOf(if (output) 1 else 0)
        clientSocket.getOutputStream().write(outputBytes)
    }

    private fun isPrime(n: Long): Boolean {
        if (n < 2) return false
        for (i in 2..Math.sqrt(n.toDouble()).toLong()) {
            if (n % i == 0L) return false
        }
        return true
    }
}

fun main() {
    val network = PiPrimeNetwork(8080)
    network.listen()
}
