from flask import Flask, jsonify, request
from flask_restful import Api, Resource

app = Flask(__name__)
api = Api(app)

users = [
    {"id": "1", "name": "John Doe", "email": "john@example.com"},
    {"id": "2", "name": "Jane Doe", "email": "jane@example.com"}
]

class Users(Resource):
    def get(self):
        return jsonify(users)

    def post(self):
        user = request.get_json()
        users.append(user)
        return jsonify(user), 201

class User(Resource):
    def get(self, id):
        for user in users:
            if user["id"] == id:
                return jsonify(user)
        return jsonify({"error": "User not found"}), 404

    def put(self, id):
        for user in users:
            if user["id"] == id:
                user.update(request.get_json())
                return jsonify(user)
        return jsonify({"error": "User not found"}), 404

    def delete(self, id):
        for user in users:
            if user["id"] == id:
                users.remove(user)
                return jsonify({"message": "User deleted"})
        return jsonify({"error": "User not found"}), 404

api.add_resource(Users, "/users")
api.add_resource(User, "/users/<string:id>")

if __name__ == "__main__":
    app.run(debug=True)
