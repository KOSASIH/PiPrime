#include <iostream>
#include <string>

int main() {
  std::string cmd;
  std::cout << "Enter command: ";
  std::getline(std::cin, cmd);
  if (cmd == "init") {
    initCmd();
  } else if (cmd == "run") {
    runCmd();
  } else if (cmd == "stop") {
    stopCmd();
  } else if (cmd == "status") {
    statusCmd();
  } else {
    std::cout << "Unknown command: " << cmd << std::endl;
  }
  return 0;
}

void initCmd() {
  std::cout << "Initializing..." << std::endl;
  // initialization code here
}

void runCmd() {
  std::cout << "Running..." << std::endl;
  // running code here
}

void stopCmd() {
  std::cout << "Stopping..." << std::endl;
  // stopping code here
}

void statusCmd() {
  std::cout << "Status:" << std::endl;
  // status code here
}

std::string readLine(const std::string& prompt) {
  std::cout << prompt;
  std::string line;
  std::getline(std::cin, line);
  return line;
}

int readInt(const std::string& prompt) {
  return std::stoi(readLine(prompt));
}

float readFloat(const std::string& prompt) {
  return std::stof(readLine(prompt));
}
