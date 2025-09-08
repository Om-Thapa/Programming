// Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string removeDuplicateLetters(string s, string ans, int idx, vector<int> &freq, int map[26]){
    if(idx == s.length()){
        return ans;
    }
    if(map[s[idx] - 'a'] == 1){
        return removeDuplicateLetters(s, ans, idx + 1, freq, map);
    } else {
        map[s[idx] - 'a'] = 1;
        return removeDuplicateLetters(s, ans + s[idx], idx + 1, freq, map);
    }
}