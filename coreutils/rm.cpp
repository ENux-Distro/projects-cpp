#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char **argv) {
    if (!argv[1]) {
        cout << "rm: Not enough arguments" << endl;
        return 1;
    }

    if (unlink(argv[1]) != 0) {
        perror("rm: Failed to remove file");
        return 1;
    }
}