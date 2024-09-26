struct LRUCache {
    int val;
    int steps;
    int last_used;
};
struct LFUCache {
    int val;
    int steps;
    int frequency;
};

void intitialize() {}
void lookup() {}
void insert(int key, int data) {}
void countOfEntries() {}

void findEntryToEvict() {}
void evict() {}
void update() {}