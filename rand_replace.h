#ifndef RANDOM_CACHE_H
#define RANDOM_CACHE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CACHE_SIZE 10

typedef struct {
    int valid;
    int tag;
    int data;
} CacheLine;

void init_cache();
int find_in_cache(int tag);
void insert_into_cache(int tag, int data);
void print_cache();

#endif // RANDOM_CACHE_H