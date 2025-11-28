// Solves using backtracking
#include <iostream>
#include <vector>
using namespace std;

int isSafe(vector<vector<int>> &mat, int row, int col)
{
    // Check this column on upper side
    for (int i = 0; i < row; i++)
    {
        if (mat[i][col])
            return 0;
    }

    // Check upper left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (mat[i][j])
            return 0;
    }

    // Check upper right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < mat.size(); i--, j++)
    {
        if (mat[i][j])
            return 0;
    }
    
    return 1;
}

void placeQueens(int row, vector<vector<int>> &mat, vector<vector<int>> &result)
{
    int n = mat.size();

    if (row == n)
    {
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j])
                    ans.push_back(j + 1);
            }
        }

        result.push_back(ans);
    }

    for (int i = 0; i < n; i++)
    {

        // Check if queen can be placed at ith row
        if (isSafe(mat, row, i))
        {
            mat[row][i] = 1;
            placeQueens(row + 1, mat, result);

            // Backtrack
            mat[row][i] = 0;
        }
    }
}

int main(){
    int n = 12;

    vector<vector<int>> mat(n, vector<int>(n, 0));
    vector<vector<int>> result;

    placeQueens(0, mat, result);

    for(auto ans : result){
        for(auto i : ans ){
            cout << i << " ";
        }
        cout << endl;
    }

    cout << "\n\nTotal Possible arrangements : " << result.size() << "\n" << endl;

    return 0;
}