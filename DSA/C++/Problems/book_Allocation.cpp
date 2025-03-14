// You are given an array arr[] of integers, where each element arr[i] represents the number of pages in the ith book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

// Each student receives atleast one book.
// Each student is assigned a contiguous sequence of books.
// No book is assigned to more than one student.
// The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

// Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).
//Geeks For Geeks
//Time Complexity : O(n*logN)

#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<int> &arr, int n, int m, int maxAllowedPages){
    int students=1, pages=0;

    //O(n)
    for(int i=0; i<n; i++){
        if(arr[i] > maxAllowedPages) return false;

        if(pages + arr[i] <= maxAllowedPages){
            pages += arr[i];
        } else {
            students++;
            pages = arr[i];
        }
    }

    return students > m ? false : true;
}

int allocateBooks(vector<int> &arr, int n, int m){
    if(m > n) return -1;

    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }

    int ans = -1;
    int st=0, end=sum; //range of possible ans

    //O(logN)
    while(st <= end){
        int mid = st + (end - st)/2;

        if(isValid(arr, n, m, mid)){//left
            ans =mid;
            end = mid - 1;
        } else {//right
            st = mid + 1;
        }
    }

    return ans;
}