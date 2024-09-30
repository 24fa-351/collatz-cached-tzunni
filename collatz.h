#include "cache.h"

unsigned long long int collatz(unsigned long long int RN);
unsigned long long int collatz_wrapperBasic(unsigned long long int RN, Cache* cache, char* mode, unsigned long long int* hit, unsigned long long int* miss);
unsigned long long int collatz_wrapperLRU(unsigned long long int RN, Cache* cache, char* mode, unsigned long long int* hit, unsigned long long int* miss);
unsigned long long int collatz_wrapperLFU(unsigned long long int RN, Cache* cache, char* mode, unsigned long long int* hit, unsigned long long int* miss);