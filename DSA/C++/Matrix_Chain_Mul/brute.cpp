#include <iostream>
#include <vector>
using namespace std;

int minMulReq(vector<int> &arr, int i, int j){
    if( i+1 == j) return 0;
    
    int res = INT32_MAX;

    for(int k=i+1; k<j; k++){
        int curr = minMulReq(arr, i, k) + minMulReq(arr, k, j) + arr[i]*arr[j]*arr[k];

        res = min(curr, res);
    }

    return res;
}