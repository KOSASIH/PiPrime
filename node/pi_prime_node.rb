require 'webrick'

port = 8080

server = WEBrick::HTTPServer.new(:Port => port)

server.mount_proc '/' do |req, res|
  if req.path == '/pi'
    pi = calculate_pi(50)
    res.status = 200
    res['Content-Type'] = 'text/plain'
    res.body = pi.to_s
  elsif req.path == '/prime'
    num = req.query['num']
    is_prime = is_prime(num)
    res.status = 200
    res['Content-Type'] = 'text/plain'
    res.body = is_prime.to_s
  else
    res.status = 404
    res['Content-Type'] = 'text/plain'
    res.body = 'Error: Invalid request'
  end
end

server.start

def calculate_pi(n)
  pi = 0.0
  (0...n).each do |k|
    pi += 1 / (16 ** k) * (
      4 / (8 * k + 1) -
      2 / (8 * k + 4) -
      1 / (8 * k + 5) -
      1 / (8 * k + 6))
  end
  pi
end

def is_prime(num)
  n = num.to_i
  return false if n < 2
  (2..Math.sqrt(n)).each do |i|
    return false if n % i == 0
  end
  true
end
