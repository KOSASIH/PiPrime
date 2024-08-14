require 'readline'

def main
  cmd = Readline.readline('Enter command: ', true)
  case cmd
  when 'init'
    init_cmd
  when 'run'
    run_cmd
  when 'stop'
    stop_cmd
  when 'status'
    status_cmd
  else
    puts "Unknown command: #{cmd}"
  end
end

def init_cmd
  puts 'Initializing...'
  # initialization code here
end

def run_cmd
  puts 'Running...'
  # running code here
end

def stop_cmd
  puts 'Stopping...'
  # stopping code here
end

def status_cmd
  puts 'Status:'
  # status code here
end

def read_line(prompt)
  Readline.readline(prompt, true)
end

def read_int(prompt)
  read_line(prompt).to_i
end

def read_float(prompt)
  read_line(prompt).to_f
end

main
