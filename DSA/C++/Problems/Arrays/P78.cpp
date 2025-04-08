#include<iostream>
#include<vector>
using namespace std;

void getAllSubsets(vector<int>& arr, vector<int>& ans, int i, vector<vector<int>>& allSubsets){
    if(i == arr.size()){
        allSubsets.push_back({ans});
        return;
    }
        
    ans.push_back(arr[i]);
    getAllSubsets(arr, ans, i+1, allSubsets);
    ans.pop_back();
    getAllSubsets(arr, ans, i+1, allSubsets);
}

vector<vector<int>> subsets(vector<int>& nums){
    vector<vector<int>> allSubsets;
    vector<int> ans;

    getAllSubsets(nums, ans, 0, allSubsets);
    return allSubsets;
}