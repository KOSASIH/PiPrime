<?php
require_once 'vendor/autoload.php';

use Slim\App;
use Slim\Http\Request;
use Slim\Http\Response;

$app = new App();

$users = [
    ['id' => '1', 'name' => 'John Doe', 'email' => 'john@example.com'],
    ['id' => '2', 'name' => 'Jane Doe', 'email' => 'jane@example.com']
];

$app->get('/users', function (Request $request, Response $response) use ($users) {
    $response->getBody()->write(json_encode($users));
    return $response->withHeader('Content-Type', 'application/json');
});

$app->post('/users', function (Request $request, Response $response) use ($users) {
    $user = json_decode($request->getBody(), true);
    $users[] = $user;
    $response->getBody()->write(json_encode($user));
    return $response->withHeader('Content-Type', 'application/json');
});

$app->get('/users/{id}', function (Request $request, Response $response) use ($users) {
    $id = $request->getAttribute('id');
    $user = array_filter($users, function ($user) use ($id) {
        return $user['id'] == $id;
    });
    if (count($user) > 0) {
        $response->getBody()->write(json_encode($user));
    } else {
        $response->getBody()->write(json_encode(['error' => 'User not found']));
        $response = $response->withStatus(404);
    }
    return $response->withHeader('Content-Type', 'application/json');
});

$app->put('/users/{id}', function (Request $request, Response $response) use ($users) {
    $id = $request->getAttribute('id');
    $user = array_filter($users, function ($user) use ($id) {
        return $user['id'] == $id;
    });
    if (count($user) > 0) {
        $user = json_decode($request->getBody(), true);
        $response->getBody()->write(json_encode($user));
    } else {
        $response->getBody()->write(json_encode(['error' => 'User not found']));
        $response = $response->withStatus(404);
    }
    return $response->withHeader('Content-Type', 'application/json');
});

$app->delete('/users/{id}', function (Request $request, Response $response) use ($users) {
    $id = $request->getAttribute('id');
    $users = array_filter($users, function ($user) use ($id) {
        return $user['id'] != $id;
    });
    $response->getBody()->write(json_encode(['message' => 'User deleted']));
    return $response->withHeader('Content-Type', 'application/json');
});

$app->run();
