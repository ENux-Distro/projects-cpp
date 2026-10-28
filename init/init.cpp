#include <iostream>
#include <unistd.h>
#include <sys/mount.h>
#include <sys/wait.h>

#define null nullptr

/* int mount(const char *source, const char *target,
                 const char *filesystemtype, unsigned long mountflags,
                 const void *_Nullable data);
*/

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

int mount2(const char *source, const char *target, const char *filesystemtype) {
    if (mount(source, target, filesystemtype, 0, null) != 0) {
        perror("init: Failed to mount");
        return 1;
    }

    return 0;
}

int main() {

    mount2("devtmpfs", "/dev", "none");
    mount2("proc", "/proc", "none");
    mount2("sysfs", "/sys", "sys");

    for (;;) {
        exec("/bin/sh", (char *[]){"/bin/sh", null});
        return 0;
    }

    return 0;

}