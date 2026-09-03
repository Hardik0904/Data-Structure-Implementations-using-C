#include<stdio.h>
#include<stdlib.h>
void swap(int* a, int* b){
    int temp= *a;
    *a=*b;
    *b=temp;
}

void swap_float(float* a, float* b){
    float temp = *a;
    *a = *b;
    *b = temp;
}
void bubble_sort(int arr[], int n){
    for(int i=n-1; i>=0; i--){
        int cnt=0;
        for(int j=0; j<i; j++){
            if(arr[j]>arr[j+1]){
            swap(&arr[j], &arr[j+1]);
            cnt++;
            }
        }
        if(cnt==0) return;
    }
}

void selection_sort(int arr[], int n){
    
    for(int i=0; i<n-1; i++){
        int mini=i;
        for(int j=i; j<n-1; j++){
            if(arr[j+1]<arr[mini])
            mini=j+1;
        }
        swap(&arr[mini], &arr[i]);
    }
}

void insertion_sort(float arr[], int n){
    for(int i=1; i<n; i++){
        for(int j=i; j>0; j--){
            if(arr[j]<arr[j-1])
            swap_float(&arr[j], &arr[j-1]);
            else break;
        }
    }
}

int partition(int arr[], int left, int right){
    int i=left;
    int pivot=right;
    while(arr[i]<arr[pivot]){
        i++;
    }
    for(int j=i+1; j<right; j++){
        if(arr[j]<arr[pivot]){
            swap(&arr[j], &arr[i]);
            i++;
        }
    }
    swap(&arr[i], &arr[pivot]);
    return i;
}
void quick_sort(int arr[], int left, int right){
    if(left>=right) return;
    int mid;
    mid=partition(arr, left, right);
    quick_sort(arr, left, mid-1);
    quick_sort(arr, mid+1, right);
}

void merge(int arr[], int left, int mid, int right){
    int temp[right-left+1];
    int k=0;
    int i=left, j=mid+1;
    while(i<=mid && j<=right){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else temp[k++]=arr[j++];
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=right){
        temp[k++]=arr[j++];
    }
    k=0;
    for(int i=left; i<=right; i++){
        arr[i]=temp[k++];
    }
}
void merge_sort(int arr[], int left, int right){
    if(left>=right) return;
    int mid=(left+right)/2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid+1, right);
    merge(arr, left, mid, right);
}

void shell_sort(int arr[], int n){
    for(int gap=n/2; gap>=1; gap/=2){
        for(int j=gap; j<n; j++){
            for(int i=j-gap; i>=0; i=i-gap){
                if(arr[i+gap]>arr[i])
                break;
                else swap(&arr[i+gap], &arr[i]);
            }
        }
    }
}

void bucket_sort(float arr[], int n){
    float bucket[n][n];
    int count[n];
    for(int i=0; i<n; i++){
        count[i]=0;
    }

    //inserting in the bucket
    for(int i=0; i<n; i++){
        int index=n*arr[i];
        bucket[index][count[index]++]=arr[i];
    }

    //sorting using insertion sort
    for(int i=0; i<n; i++){
        insertion_sort(bucket[i], count[i]);
    }

    int k=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<count[i]; j++){
            arr[k++]=bucket[i][j];
        }
    }
}
int main(){
    float arr[]={0.4, 0.7, 0.8, 0.7, 0.110, 0.1, 0.3, 0.2, 0.18, 0.20, 0.5};
    bucket_sort(arr, 11);
    for(int i=0; i<11; i++){
        printf("%.2f ", arr[i]);
    }
}