import java.net.*;
import java.io.*;
import java.util.*;

class PiPrimeServer {
    public double calculatePi(int n) {
        double pi = 0.0;
        for (int k = 0; k < n; k++) {
            pi += 1 / Math.pow(16, k) * (
                4 / (8 * k + 1) -
                2 / (8 * k + 4) -
                1 / (8 * k + 5) -
                1 / (8 * k + 6)
            );
        }
        return pi;
    }

    public boolean isPrime(int num) {
        if (num < 2) {
            return false;
        }
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
}

public class PiPrimeServerMain {
    public static void main(String[] args) throws IOException {
        PiPrimeServer server = new PiPrimeServer();
        ServerSocket serverSocket = new ServerSocket(8080);

        while (true) {
            Socket socket = serverSocket.accept();
            BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            String request = reader.readLine();
            String[] queryParams = request.split("\\?")[1].split("&");

            String response = "";
            for (String param : queryParams) {
                String[] keyValue = param.split("=");
                if (keyValue[0].equals("n")) {
                    int n = Integer.parseInt(keyValue[1]);
                    double pi = server.calculatePi(n);
                    response = "{\"pi\": " + pi + "}";
                } else if (keyValue[0].equals("num")) {
                    int num = Integer.parseInt(keyValue[1]);
                    boolean prime = server.isPrime(num);
                    response = "{\"prime\": " + prime + "}";
                }
            }

            OutputStream outputStream = socket.getOutputStream();
            outputStream.write(response.getBytes());
            socket.close();
        }
    }
}
