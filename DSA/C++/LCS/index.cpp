#include <bits/stdc++.h>
using namespace std;

int lcs(string &s1, string &s2, vector<vector<int>> &dp){
    int m = s1.length();
    int n = s2.length();
    
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
                continue;
            }

            if( s1[i-1] == s2[j-1] ){
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[m][n];
}
string sequence_included(string &s1, string &s2, vector<vector<int>> &dp){
    int i = s1.length();
    int j = s2.length();
    string lcs_rev;
    
    while (i > 0 && j > 0) {
        if (s1[i-1] == s2[j-1]) {
            lcs_rev.push_back(s1[i-1]);
            --i; --j;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            --i;
        } else {
            --j;
        }
    }
    reverse(lcs_rev.begin(), lcs_rev.end());
    return lcs_rev;
}

int main() {
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";

    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp (m + 1, vector<int>(n + 1, -1));

    cout << "Length of longest sub-sequence = " << lcs(s1, s2, dp) << endl;
    cout << "LCS: " << sequence_included(s1, s2, dp) << endl;
    return 0;
}