#include<iostream>
#include<vector>
using namespace std;

int findDuplicate(vector<int>& arr){
    int slow = arr[0], fast = arr[0];

    do{
        slow = arr[slow];// move slow by 1 step
        fast = arr[arr[fast]];// move fast by 2 steps
        // if they meet, there is a cycle
    }while(slow != fast);

    slow = arr[0];

    while(slow != fast){
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
}