use std::env;
use std::io;
use std::io::BufRead;

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() == 1 {
        println!("Usage: cli [command] [options]");
        return;
    }

    let cmd = &args[1];
    match cmd.as_str() {
        "init" => init_cmd(),
        "run" => run_cmd(),
        "stop" => stop_cmd(),
        "status" => status_cmd(),
        _ => println!("Unknown command: {}", cmd),
    }
}

fn init_cmd() {
    println!("Initializing...");
    // initialization code here
}

fn run_cmd() {
    println!("Running...");
    // running code here
}

fn stop_cmd() {
    println!("Stopping...");
    // stopping code here
}

fn status_cmd() {
    println!("Status:");
    // status code here
}

fn read_line(prompt: &str) -> String {
    print!("{}", prompt);
    let mut line = String::new();
    io::stdin().read_line(&mut line).expect("Failed to read line");
    line.trim().to_string()
}

fn read_int(prompt: &str) -> i32 {
    let line = read_line(prompt);
    line.parse::<i32>().expect("Failed to parse int")
}

fn read_float(prompt: &str) -> f64 {
    let line = read_line(prompt);
    line.parse::<f64>().expect("Failed to parse float")
}
