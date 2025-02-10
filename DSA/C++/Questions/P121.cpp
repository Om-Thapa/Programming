//Buy or sell stocks
//Given array price where price[i] is price of given stock at ith day
//Buying and selling days should be different such that profit is max
#include<iostream>
#include<vector>
using namespace std;


int maxProfit(vector<int>& price){
    int maxProfit = 0, bestBuy = price[0];

    for( int i=1 ; i<price.size(); i++ ){
        if( price[i] > bestBuy ){
            maxProfit=max(maxProfit, price[i]-bestBuy);
        }
        bestBuy=min(bestBuy, price[i]);
    }

    return maxProfit;
}