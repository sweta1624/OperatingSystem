//to implement the pipes given using pipe ( ) system call. 
//ls -l | grep .c$ who | sort
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main() {
 int fd[2];
 pid_t pid1, pid2;
 if (pipe(fd) == -1) {
 fprintf(stderr, "Pipe failed");
 return 1;
 }
 pid1 = fork();
 if (pid1 < 0) {
 fprintf(stderr, "Fork failed");
 return 1;
 } else if (pid1 == 0) {
 // Child 1 - ls -l | grep .c$
 close(fd[0]); // Close unused read end
 dup2(fd[1], STDOUT_FILENO); // Redirect stdout to write end of pipe
 execl("/bin/ls", "ls", "-l", NULL);
 } else {
 pid2 = fork();
 if (pid2 < 0) {
 fprintf(stderr, "Fork failed");
 return 1;
 } else if (pid2 == 0) {
 // Child 2 - who | sort
 close(fd[1]); // Close unused write end
 dup2(fd[0], STDIN_FILENO); // Redirect stdin to read end of pipe
 execl("/usr/bin/who", "who", NULL);
 } else {
 // Parent
 close(fd[0]);
 close(fd[1]);
 wait(NULL);
 wait(NULL);
 printf("Both children completed\n");
 }
 }
 return 0;
}
