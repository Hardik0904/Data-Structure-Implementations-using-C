#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stddef.h>
#include <stdbool.h>

typedef struct{
    int *data;
    size_t size;
    size_t capacity;
} DynamicArray;

DynamicArray* da_init(void);
void da_push_back(DynamicArray *da, int val);
bool da_pop_back(DynamicArray* da, int *out_value);
bool da_insert(DynamicArray* da, size_t index, int value);
bool da_remove(DynamicArray* da, size_t index, int* out_value);
void da_print(DynamicArray *da);

#endif