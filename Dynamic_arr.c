#include<stdio.h>
#include<stdlib.h>

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
    da->capacity;
}
int main(){

}