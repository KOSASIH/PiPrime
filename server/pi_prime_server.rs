use std::sync::{Arc, Mutex};
use std::thread;
use std::net::{TcpListener, TcpStream};
use std::io::{Read, Write};

struct PiPrimeServer {
    pi: Mutex<f64>,
    prime: Mutex<bool>,
}

impl PiPrimeServer {
    fn calculate_pi(&self, n: u32) -> f64 {
        let mut pi = 0.0;
        for k in 0..n {
            pi += 1.0 / (16.0_f64.powi(k as i32)) * (
                4.0 / (8 * k + 1) -
                2.0 / (8 * k + 4) -
                1.0 / (8 * k + 5) -
                1.0 / (8 * k + 6)
            );
        }
        *self.pi.lock().unwrap() = pi;
        pi
    }

    fn is_prime(&self, num: &str) -> bool {
        let n = num.parse::<u32>().unwrap();
        if n < 2 {
            return false;
        }
        for i in 2..=(n as f64).sqrt() as u32 {
            if n % i == 0 {
                return false;
            }
        }
        *self.prime.lock().unwrap() = true;
        true
    }
}

fn main() {
    let server = Arc::new(PiPrimeServer {
        pi: Mutex::new(0.0),
        prime: Mutex::new(false),
    });
    let listener = TcpListener::bind("127.0.0.1:8080").unwrap();
    for stream in listener.incoming() {
        let server = Arc::clone(&server);
        thread::spawn(move || {
            let mut stream = stream.unwrap();
            let mut buffer = [0; 512];
            stream.read(&mut buffer).unwrap();
            let request = String::from_utf8_lossy(&buffer);
            if request.starts_with("/pi") {
                let n = request.trim_start_matches("/pi?n=").parse::<u32>().unwrap();
                let pi = server.calculate_pi(n);
                stream.write(pi.to_string().as_bytes()).unwrap();
            } else if request.starts_with("/prime") {
                let num = request.trim_start_matches("/prime?num=").to_string();
                let prime = server.is_prime(&num);
                stream.write(prime.to_string().as_bytes()).unwrap();
            } else {
                stream.write(b"Error: Invalid request").unwrap();
            }
            stream.flush().unwrap();
        });
    }
}
