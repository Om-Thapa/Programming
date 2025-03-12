//Given a Mountain array
//Eg 0,3,5,9,6,4,3 where 9 is the peak of the mountain array
//Find the peak element with Time : O(log n)
#include <iostream>
#include<vector>
using namespace std;

int peakIndex(vector<int>& A){
    int st = 1, end = A.size() - 2;

    while(st <= end){
        int mid = st + (end - st)/2;

        if(A[mid-1] < A[mid] && A[mid] > A[mid+1]){
            return mid;
        } else if(A[mid-1] < A[mid]){
            st = mid + 1;
        }else {
            end = mid -1;
        }
    }

    return -1;
}