// Quick Sort
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

int partition(vector<int> &arr, int si, int ei){
    int pivot = arr[ei], i = si - 1;
    for(int j = si; j < ei; j++){ // j < ei, not j <= ei
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[ei]);
    return i+1;
}

void quickSort(vector<int> &arr, int si, int ei){
    if(si >= ei) return;
    int p = partition(arr, si, ei);
    quickSort(arr, si, p-1);
    quickSort(arr, p+1, ei);
}

int main(){
    int n = 20;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        arr.push_back(rand() % 100 + 1);
    }

    cout << "Array before sorting: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n" << endl;

    quickSort(arr, 0, n-1);

    cout << "\nArray after sorting: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}