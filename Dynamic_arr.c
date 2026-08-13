#include<stdio.h>
#include<stdlib.h>
#define Initial_Capacity 4

typedef struct{
    int *data;
    size_t size;
    size_t capacity;
} DynamicArray;

//Initialize the ynamic array
DynamicArray* da_init(void){
    DynamicArray *da = (DynamicArray *)malloc(sizeof(DynamicArray));
    if(!da){
        perror("failed to allocate DynamicArray struct");
        exit(EXIT_FAILURE);
    }
    da->size = 0;
    da->capacity = Initial_Capacity;
    da->data=(int*)malloc(da->capacity*sizeof(int));
    if(!da->data){
        perror("Failed to allocate dynamic array buffer");
        free(da);
        exit(EXIT_FAILURE);
    }
    return da;
}

//internal fuction to resize the capacity of array
static void da_resize(DynamicArray* da, size_t new_capacity){
    int* new_data=(int*)realloc(new_capacity*sizeof(int));
    if(!new_data){
        perror("failed to reallocate new buffer");
        return;
    }
    da->data = new_data;
    da->capacity = new_capacity;
}

void da_push_back(DynamicArray *da, int val){
    if(da->size == da->capacity){
        da_resize(da, da->capacity*2);
        da->data[da->size++]=val;
    }
}


int main(){

}