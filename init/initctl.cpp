#include <iostream>
#include <unistd.h>
#include <cstring>
#include <sys/wait.h>
#include <sys/reboot.h>

#define null nullptr

using namespace std;

void exec(char *file, char **args) {

    pid_t pid = fork();

    if (pid == 0) {
        execvp(file, args);
        perror("init: Failed to execute");
        exit(127);
    } else {
        siginfo_t info;
        waitid(P_PID, pid, &info, WEXITED);
    }

}

int main(int argc, char **argv) {
    if (argc < 2) {
        cout << "initctl - A system and service manager" << endl;
        cout << "Usage:" << endl;
        cout << " start <service FULLPATH>: Runs a service" << endl;
        cout << " restart: Forcefully restarts your computer" << endl;
        cout << " forceoff: Forcefully powers off your computer" << endl;
        return 0;
    }

    if (strcmp(argv[1], "start") == 0) {
        if (argv[2] == null) {
            cout << "ERROR: Please enter the service you want to start" << endl;
            return 1;
        }

        exec(argv[2], (char *[]){(char *)argv[2], null});
    } else if (strcmp(argv[1], "restart") == 0) {
        if (reboot(RB_AUTOBOOT) != 0) {
            cout << "ERROR: YOUR SYSTEM CAN'T REBOOT, YOURE COOKED" << endl;
            return 222;
        }
    } else if (strcmp(argv[1], "forceoff") == 0) {
        if (reboot(RB_POWER_OFF) != 0) {
            cout << "ERROR: YOUR SYSTEM CAN'T FORCEOFF, YOURE COOKED" << endl;
            return 22;
        }
    }

}