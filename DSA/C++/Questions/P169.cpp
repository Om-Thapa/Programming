//Find majority element(occuring more than equal to half of the array) in an array
#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& nums){
    int freq=0,ans=0;

    for(int i=0;i<nums.size();i++){
        if(freq==0)
        ans=nums[i];
        if(ans==nums[i]){
            freq++;
        }else{
            freq--;
        }
    }
    return ans;
}

int main(){
    vector<int> vec={1,0,0,2,2,1,1,1,5,1};
    cout << "Majority Element : "<< majorityElement(vec)<<endl;
    return 0;
}