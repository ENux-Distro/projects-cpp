#include <iostream>
#include <fcntl.h>
#include <dirent.h>

using namespace std;

int main(int argc, char **argv) {
    const char *path;
    if (argc < 2) {
        path = ".";
    } else {
        path = argv[1];
    }

    DIR *dir = opendir(path);

    if (!dir) {
        perror("ls: Failed to open dir");
        return 1;
    }
    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue;
        }

        cout << entry->d_name << "  ";
    }

    cout << endl;
    closedir(dir);
}