#include <stdio.h>
#include <stdlib.h>
#include "lru_cache.h"

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache *cache = (LRUCache *)malloc(sizeof(LRUCache));
    cache->capacity = capacity;
    cache->size = 0;
    cache->head = NULL;
    cache->tail = NULL;
    cache->hashTable = (CacheNode **)calloc(capacity, sizeof(CacheNode *));
    return cache;
}

void moveToHead(LRUCache *cache, CacheNode *node) {
    if (cache->head == node) return;

    // removes the node from its current position
    if (node->prev) node->prev->next = node->next;
    if (node->next) node->next->prev = node->prev;
    if (cache->tail == node) cache->tail = node->prev;

    // move node to the head
    node->next = cache->head;
    node->prev = NULL;
    if (cache->head) cache->head->prev = node;
    cache->head = node;
    if (!cache->tail) cache->tail = node;
}

void removeTail(LRUCache *cache) {
    if (!cache->tail) return;

    CacheNode *node = cache->tail;
    if (node->prev) node->prev->next = NULL;
    cache->tail = node->prev;
    if (cache->head == node) cache->head = NULL;

    // updates the hash table to remove the node
    cache->hashTable[node->key % cache->capacity] = NULL;
    free(node);
    cache->size--;
}

int lRUCacheGet(LRUCache *cache, int key) {
    CacheNode *node = cache->hashTable[key % cache->capacity];
    while (node) {
        if (node->key == key) {
            moveToHead(cache, node);
            return node->value;
        }
        node = node->next;
    }
    return -1;
}

void lRUCachePut(LRUCache *cache, int key, int value) {
    CacheNode *node = cache->hashTable[key % cache->capacity];
    while (node) {
        if (node->key == key) {
            node->value = value;
            moveToHead(cache, node);
            return;
        }
        node = node->next;
    }

    if (cache->size == cache->capacity) {
        removeTail(cache);
    }

    node = (CacheNode *)malloc(sizeof(CacheNode));
    node->key = key;
    node->value = value;
    node->prev = NULL;
    node->next = cache->hashTable[key % cache->capacity];
    if (node->next) node->next->prev = node;
    cache->hashTable[key % cache->capacity] = node;
    moveToHead(cache, node);
    cache->size++;
}

void lRUCacheFree(LRUCache *cache) {
    CacheNode *node = cache->head;
    while (node) {
        CacheNode *next = node->next;
        free(node);
        node = next;
    }
    free(cache->hashTable);
    free(cache);
}