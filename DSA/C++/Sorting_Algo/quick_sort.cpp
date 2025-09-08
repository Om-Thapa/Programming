// Quick Sort
#include <iostream>
#include <algorithm>
using namespace std;

int partition(int arr[], int si, int ei){
    int pivot = arr[si], i = si - 1;
    for(int j = si; j <= ei; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[si]);
    return i+1;
}

void quickSort(int arr[], int si, int ei){
    if(si >= ei) return;
    int p = partition(arr, si, ei);
    quickSort(arr, si, p-1);
    quickSort(arr, p+1, ei);
}