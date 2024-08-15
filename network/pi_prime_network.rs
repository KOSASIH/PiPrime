use std::net::{TcpListener, TcpStream};
use std::io::{Read, Write};
use std::sync::Arc;
use std::thread;

struct PiPrimeNetwork {
    listener: TcpListener,
}

impl PiPrimeNetwork {
    fn new(port: u16) -> Result<Self, std::io::Error> {
        let listener = TcpListener::bind(format!("127.0.0.1:{}", port))?;
        Ok(PiPrimeNetwork { listener })
    }

    fn listen(self) -> Result<(), std::io::Error> {
        for stream in self.listener.incoming() {
            let stream = stream?;
            thread::spawn(move || {
                if let Err(err) = self.handle_connection(stream) {
                    eprintln!("Error handling connection: {}", err);
                }
            });
        }
        Ok(())
    }

    fn handle_connection(&self, mut stream: TcpStream) -> Result<(), std::io::Error> {
        let mut input = [0u8; 16];
        stream.read_exact(&mut input)?;
        let input = u128::from_le_bytes(input);
        let output = is_prime(input);
        let output = output.to_le_bytes();
        stream.write_all(&output)?;
        Ok(())
    }
}

fn is_prime(n: u128) -> bool {
    if n < 2 {
        return false;
    }
    for i in 2..=(n as f64).sqrt() as u128 {
        if n % i == 0 {
            return false;
        }
    }
    true
}

fn main() {
    let network = PiPrimeNetwork::new(8080).unwrap();
    network.listen().unwrap();
}
