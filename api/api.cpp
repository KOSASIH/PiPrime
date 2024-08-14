#include <iostream>
#include <string>
#include <vector>
#include <json/json.h>

struct User {
    std::string id;
    std::string name;
    std::string email;
};

std::vector<User> users = {
    {"1", "John Doe", "john@example.com"},
    {"2", "Jane Doe", "jane@example.com"}
};

void getUsers(Json::Value& json) {
    for (const auto& user : users) {
        Json::Value userJson;
        userJson["id"] = user.id;
        userJson["name"] = user.name;
        userJson["email"] = user.email;
        json.append(userJson);
    }
}

void getUser(const std::string& id, Json::Value& json) {
    for (const auto& user : users) {
        if (user.id == id) {
            json["id"] = user.id;
            json["name"] = user.name;
            json["email"] = user.email;
            return;
        }
    }
    json["error"] = "User not found";
}

void createUser(const Json::Value& json) {
    User user;
    user.id = json["id"].asString();
    user.name = json["name"].asString();
    user.email = json["email"].asString();
    users.push_back(user);
}

void updateUser(const std::string& id, const Json::Value& json) {
    for (auto& user : users) {
        if (user.id == id) {
            user.name = json["name"].asString();
            user.email = json["email"].asString();
            return;
        }
    }
}

void deleteUser(const std::string& id) {
    users.erase(std::remove_if(users.begin(), users.end(), [&](const User& user) {
        return user.id == id;
    }), users.end());
}

int main() {
    // Assume a web framework is used to handle HTTP requests
    // and Json::Value is used to parse and generate JSON responses
    return 0;
}
