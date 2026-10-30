#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char **argv) {
    if (!argv[1] || !argv[2]) {
        cout << "ln: No target/linkpath found" << endl;
    }
    else if (symlink(argv[1], argv[2]) != 0) {
        perror("ln: Failed to symlink");
    }
}