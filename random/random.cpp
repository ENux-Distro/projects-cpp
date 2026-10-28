#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>

#define null nullptr

using namespace std;

int exec(char *file, char **args) {

    pid_t pid = fork();

    if (pid == 0) {
        execvp(file, args);
        perror("init: Failed to execute");
        exit(127);
    } else {
        siginfo_t info;
        waitid(P_PID, pid, &info, WEXITED);
    }

    return 0;

}

int base64() {
    exec((char *)"base64", (char *[]){(char *)"base64", (char *)"/dev/urandom", null});
    return 0;
}

int main(int argc, char **argv) {
    if (argc > 1 && strcmp(argv[1], "--help") == 0) {
        cout << "random - Generate random stuff" << endl;
        cout << "Usage:" << endl;
        cout << " --help: Displays this message" << endl;
        cout << " If your shell supports redirection, you can generate extremely big files, with the redirection option (>) your shell has" << endl;
        cout << " For example:" << endl;
        cout << "   'random > text.txt'" << endl;
        cout << "   'du -sh text.txt'" << endl;
        cout << "   <some very big number>" << endl;
        return 0;
    } else {
        base64();
    }

    return 0;
}