#include <iostream>
#include <sys/mount.h>

/*
int mount(const char *source, const char *target,
                 const char *filesystemtype, unsigned long mountflags,
                 const void *_Nullable data);
*/

using namespace std;

int main(int argc, char **argv) {
    if (!argv[1] || !argv[2] || !argv[3]) {
        cout << "mount: Not enough arguments" << endl;
        return 1;
    } else {
        if (mount(argv[1], argv[2], argv[3], 0, NULL) != 0) {
            perror("mount: Failed to mount");
            return 1;
        }
    }
}