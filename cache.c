#include "cache.h"

#include <string.h>
#include <stdlib.h>

void initialize(Cache* cache, int size) {
    cache->entries = (col_item*)malloc(sizeof(col_item) * size); // allocate memory for the cache
    cache->size = size; // pass the size of the cache
    cache->current_size = 0; // initialize the current size of the cache
    cache->timestamp = 0; // use timestamp, only used for LRU
}

int lookupLRU(Cache* cache, int key) {
    for (int ix = 0; ix < cache->current_size; ++ix) { // iterate through the cache
        if (cache->entries[ix].key == key) {
            cache->entries[ix].sorter = ++cache->timestamp; // update the timestamp
            return cache->entries[ix].value;
        }
    }
    return -1;
}
int lookupLFU(Cache* cache, int key) {
    for (int ix = 0; ix < cache->current_size; ++ix) {
        if (cache->entries[ix].key == key) {
            ++cache->entries[ix].sorter; // update the frequency
            return cache->entries[ix].value;
        }
    }
    return -1;
}

void insertLRU(Cache* cache, int key, int value) {
    if (cache->current_size == cache->size) {
        int evict_candidate = 0;
        unsigned long long min_sorter = cache->entries[0].sorter; // min algo
        for (int ix = 1; ix < cache->current_size; ++ix) {
            if (cache->entries[ix].sorter < min_sorter) {
                evict_candidate = ix;
                min_sorter = cache->entries[ix].sorter;
            }
        }

        for (int ix = evict_candidate; ix < cache->current_size - 1; ++ix) { // shift the cache (array)
            cache->entries[ix] = cache->entries[ix + 1];
        }
        --cache->current_size;
    }
    cache->entries[cache->current_size].key = key;
    cache->entries[cache->current_size].value = value;
    cache->entries[cache->current_size].sorter = ++cache->timestamp; // use the timestamp
    ++cache->current_size;
}
void insertLFU(Cache* cache, int key, int value) {
    if (cache->current_size == cache->size) {
        int evict_candidate = 0;
        unsigned long long min_sorter = cache->entries[0].sorter;
        for (int ix = 1; ix < cache->current_size; ++ix) {
            if (cache->entries[ix].sorter < min_sorter) {
                evict_candidate = ix;
                min_sorter = cache->entries[ix].sorter;
            }
        }

        for (int ix = evict_candidate; ix < cache->current_size - 1; ++ix) {
            cache->entries[ix] = cache->entries[ix + 1];
        }
        --cache->current_size;
    }
    cache->entries[cache->current_size].key = key;
    cache->entries[cache->current_size].value = value;
    cache->entries[cache->current_size].sorter = 1; // set freq to 1
    ++cache->current_size;
}