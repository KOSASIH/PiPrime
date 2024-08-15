import java.net.ServerSocket
import java.net.Socket
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter

class PiPrimeServer {
    fun calculatePi(n: Int): Double {
        var pi = 0.0
        for (k in 0 until n) {
            pi += 1 / Math.pow(16.0, k.toDouble()) * (
                4 / (8 * k + 1) -
                2 / (8 * k + 4) -
                1 / (8 * k + 5) -
                1 / (8 * k + 6)
            )
        }
        return pi
    }

    fun isPrime(num: Int): Boolean {
        if (num < 2) {
            return false
        }
        for (i in 2..Math.sqrt(num.toDouble()).toInt()) {
            if (num % i == 0) {
                return false
            }
        }
        return true
    }
}

fun main() {
    val server = PiPrimeServer()
    val serverSocket = ServerSocket(8080)

    while (true) {
        val socket = serverSocket.accept()
        val reader = BufferedReader(InputStreamReader(socket.inputStream))
        val request = reader.readLine()
        val queryParams = request.split("\\?")[1].split("&")

        var response = ""
        for (param in queryParams) {
            val keyValue = param.split("=")
            if (keyValue[0] == "n") {
                val n = keyValue[1].toInt()
                val pi = server.calculatePi(n)
                response = "{\"pi\": $pi}"
            } else if (keyValue[0] == "num") {
                val num = keyValue[1].toInt()
                val prime = server.isPrime(num)
                response = "{\"prime\": $prime}"
            }
        }

        val writer = PrintWriter(socket.outputStream, true)
        writer.println(response)
        socket.close()
    }
}
