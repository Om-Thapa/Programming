// Given an array arr[] and k, where the array represents the boards and each element of the given array represents the length of each board. k numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint. The task is to find the minimum time to get this job done by painting all the boards under the constraint that any painter will only paint the continuous sections of boards. say board [2, 3, 4] or only board [1] or nothing but not board [2, 4, 5].

#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int> &arr, int n, int m, int maxAllowed){
    int curSum = 0, painter = 1, i;

    for(i=0; i<n; i++){
        // if(arr[i] > maxAllowed) return false; No Need

        if(curSum + arr[i] <= maxAllowed){
            curSum += arr[i];
        } else {
            painter++;
            curSum = arr[i];
        }
    }

    return painter <= m;
}

int minTimeToPaint(vector<int> &arr, int n, int m){
    if(m > n) return -1;

    int totalLength = 0, st = INT32_MIN;
    for(int i=0; i < n; i++){
        st = max(st, arr[i]);
        totalLength += arr[i];
    }

    int minTime = -1;
    int end = totalLength;

    while(st <= end){
        int mid = st + (end - st)/2;

        if(isPossible(arr, n, m, mid)){
            minTime = mid;
            end = mid - 1;
        } else {
            st = mid + 1;
        }
    }

    return minTime;
}