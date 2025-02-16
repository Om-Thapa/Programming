//Search in a Rotated sorted array
#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> arr, int tar){
    int st = 0, end = arr.size() - 1;
    
    while( st <= end ){
        int mid = st + ( end - st ) /2;

        if( tar == arr[mid] ){
            return mid;
        }

        if ( arr[st] <= arr[mid] ){
            if( arr[st] <= tar && tar <= arr[mid] ){
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        } else {
            if( arr[mid] <= tar && tar <= arr[end] ){
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }

    return -1;
}