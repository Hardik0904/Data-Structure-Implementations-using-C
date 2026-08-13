#include<stdio.h>
#include<stdlib.h>
#define Initial_Capacity 4

typedef struct{
    int *data;
    size_t size;
    size_t capacity;
} DynamicArray;

//Initialize the dynamic array
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
    int* new_data=(int*)realloc(da->data, new_capacity*sizeof(int));
    if(!new_data){
        perror("failed to reallocate new buffer");
        return;
    }
    da->data = new_data;
    da->capacity = new_capacity;
}

//push item to back 
void da_push_back(DynamicArray *da, int val){
    if(da->size == da->capacity){
        da_resize(da, da->capacity*2);
    }
    da->data[da->size++]=val;;
}


//print arary elements
void da_print(DynamicArray *da){
    printf("[");
    for(int i=0; i<da->size; i++){
        printf("%d", da->data[i]);
        if(i < da->size - 1)
            printf(", ");
    }
    printf("]");
}
int main(){
    DynamicArray *array = da_init();
    da_push_back(array, 4);
    da_push_back(array, 7);
    da_push_back(array, 45);
    da_push_back(array, 9);
    da_print(array);
}