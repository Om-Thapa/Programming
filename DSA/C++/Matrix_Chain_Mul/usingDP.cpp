// C++ code to implement the
// matrix chain multiplication using memoization
#include <bits/stdc++.h>
using namespace std;

int minMultRec(vector<int> &arr, int i, int j, vector<vector<int>> &memo)
{

    // If there is only one matrix
    if (i + 1 == j)
        return 0;

    // Check if the result is already
    // computed
    if (memo[i][j] != -1)
        return memo[i][j];

    int res = INT_MAX;

    // Place the first bracket at different positions or k and
    // for every placed first bracket, recursively compute
    // minimum cost for remaining brackets (or subproblems)
    for (int k = i + 1; k < j; k++)
    {
        int curr = minMultRec(arr, i, k, memo) + minMultRec(arr, k, j, memo) + arr[i] * arr[k] * arr[j];

        res = min(curr, res);
    }

    // Store the result in memo table
    memo[i][j] = res;
    return res;
}

int matrixMultiplication(vector<int> &arr)
{

    int n = arr.size();
    vector<vector<int>> memo(n, vector<int>(n, -1));
    return minMultRec(arr, 0, n - 1, memo);
}

int main()
{
    vector<int> arr = {2, 1, 3, 4};
    int res = matrixMultiplication(arr);
    cout << res << endl;
    return 0;
}