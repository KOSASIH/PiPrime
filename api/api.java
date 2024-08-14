import java.util.ArrayList;
import java.util.List;

import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

class User {
    private String id;
    private String name;
    private String email;

    // getters and setters
}

@RestController
public class Api {
    private List<User> users = new ArrayList<>();

    public Api() {
        users.add(new User("1", "John Doe", "john@example.com"));
        users.add(new User("2", "Jane Doe", "jane@example.com"));
    }

    @GetMapping("/users")
    public List<User> getUsers() {
        return users;
    }

    @GetMapping("/users/{id}")
    public User getUser(@PathVariable String id) {
        for (User user : users) {
            if (user.getId().equals(id)) {
                return user;
            }
        }
        return null;
    }

    @PostMapping("/users")
    public String createUser(@RequestBody User user) {
        users.add(user);
        return "User created";
    }

    @PutMapping("/users/{id}")
    public String updateUser(@PathVariable String id, @RequestBody User user) {
        for (int i = 0; i < users.size(); i++) {
            if (users.get(i).getId().equals(id)) {
                users.set(i, user);
                return "User updated";
            }
        }
        return "User not found";
    }

    @DeleteMapping("/users/{id}")
    public String deleteUser(@PathVariable String id) {
        for (int i = 0; i < users.size(); i++) {
            if (users.get(i).getId().equals(id)) {
                users.remove(i);
                return "User deleted";
            }
        }
        return "User not found";
    }
}
