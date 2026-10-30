#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>

using namespace std;

int main() {

    char command[1024];
    char cwd[9999];
    getcwd(cwd, sizeof(cwd));

    for (;;) {
        getcwd(cwd, sizeof(cwd));
        cout << cwd << "\n> " << flush;
        int count = read(0, command, sizeof(command));
        if (count <= 0) break;
        command[count - 1] = '\0';

        char *args[64];
        int argc = 0;
        for (char *tok = strtok(command, " \t"); tok && argc < 63; tok = strtok(NULL, " \t"))
            args[argc++] = tok;
        args[argc] = NULL;

        if (argc == 0) continue;
        if (strcmp(args[0], "cd") == 0) chdir(args[1]);
        if (strcmp(args[0], "exit") == 0) break;
        pid_t pid = fork();
        if (pid == 0) {
            execvp(args[0], args);
            perror("sh: Failed to execute command");
        } else {
            siginfo_t info;
            waitid(P_PID, pid, &info, WEXITED);
        }
    }
}