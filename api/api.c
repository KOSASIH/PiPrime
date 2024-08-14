#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <json-c/json.h>

typedef struct {
    char id[10];
    char name[50];
    char email[50];
} User;

User users[] = {
    {"1", "John Doe", "john@example.com"},
    {"2", "Jane Doe", "jane@example.com"}
};

int numUsers = sizeof(users) / sizeof(User);

void getUsers(struct json_object* json) {
    struct json_object* array = json_object_new_array();
    for (int i = 0; i < numUsers; i++) {
        struct json_object* user = json_object_new_object();
        json_object_object_add(user, "id", json_object_new_string(users[i].id));
        json_object_object_add(user, "name", json_object_new_string(users[i].name));
        json_object_object_add(user, "email", json_object_new_string(users[i].email));
        json_object_array_add(array, user);
    }
    json_object_object_add(json, "users", array);
}

void getUser(struct json_object* json, char* id) {
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].id, id) == 0) {
            struct json_object* user = json_object_new_object();
            json_object_object_add(user, "id", json_object_new_string(users[i].id));
            json_object_object_add(user, "name", json_object_new_string(users[i].name));
            json_object_object_add(user, "email", json_object_new_string(users[i].email));
            json_object_object_add(json, "user", user);
            return;
        }
    }
    json_object_object_add(json, "error", json_object_new_string("User not found"));
}

void createUser(struct json_object* json, char* id, char* name, char* email) {
    User* newUser = malloc(sizeof(User));
    strcpy(newUser->id, id);
    strcpy(newUser->name, name);
    strcpy(newUser->email, email);
    users[numUsers++] = *newUser;
    json_object_object_add(json, "message", json_object_new_string("User created"));
}

void updateUser(struct json_object* json, char* id, char* name, char* email) {
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].id, id) == 0) {
            strcpy(users[i].name, name);
            strcpy(users[i].email, email);
            json_object_object_add(json, "message", json_object_new_string("User updated"));
            return;
        }
    }
    json_object_object_add(json, "error", json_object_new_string("User not found"));
}

void deleteUser(struct json_object* json, char* id) {
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].id, id) == 0) {
            for (int j = i; j < numUsers - 1; j++) {
                users[j] = users[j + 1];
            }
            numUsers--;
            json_object_object_add(json, "message", json_object_new_string("User deleted"));
            return;
        }
    }
    json_object_object_add(json, "error", json_object_new_string("User not found"));
}

int main() {
    struct json_object* json = json_object_new_object();
    getUsers(json);
    printf("%s\n", json_object_to_json_string(json));
    json_object_put(json);

    json = json_object_new_object();
    getUser(json, "1");
    printf("%s\n", json_object_to_json_string(json));
    json_object_put(json);

    json = json_object_new_object();
    createUser(json, "3", "John Smith", "john.smith@example.com");
    printf("%s\n", json_object_to_json_string(json));
    json_object_put(json);

    json = json_object_new_object();
    updateUser(json, "1", "Jane Doe", "jane.doe@example.com");
    printf("%s\n", json_object_to_json_string(json));
    json_object_put(json);

    json = json_object_new_object();
    deleteUser(json, "2");
    printf("%s\n", json_object_to_json_string(json));
    json_object_put(json);

    return 0;
}
