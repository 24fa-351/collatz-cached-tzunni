#include <string.h>

unsigned long long int collatz(unsigned long long int RN) {
    unsigned long long int step_count = 0;
    while (RN != 1) {
        if (RN % 2 == 0) {
            RN = RN / 2;
        } else {
            RN = (RN * 3) + 1;
        }
        ++step_count;
    }
    return step_count;
}

unsigned long long int collatz_wrapper(unsigned long long int RN, char mode[]) {
    if (strcmp(mode, "LRU") == 0) {
        return collatz(RN);
    } else if (strcmp(mode, "LFU") == 0) {
        return collatz(RN);
    } else {
        return collatz(RN);
    }
}