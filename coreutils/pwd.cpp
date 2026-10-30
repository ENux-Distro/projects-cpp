#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
    char cwd[9999];
    getcwd(cwd, sizeof(cwd));
    cout << cwd << endl;
}