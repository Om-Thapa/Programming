//Implement matrix mutliplication ( Brute Force )

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    int m = A.size(), n = A[0].size(), p = B[0].size();
    if(n != B.size()){ 
        printf("Invalid matrices");
        return {};
    }
    
    vector<vector<int>> ans(m, vector<int>(p, 0));

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < p; j++) {
            for(int k = 0; k < n; k++) {
                ans[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return ans;
}