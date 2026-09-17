#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct{
    int a[100];
    size_t size;
}PQ;

int parent(int index){
    return (index-1)/2;
}

int rightchild(int index){
    return index*2+2;
}

int leftchild(int index){
    return index*2+1;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shiftup(PQ* heap, int index){
    if(index==0) return;
    if(heap->a[parent(index)]<heap->a[index]){
        swap(&heap->a[parent(index)], &heap->a[index]);
    }
    index=parent(index);
    shiftup(heap, index);
}

PQ* initialize(int arr[], int size){
    if(size>100){
        perror("size exceeded");
        exit(EXIT_FAILURE);
    }
    PQ* heap=(PQ*)malloc(sizeof(PQ));
    heap->size=size;
    for(int i=0; i<size; i++){
        heap->a[i]=arr[i];
        if(i!=0) shiftup(heap, i);
    }

    return heap;
}

int maxpriority(PQ* heap){
    return heap->a[0];
}

void increasekey(PQ* heap, int index, int k){
    heap->a[index]=k;
    shiftup(heap, index);
}

void insert(PQ* heap, int value){
    heap->a[heap->size]=INT_MIN;
    increasekey(heap, heap->size, value);
    heap->size++;
}

int extractmax(PQ* heap){
    
}

int main(){
    int size;
    printf("Give size of array: \n");
    scanf("%d", &size);
    int arr[size];
    for(int i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }
    PQ* heap=initialize(arr, size);
    insert(heap, 8);
    insert(heap, 42);
    printf("%d", maxpriority(heap));
    return 0;
}