//Finding Maximun Sub-Array Sum
#include<iostream>
#include<vector>
using namespace std;

//Printing all subarrays
void printAll(vector<int>& arr){
    int n=arr.size();
    for(int st=0;st<n;st++){
        for(int end=st;end <n;end++){
            for(int i=st;i<=end;i++)
            cout << arr[i];
            cout <<" ";
        }
        cout << endl;
    }
}

//Using Kadane's Algorithm
int findSum(vector<int>& arr){
    int n=arr.size();
    int currSum=0,maxSum=INT16_MIN;
    for(int i=0;i<n;i++){
        currSum+=arr[i];
        maxSum=max(currSum,maxSum);
        if(currSum<0)
        currSum=0;
    }
    return maxSum;
}

int main(){
    vector<int> arr={1,2,3,4,5};
    printAll(arr);
    cout<< "Max Sub-Array Sum = "<< findSum(arr);
    return 0;
}