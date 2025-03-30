#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& mat){//Time : O(m*n) , Space : O(1)
    int m = mat.size() , n = mat[0].size();
    int srow = 0 , scol = 0 , erow = m-1 , ecol = n-1;
    vector<int> ans;

    while(srow <= erow && scol <= ecol){
        //Top row
        for(int i = scol ; i <= ecol ; i++){
            ans.push_back(mat[srow][i]);
        }
        srow++;

        //Right column
        for(int i = srow ; i <= erow ; i++){
            ans.push_back(mat[i][ecol]);
        }
        ecol--;

        //Bottom row
        for(int i = ecol ; i >= scol ; i--){
            if(srow == erow) break;
            ans.push_back(mat[erow][i]);
        }
        erow--;

        //Left column
        for(int i = erow ; i >= srow ; i--){
            if(scol == ecol) break;
            ans.push_back(mat[i][scol]);
        }
        scol++;
    }
}