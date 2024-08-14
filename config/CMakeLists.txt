cmake_minimum_required(VERSION 3.10)

project(PiPrime)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(pi_prime_node node.cpp)
add_executable(pi_prime_server server.cpp)

target_link_libraries(pi_prime_node ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(pi_prime_server ${CMAKE_THREAD_LIBS_INIT})
