//Container with Max Water
#include<iostream>
#include<vector>
using namespace std;

int maxArea(vector<int>& heigth ){
    int maxWater=0; //ans
    int lp=0,rp=heigth.size()-1;

    while (lp < rp) {
        int w = rp - lp;
        int ht = min(heigth[rp],heigth[lp]);
        int currWater = w * ht;
        maxWater=max( maxWater, currWater );

        heigth[lp] > heigth[rp] ? rp-- : lp++;
    }
    
    return maxWater;
}