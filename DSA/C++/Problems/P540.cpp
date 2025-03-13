// You are given a sorted array consisting of only integers where 
// every element appears exactly twice, except for one element which appears exactly once.
// Return the single element that appears only once.
//Time : O(logn)

#include<iostream>
#include<vector>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int st = 0, end = nums.size()-1;

    if(nums.size() == 1) return nums[end];

    while( st <= end ){
        int mid = st + (end - st)/2;

        if(mid == 0 && nums[mid]!=nums[mid+1]) return nums[mid];
        else if(mid == nums.size()-1 && nums[mid]!=nums[mid-1]) return nums[mid];
        else if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]) return nums[mid];

        if(mid%2 == 0){
            if(nums[mid] == nums[mid+1]){
                st = mid + 1;
            }else{
                end = mid - 1;
            }
        }else{
            if(nums[mid] == nums[mid-1]){
                st = mid + 1;
            }else{
                end = mid - 1;
            }
        }
    }

    return -1;
}