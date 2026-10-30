#include <iostream>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>

using namespace std;

int main(int argc, char **argv) {
    if (!argv[1]) {
        cout << "mkdir: No pathname to create a directory" << endl;
        return 1;
    } else {
        if (mkdir(argv[1], 0755) != 0) {
            perror("mkdir: Failed to create a directory");
            return 1;
        }
    }
}