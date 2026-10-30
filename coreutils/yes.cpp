#include <unistd.h>

int main() {
    for (;;) {
        write(1, "y\n", 2);
    }
}