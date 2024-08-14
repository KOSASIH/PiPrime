use actix_web::{web, App, HttpServer, Responder};
use serde::{Deserialize, Serialize};

#[derive(Serialize, Deserialize)]
struct User {
    id: String,
    name: String,
    email: String,
}

let users = vec![
    User {
        id: "1".to_string(),
        name: "John Doe".to_string(),
        email: "john@example.com".to_string(),
    },
    User {
        id: "2".to_string(),
        name: "Jane Doe".to_string(),
        email: "jane@example.com".to_string(),
    },
];

async fn get_users() -> impl Responder {
    web::Json(users.clone())
}

async fn get_user(id: web::Path<String>) -> impl Responder {
    let user = users.iter().find(|u| u.id == id.into_inner());
    match user {
        Some(u) => web::Json(u.clone()),
        None => web::Json("User not found"),
    }
}

async fn create_user(user: web::Json<User>) -> impl Responder {
    users.push(user.into_inner());
    web::Json("User created")
}

async fn update_user(id: web::Path<String>, user: web::Json<User>) -> impl Responder {
    let idx = users.iter().position(|u| u.id == id.into_inner());
    match idx {
        Some(i) => {
            users[i] = user.into_inner();
            web::Json("User updated")
        }
        None => web::Json("User not found"),
    }
}

async fn delete_user(id: web::Path<String>) -> impl Responder {
    let idx = users.iter().position(|u| u.id == id.into_inner());
    match idx {
        Some(i) => {
            users.remove(i);
            web::Json("User deleted")
        }
        None => web::Json("User not found"),
    }
}

#[actix_web::main]
async fn main() -> std::io::Result<()> {
    HttpServer::new(|| {
        App::new()
            .service(web::resource("/users").route(web::get().to(get_users)))
            .service(web::resource("/users/{id}").route(web::get().to(get_user)))
            .service(web::resource("/users").route(web::post().to(create_user)))
            .service(web::resource("/users/{id}").route(web::put().to(update_user)))
            .service(web::resource("/users/{id}").route(web::delete().to(delete_user)))
    })
    .bind("127.0.0.1:8080")?
    .run()
    .await
}
