use std::net::TcpListener;
use std::thread;

fn main() {
    let listener = TcpListener::bind("127.0.0.1:8080").unwrap();
    println!("Serving at port 8080");

    for stream in listener.incoming() {
        let stream = stream.unwrap();
        thread::spawn(move || {
            let mut buffer = [0; 512];
            stream.read(&mut buffer).unwrap();
            let request = String::from_utf8_lossy(&buffer);
            let response = match request.as_str() {
                "/pi" => calculate_pi(1000000).to_string(),
                "/prime?num=" => is_prime(request.split("=").last().unwrap()).to_string(),
                _ => "Error: Invalid request".to_string(),
            };
            stream.write(response.as_bytes()).unwrap();
            stream.flush().unwrap();
        });
    }
}

fn calculate_pi(n: u32) -> f64 {
    let mut pi = 0.0;
    for k in 0..n {
        pi += 1.0 / (16.0_f64.powi(k as i32)) * (
            4.0 / (8 * k + 1) -
            2.0 / (8 * k + 4) -
            1.0 / (8 * k + 5) -
            1.0 / (8 * k + 6)
        );
    }
    pi
}

fn is_prime(num: &str) -> bool {
    let n = num.parse::<u32>().unwrap();
    if n < 2 {
        return false;
    }
    for i in 2..=(n as f64).sqrt() as u32 {
        if n % i == 0 {
            return false;
        }
    }
    true
            }
