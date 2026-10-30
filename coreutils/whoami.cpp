#include <iostream>
#include <unistd.h>
#include <pwd.h>

using namespace std;

int main() {
    uid_t uid = getuid();

    struct passwd *pw = getpwuid(uid);

    if (pw) {
        cout << pw->pw_name << endl;
    } else {
        perror("whoami: Failed to grab user information");
    }
}