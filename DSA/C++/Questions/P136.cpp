//Find unique number in an array(vector) of duplicate numbers.
//Use XOR gate
#include<iostream>
#include<vector>
using namespace std;
int singleNumber(vector<int>& nums){
    int ans=0;
    for(int val : nums)
    ans^=val;
    return ans;
}
int main(){
    vector<int> vec={2,-1,2,4,-1};
    int n=singleNumber(vec);
    cout << "Unique Number is : " << n << "\n";
    return 0;
}