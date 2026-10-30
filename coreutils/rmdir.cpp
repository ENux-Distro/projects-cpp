#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char **argv) {
    if (!argv[1]) {
        cout << "rmdir: Not enough arguments" << endl;
        return 1;
    }

    if (rmdir(argv[1]) != 0) {
        perror("rmdir: Failed to remove file");
        return 1;
    }
}