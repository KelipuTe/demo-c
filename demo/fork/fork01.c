#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();
  // 父进程会拿到子进程pid，子进程会拿到0
  printf("pid=%d\r\n", pid);
  return 0;
}