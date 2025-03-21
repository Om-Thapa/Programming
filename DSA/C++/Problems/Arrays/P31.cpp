// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

// For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
// The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int pivot = -1, n = nums.size();
    
    for(int i=n-2; i>=0; i--){
        if(nums[i]<nums[i+1]){
            pivot = i;
            break;
        }
    }

    if(pivot == -1){
        reverse(nums.begin(), nums.end());
        return;
    }

    for(int i=n-1; i>pivot; i--){
        if(nums[i]>nums[pivot]){
            swap(nums[i],nums[pivot]);
            break;
        }
    }

    int i = pivot+1, j = n-1;
    while(i <= j){
        swap(nums[i++], nums[j--]);
    }
}