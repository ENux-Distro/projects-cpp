#include <unistd.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char **argv) {
    if (!argv[1]) {
        cout << "sleep: Not enough arguments" << endl;
        return 1;
    }

    int seconds = atoi(argv[1]);

    if (sleep(seconds) != 0) {
        perror("rm: Failed to remove file");
        return 1;
    }
}