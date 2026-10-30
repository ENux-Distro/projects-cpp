#include <iostream>
#include <unistd.h>

int main() {
    if (seteuid(0) != 0) {
        perror("seteuid: Failed to set euid to 0");
        return 1;
    }
}