require 'http'
require 'json'

class PiPrimeServer
  def calculate_pi(n)
    pi = 0.0
    (0..n-1).each do |k|
      pi += 1 / (16 ** k) * (
        4 / (8 * k + 1) -
        2 / (8 * k + 4) -
        1 / (8 * k + 5) -
        1 / (8 * k + 6)
      )
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
end

server = PiPrimeServer.new

HTTP.createServer do |req, res|
  if req.request_method == 'GET'
    if req.query['n']
      n = req.query['n'].to_i
      pi = server.calculate_pi(n)
      res.status = 200
      res.headers['Content-Type'] = 'application/json'
      res.body = { pi: pi }.to_json
    elsif req.query['num']
      num = req.query['num']
      prime = server.is_prime(num)
      res.status = 200
      res.headers['Content-Type'] = 'application/json'
      res.body = { prime: prime }.to_json
    else
      res.status = 404
      res.headers['Content-Type'] = 'text/plain'
      res.body = 'Error: Invalid request'
    end
  end
end.listen(8080)
