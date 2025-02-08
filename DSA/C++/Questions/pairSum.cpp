//Find index of pairs in an sorted array whose sum is a given desired number.
#include<iostream>
#include<vector>
using namespace std;

vector<int> pairSum(vector<int> nums,int target){
    vector<int> ans;
    int n=nums.size();

    //Brute Force
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         if(nums[i]+nums[j]==target){
    //             ans.push_back(i);
    //             ans.push_back(j);
    //             return ans;
    //         }
    //     }
    // }

    //Using two pointer approach
    int i=0,j=n-1;
    while (i<j){
        int sum=nums[i]+nums[j];
        if(sum>target)
        j--;
        else if(sum<target)
        i++;
        else{
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
}
int main(){
    vector<int> vec={2,4,7,10,11,18};
    int target=12;
    vector<int> ans=pairSum(vec,target);
    cout<<ans[0]<<" , "<<ans[1]<<endl;
    return 0;
}