import java.net.ServerSocket;
import java.net.Socket;

public class PiPrimeNetwork {
    private ServerSocket serverSocket;

    public PiPrimeNetwork(int port) throws Exception {
        serverSocket = new ServerSocket(port);
    }

    public void listen() {
        while (true) {
            Socket clientSocket = serverSocket.accept();
            handleConnection(clientSocket);
        }
    }

    private void handleConnection(Socket clientSocket) throws Exception {
        byte[] inputBytes = new byte[16];
        clientSocket.getInputStream().read(inputBytes);
        long input = ByteBuffer.wrap(inputBytes).getLong();
        boolean output = isPrime(input);
        byte[] outputBytes = new byte[] { (byte) (output ? 1 : 0) };
        clientSocket.getOutputStream().write(outputBytes);
    }

    private boolean isPrime(long n) {
        if (n < 2) return false;
        for (long i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    public static void main(String[] args) throws Exception {
        PiPrimeNetwork network = new PiPrimeNetwork(8080);
        network.listen();
    }
}
