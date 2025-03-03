#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CACHE_SIZE 10

typedef struct {
    int valid;
    int tag;
    int data;
} CacheLine;

CacheLine cache[CACHE_SIZE];

void init_cache() {
    for (int i = 0; i < CACHE_SIZE; i++) {
        cache[i].valid = 0;
    }
    srand(time(NULL));
}

int find_in_cache(int tag) {
    for (int i = 0; i < CACHE_SIZE; i++) {
        if (cache[i].valid && cache[i].tag == tag) {
            return cache[i].data;
        }
    }
    return -1;
}

void insert_into_cache(int tag, int data) {
    int index = rand() % CACHE_SIZE;
    cache[index].valid = 1;
    cache[index].tag = tag;
    cache[index].data = data;
}

void print_cache() {
    for (int i = 0; i < CACHE_SIZE; i++) {
        if (cache[i].valid) {
            printf("Cache Line %d: Tag = %d, Data = %d\n", i, cache[i].tag, cache[i].data);
        } else {
            printf("Cache Line %d: Invalid\n", i);
        }
    }
}