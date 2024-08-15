import java.io.IOException;
import java.io.OutputStream;
import java.net.InetSocketAddress;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpHandler;
import com.sun.net.httpserver.HttpServer;

public class PiPrimeNode {
    public static void main(String[] args) throws Exception {
        int port = 8080;
        HttpServer server = HttpServer.create(new InetSocketAddress(port), 0);
        server.setExecutor(Executors.newCachedThreadPool());
        server.createContext("/pi", new PiHandler());
        server.createContext("/prime", new PrimeHandler());
        server.start();
        System.out.println("Serving at port " + port);
    }
}

class PiHandler implements HttpHandler {
    @Override
    public void handle(HttpExchange exchange) throws IOException {
        double pi = calculatePi(1000000);
        exchange.sendResponseHeaders(200, String.valueOf(pi).length());
        OutputStream os = exchange.getResponseBody();
        os.write(String.valueOf(pi).getBytes());
        os.close();
    }
}

class PrimeHandler implements HttpHandler {
    @Override
    public void handle(HttpExchange exchange) throws IOException {
        String num = exchange.getRequestURI().getQuery().split("=")[1];
        boolean isPrime = isPrime(num);
        exchange.sendResponseHeaders(200, String.valueOf(isPrime).length());
        OutputStream os = exchange.getResponseBody();
        os.write(String.valueOf(isPrime).getBytes());
        os.close();
    }
}

public static double calculatePi(int n) {
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

public static boolean isPrime(String num) {
    int n = Integer.parseInt(num);
    if (n < 2) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
