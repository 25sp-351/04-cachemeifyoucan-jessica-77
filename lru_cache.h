#ifndef LRU_CACHE_H
#define LRU_CACHE_H

typedef struct CacheNode {
    int key;
    int value;
    struct CacheNode *prev;
    struct CacheNode *next;
} CacheNode;

typedef struct {
    int capacity;
    int size;
    CacheNode *head;
    CacheNode *tail;
    CacheNode **hashTable;
} LRUCache;

LRUCache* lRUCacheCreate(int capacity);

int lRUCacheGet(LRUCache *cache, int key);

void lRUCachePut(LRUCache *cache, int key, int value);

void lRUCacheFree(LRUCache *cache);

#endif // LRU_CACHE_H