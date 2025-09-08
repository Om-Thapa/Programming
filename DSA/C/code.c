#include<stdio.h>

int binarySearch(int arr[], int size, int target){
    int l = 0, r = size - 1;
    while(l <= r){
        int mid = (l + r) / 2;
        if( arr[mid] == target) return mid;

        if( arr[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int binarySearchRecursive(int arr[], int l, int r, int target){
    if(l > r) return -1;
    int mid = (l + r) / 2;
    if(arr[mid] == target) return mid;
    if(arr[mid] < target) return binarySearchRecursive(arr, mid + 1, r, target);
    else return binarySearchRecursive(arr, l, mid - 1, target);
}

int main(){
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // printf("Enter the array: ");
    // for(int i = 0; i < 10; i++){
    //     scanf("%d", &arr[i]);
    // }
    int target;
    printf("Enter the target: ");
    scanf("%d", &target);
    int result = binarySearch(arr, 10, target);
    printf("The target is at index: %d\n", result);
    int result2 = binarySearchRecursive(arr, 0, 9, target);
    printf("The target is at index: %d\n", result2);
    return 0;
}