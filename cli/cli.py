import sys
import argparse

def main():
    parser = argparse.ArgumentParser(description='CLI tool')
    parser.add_argument('command', help='Command to execute')
    args = parser.parse_args()

    if args.command == 'init':
        init_cmd()
    elif args.command == 'run':
        run_cmd()
    elif args.command == 'stop':
        stop_cmd()
    elif args.command == 'status':
        status_cmd()
    else:
        print(f"Unknown command: {args.command}")

def init_cmd():
    print("Initializing...")
    # initialization code here

def run_cmd():
    print("Running...")
    # running code here

def stop_cmd():
    print("Stopping...")
    # stopping code here

def status_cmd():
    print("Status:")
    # status code here

def read_line(prompt):
    return input(prompt)

def read_int(prompt):
    return int(input(prompt))

def read_float(prompt):
    return float(input(prompt))

if __name__ == '__main__':
    main()
