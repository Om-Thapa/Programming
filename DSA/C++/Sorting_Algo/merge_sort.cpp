#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void merge(vector<int>& arr, int si, int ei, int mid) {
    int i = si;
    int j = mid + 1;
    vector<int> temp;

    while (i <= mid && j <= ei) {
        if (arr[i] < arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= ei) temp.push_back(arr[j++]);

    for (int k = si; k <= ei; k++)
        arr[k] = temp[k - si];
}

void merge_sort(vector<int>& arr, int si, int ei) {
    if (si >= ei) return;

    int mid = si + (ei - si) / 2;
    merge_sort(arr, si, mid);
    merge_sort(arr, mid + 1, ei);
    merge(arr, si, ei, mid);
}

int main() {
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
    
    merge_sort(arr, 0, arr.size() - 1);
    
    cout << "\nArray after sorting: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
