#include "collatz.h"
#include "string.h"

unsigned long long int collatz(unsigned long long int RN) { // core function
    if (RN % 2 == 0) {
        RN = RN / 2;
    } else {
        RN = (RN * 3) + 1;
    }
    return RN;
}

 unsigned long long int collatz_wrapperBasic(unsigned long long int RN, Cache* cache, char* mode, unsigned long long int* hit, unsigned long long int* miss) {
    unsigned long long int step_count = 0; // track step count
    while (RN != 1) {
        RN = collatz(RN);
        ++step_count;
    }
    return step_count;
}

 unsigned long long int collatz_wrapperLRU(unsigned long long int RN, Cache* cache, char* mode, unsigned long long int* hit, unsigned long long int* miss) {
    unsigned long long int step_count = 0;
    int result = lookupLRU(cache, RN); // check if in cache
    if (result != -1) {
        ++(*hit);
        return result;
    }
    unsigned long long int old_RN = RN;
    while (RN != 1) { // iterate through collatz
        RN = collatz(RN);
        ++step_count;
    }
    insertLRU(cache, old_RN, step_count); // return result to cache
    ++(*miss);
    return step_count;
}

 unsigned long long int collatz_wrapperLFU(unsigned long long int RN, Cache* cache, char* mode, unsigned long long int* hit, unsigned long long int* miss) {
    unsigned long long int step_count = 0;
    int result = lookupLFU(cache, RN); // use LFU specific functions
    if (result != -1) {
        ++(*hit);
        return result;
    }
    unsigned long long int old_RN = RN;
    while (RN != 1) {
        RN = collatz(RN);
        ++step_count;
    }
    insertLFU(cache, old_RN, step_count);
    ++(*miss);
    return step_count;
}