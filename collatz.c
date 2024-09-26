#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "collatz.h"
#include "cache.h"

int main(int argc, char *argv[]) {
    unsigned long long int N;
    unsigned long long int MIN;
    unsigned long long int MAX;
    char mode[] = {};
    sscanf(argv[1], "%llu", &N);
    sscanf(argv[2], "%llu", &MIN);
    sscanf(argv[3], "%llu", &MAX);
    sscanf(argv[4], "%s", &mode);
    if (mode == "LRU" || mode == "LFU") {
        struct LRUCache cache[] = {};
    }
    srand(time(0));

    for (unsigned long long int N_counter = 0; N_counter < N; ++N_counter) {
        unsigned long long int RN = (rand() % (MAX - MIN + 1)) + MIN;
        printf("%llu",RN);
        printf("%c", ',');
        printf("%llu",MIN);
        printf("%c", ',');
        printf("%llu",MAX);
        printf("%c", ',');
        printf("%llu", collatz_wrapper(RN, mode));
        printf("%c", ',');
        printf("%s", mode);
        printf("%c", '\n');
    }
}