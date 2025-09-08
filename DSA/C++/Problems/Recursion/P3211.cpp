// You are given a positive integer n.
// A binary string x is valid if all substrings of x of length 2 contain at least one "1".
// Return all valid strings with length n, in any order.Use recursion to solve this problem.    

#include <iostream>
#include <vector>
using namespace std;

void validStrings(int n, string ans) {
    if (n == 0) {
        cout << ans << endl;
        return;
    }
    if (ans[ans.length() - 1] != '1') {
        validStrings(n-1, ans + "0");
        validStrings(n-1, ans + "1");
    } else {
        validStrings(n-1, ans + "1");
    }
}