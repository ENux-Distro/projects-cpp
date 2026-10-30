#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv) {
    if (argc < 2) {
        for (;;) {
            string stdinread;
            getline(cin, stdinread);
            cout << stdinread << endl;
        }
    }

    FILE *file = fopen(argv[1], "r");

    int ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
}