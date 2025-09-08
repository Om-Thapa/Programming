// Given n friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.(Use recursion to solve this problem)

#include <iostream>
using namespace std;

int friendsPairing(int n) {
    if ( n == 1 || n == 2) {
        return n;
    }
    return friendsPairing(n-1) + (n-1) * friendsPairing(n-2); // n-1 is the number of ways to pair up the remaining friends and friendsPairing(n-2) is the number of ways to pair up the remaining friends  
}