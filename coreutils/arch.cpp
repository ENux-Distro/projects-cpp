#include <iostream>
#include <sys/utsname.h>

using namespace std;

int main() {

    struct utsname buffer;

    if (uname(&buffer) != 0) {
        perror("arch: Failed to grab CPU information");
        return 1;
    }

    cout << buffer.machine << endl;
    return 0;
}