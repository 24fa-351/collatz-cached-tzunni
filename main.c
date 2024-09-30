#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "collatz.h"

int main(int argc, char *argv[]) {
    // declare and get our variables
    unsigned long long int N;
    unsigned long long int MIN;
    unsigned long long int MAX;
    char* mode;
    int size;

    sscanf(argv[1], "%llu", &N);
    sscanf(argv[2], "%llu", &MIN);
    sscanf(argv[3], "%llu", &MAX);
    sscanf(argv[4], "%s", mode);
    sscanf(argv[5], "%d", &size);

    srand(time(NULL)); // seed rng
    Cache* collatz_storage = (Cache*)malloc(sizeof(Cache)); // allocate cache mem
    
    // set the mode using function to pointer
    unsigned long long int (*collatz_wrapper)(unsigned long long int, Cache*, char*, unsigned long long int*, unsigned long long int*) = NULL;
    if (strcmp(mode, "LRU") == 0) {
        initialize(collatz_storage, size);
        collatz_wrapper = collatz_wrapperLRU;
    } else if (strcmp(mode, "LFU") == 0) {
        initialize(collatz_storage, size);
        collatz_wrapper = collatz_wrapperLFU;
    } else {
        collatz_wrapper = collatz_wrapperBasic;
    }

    // run our randomizer, and track cache hits and misses
    unsigned long long int cache_hit = 0;
    unsigned long long int cache_miss = 0;
    for (unsigned long long int N_counter = 0; N_counter < N; ++N_counter) {
        unsigned long long int RN = (rand() % (MAX - MIN + 1)) + MIN;
        (*collatz_wrapper)(RN, collatz_storage, mode, &cache_hit, &cache_miss);
    }
    printf("%.2f%%\n", (double)cache_hit/(cache_hit + cache_miss) * 100);
}