//Two Sum Problem

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int>& arr, int tar){
    unordered_map<int, int> m;
    vector<int> ans;

    for(int i=0; i<arr.size(); i++){
        
        if(m.find(tar-arr[i]) != m.end()){
            ans.push_back(m[tar-arr[i]]);
            ans.push_back(i);
            return ans;
        }

        m[arr[i]] = i;
    }

    return ans;
}