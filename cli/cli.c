#include <stdio.h>
#include <string.h>

int main() {
  char cmd[1024];
  printf("Enter command: ");
  fgets(cmd, 1024, stdin);
  cmd[strcspn(cmd, "\n")] = 0; // remove newline character
  if (strcmp(cmd, "init") == 0) {
    initCmd();
  } else if (strcmp(cmd, "run") == 0) {
    runCmd();
  } else if (strcmp(cmd, "stop") == 0) {
    stopCmd();
  } else if (strcmp(cmd, "status") == 0) {
    statusCmd();
  } else {
    printf("Unknown command: %s\n", cmd);
  }
  return 0;
}

void initCmd() {
  printf("Initializing...\n");
  // initialization code here
}

void runCmd() {
  printf("Running...\n");
  // running code here
}

void stopCmd() {
  printf("Stopping...\n");
  // stopping code here
}

void statusCmd() {
  printf("Status:\n");
  // status code here
}

char* readLine(const char* prompt) {
  printf("%s", prompt);
  char line[1024];
  fgets(line, 1024, stdin);
  line[strcspn(line, "\n")] = 0; // remove newline character
  return strdup(line);
}

int readInt(const char* prompt) {
  return atoi(readLine(prompt));
}

float readFloat(const char* prompt) {
  return atof(readLine(prompt));
}
