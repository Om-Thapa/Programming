#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;

        // Create a set to store the elements of the grid
        unordered_set<int> s;
        int n = grid.size();
        int a, b;

        int expSum = 0, actSum = 0;

        //Find the missing value and calculate the sum of the elements
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                actSum += grid[i][j];

                if(s.find(grid[i][j]) != s.end()){
                    a = grid[i][j];
                    ans.push_back(a);
                }
                s.insert(grid[i][j]);
            }
        }

        // Calculate the expected sum of the elements
        expSum = (n*n) * (n*n + 1) / 2;
        b = expSum - actSum + a; 
        ans.push_back(b);

        return ans;
    }
};