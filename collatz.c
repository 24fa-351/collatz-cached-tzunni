#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int main(int argc, char *argv[]) {
    unsigned long long int N;
    unsigned long long int MIN;
    unsigned long long int MAX;
    sscanf(argv[1], "%llu", &N);
    sscanf(argv[2], "%llu", &MIN);
    sscanf(argv[3], "%llu", &MAX);
    srand(time(0));

    for (unsigned long long int N_counter = 0; N_counter < N; ++N_counter) {
        unsigned long long int RN = (rand() % (MAX - MIN + 1)) + MIN;
        printf("%llu",RN);
        printf("%c", ',');
        printf("%llu",MIN);
        printf("%c", ',');
        printf("%llu",MAX);
        printf("%c", ',');
        printf("%llu", collatz(RN));
        printf("%c", '\n');
    }
}