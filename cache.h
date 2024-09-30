typedef struct col_item {
    int key;
    int value;
    int sorter;
} col_item;
typedef struct Cache {
    col_item* entries;      
    int size;               
    char* mode;               
    int current_size;       
    unsigned long long timestamp;
} Cache;

void initialize(Cache* cache, int size);
int lookupLRU(Cache* cache, int key);
int lookupLFU(Cache* cache, int key);
void insertLRU(Cache* cache, int key, int value);
void insertLFU(Cache* cache, int key, int value);