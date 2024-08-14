import Foundation
import Vapor

struct User: Codable {
    let id: String
    let name: String
    let email: String
}

let users = [
    User(id: "1", name: "John Doe", email: "john@example.com"),
    User(id: "2", name: "Jane Doe", email: "jane@example.com")
]

let app = App()

app.get("users") { req -> [User] in
    return users
}

app.post("users") { req -> User in
    let user = try req.content.decode(User.self)
    users.append(user)
    return user
}

app.get("users/:id") { req -> User? in
    let id = req.parameters["id"]
    return users.first(where: { $0.id == id })
}

app.put("users/:id") { req -> User? in
    let id = req.parameters["id"]
    let user = try req.content.decode(User.self)
    if let index = users.firstIndex(where: { $0.id == id }) {
        users[index] = user
        return user
    } else {
        return nil
    }
}

app.delete("users/:id") { req -> Void in
    let id = req.parameters["id"]
    if let index = users.firstIndex(where: { $0.id == id }) {
        users.remove(at: index)
    }
}

app.run()
