#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void addSeedData(int n){
    FILE *fptr;
    fptr = fopen("number.txt", "w");
    if (!fptr) return;

    srand(time(NULL)); // Seed random number generator

    for(int i=0; i<n; i++){
        fprintf(fptr, "%d\n", (rand()%10000) + 1);
    }
    fclose(fptr);
}

void insertion_sort(int *arr, int n){
    for(int i = 1; i < n; i++){
        int key = arr[i], j = i-1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void bubble_sort(int *arr, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selection_sort(int *arr, int n){
    for(int i=0; i<n-1; i++){
        int min_idx = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[min_idx])
                min_idx = j;
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main(){
    int n = 100000;
    clock_t st_time, end_time; 
    addSeedData(n);
    FILE *fptr = fopen("number.txt", "r");
    
    int arr1[n], arr2[n], arr3[n], s = 0;
    while(s < n && fscanf(fptr, "%d", &arr1[s]) == 1){
        s++;
    }
    fclose(fptr);

    for(int i=0; i<s; i++){
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
    
    st_time = clock();
    bubble_sort(arr1, s);
    end_time = clock();
    double difference_in_seconds = (double)(end_time - st_time) / CLOCKS_PER_SEC;
    printf("%f second in Bubble sort\n", difference_in_seconds);
    
    st_time = clock();
    insertion_sort(arr2, s);
    end_time = clock();
    difference_in_seconds = (double)(end_time - st_time) / CLOCKS_PER_SEC;
    printf("%f second in Insertion sort\n", difference_in_seconds);
    
    st_time = clock();
    selection_sort(arr3, s);
    end_time = clock();
    difference_in_seconds = (double)(end_time - st_time) / CLOCKS_PER_SEC;
    printf("%f second in Selection sort\n", difference_in_seconds);

    fptr = fopen("number.txt", "w");
    for(int i = 0; i < s; i++)
        fprintf(fptr, "%d\n", arr1[i]);
    fclose(fptr);

    return 0;
}