#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void getSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allSubsets) {
    if (i == nums.size()) {
        allSubsets.push_back({ans});
        return;
    }

    // Exclude the current element
    ans.push_back(nums[i]);
    getSubsets(nums, ans, i + 1, allSubsets);

    ans.pop_back();

    // Include the current element
    while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
        i++;
    }
    getSubsets(nums, ans, i + 1, allSubsets);
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> allSubsets;
    vector<int> ans;

    getSubsets(nums, ans, 0, allSubsets);

    return allSubsets;