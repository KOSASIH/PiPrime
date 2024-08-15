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
            stream.write
