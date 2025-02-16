#include<iostream>
#include<vector>
using namespace std;

//Using Iterations
int binSearch(vector<int> arr, int tar){
    int st=0, end=arr.size()-1;

    while( st <= end){
        int mid = st + (end - st)/2;

        if(tar > arr[mid]) {
            st = mid + 1;
        } else if(tar < arr[mid]) {
            end = mid - 1;
        } else {
            return mid;
        }
    }

    return -1;
}

//Using Recursions
int binSearch(vector<int> arr, int tar, int st, int end) {
    if( st <= end ){
        int mid = st + (end - st) /2;

        if(tar > arr[mid]) {
            return binSearch(arr, tar, mid + 1, end);
        }else if(tar < arr[mid] ){
            return binSearch( arr, tar, st, mid - 1);
        } else {
            return mid;
        }
    }

    return -1;
}

int main(){
    vector<int> arr1 = {-1, 0, 3, 4, 5, 9, 12};
    int tar1 = 12;

    cout << binSearch(arr1, tar1) << endl;

    vector<int> arr2 = {-1, 0, 3, 4, 5, 6, 9, 12, 15};
    int tar2 = 6;

    cout << binSearch( arr2, tar2, 0, arr2.size()-1) << endl;
}