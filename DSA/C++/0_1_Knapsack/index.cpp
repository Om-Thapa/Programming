#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int> &wt, vector<int> &profit){
    int n = profit.size();
    vector<vector<int>> dp( n+1, vector<int>(W+1));

    for(int i=0; i <= n; i++){
        for(int j=0; j <= W; j++ ){

            if( i==0 || j==0 ){
                dp[i][j] = 0;
            } else {
                int pick = 0;

                //If we pick the ith item
                if( wt[i-1] <= j )
                    pick = profit[i - 1] + dp[i-1][ j - wt[i-1] ];

                int notPick = dp[i - 1][j];

                dp[i][j] = max(pick, notPick);
            }
        }
    }

    return dp[n][W];
}

int main() {
    vector<int> profit = {6, 12, 3};
    vector<int> wt = {2, 4, 1};
    int W = 4;

    cout << knapsack(W, wt, profit) << endl;
    return 0;
}