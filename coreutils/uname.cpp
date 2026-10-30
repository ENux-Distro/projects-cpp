#include <iostream>
#include <sys/utsname.h>
#include <cstring>

using namespace std;

struct utsname buffer;

int uname2() {
    if (uname(&buffer) != 0) {
        perror("uname: Failed");
        return 1;
    }

    return 0;
}

    void o() {
        uname2();
        cout << buffer.sysname << endl;
    }

    void n() {
        uname2();
        cout << buffer.nodename << endl;
    }

    void r() {
        uname2();
        cout << buffer.release << endl;
    }

    void v() {
        uname2();
        cout << buffer.version << endl;
    }

    void m() {
        uname2();
        cout << buffer.machine << endl;
    }

    void s() {
        cout << "Linux" << endl;
    }


int main(int argc, char **argv) {

    struct utsname buffer;

    if (uname(&buffer) != 0) {
        perror("uname: Failed");
        return 1;
    }

    if (argc < 2 || strcmp(argv[1], "-s") == 0) {
        s();
    } else if (strcmp(argv[1], "-o") == 0) {
        o();
    } else if (strcmp(argv[1], "-n") == 0) {
        n();
    } else if (strcmp(argv[1], "-r") == 0) {
        r();
    } else if (strcmp(argv[1], "-v") == 0) {
        v();
    } else if (strcmp(argv[1], "-m") == 0) {
        m();
    } else {
        cout << "uname: Unrecognized option: " << argv[1] << endl;
    }
}