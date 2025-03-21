// You are given an array with unique elements of stalls[], which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. Your task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

#include <bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int> &arr, int N, int C, int minAllowedDist){//O(N)
    int cows = 1, lastStallPos = arr[0];

    for(int i=0; i<N; i++){
        if(arr[i]-lastStallPos >= minAllowedDist){
            cows++;
            lastStallPos = arr[i];
        }

        if(cows == C){
            return true;
        }
    }

    return false;
}

int getDistance(vector<int> &arr, int N, int C){
    sort(arr.begin(), arr.end());//O(NlogN)

    int st = 1, end = arr[N-1] - arr[0], ans = -1;
    
    while(st <= end){//O(log(Range) * N)
        int mid = st + (end - st) / 2;

        if(isPossible(arr, N, C, mid)){
            st = mid + 1;
            ans = mid;
        } else {
            end = mid - 1;
        }
    }

    return ans;
}