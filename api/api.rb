require 'sinatra'
require 'json'

users = [
  { id: '1', name: 'John Doe', email: 'john@example.com' },
  { id: '2', name: 'Jane Doe', email: 'jane@example.com' }
]

get '/users' do
  json users
end

post '/users' do
  user = JSON.parse(request.body.read)
  users << user
  json user
end

get '/users/:id' do
  id = params[:id]
  user = users.find { |u| u[:id] == id }
  if user
    json user
  else
    json({ error: 'User not found' }), 404
  end
end

put '/users/:id' do
  id = params[:id]
  user = users.find { |u| u[:id] == id }
  if user
    user.merge!(JSON.parse(request.body.read))
    json user
  else
    json({ error: 'User not found' }), 404
  end
end

delete '/users/:id' do
  id = params[:id]
  users.delete_if { |u| u[:id] == id }
  json({ message: 'User deleted' })
end
