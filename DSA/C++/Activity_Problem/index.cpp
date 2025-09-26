#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to store activity info
struct Activity {
    int start, finish;
};

// Comparator to sort activities by finish time
bool activityCompare(const Activity &a1, const Activity &a2) {
    return a1.finish < a2.finish;
}

// Function to find max number of activities
int maxActivities(const vector<int> &start, const vector<int> &finish) {
    int n = start.size();
    vector<Activity> activities(n);

    for (int i = 0; i < n; ++i) {
        activities[i].start = start[i];
        activities[i].finish = finish[i];
    }

    // Sort activities by finish time
    sort(activities.begin(), activities.end(), activityCompare);

    int count = 1; // First activity always selected
    int lastFinish = activities[0].finish;

    for (int i = 1; i < n; ++i) {
        if (activities[i].start >= lastFinish) {
            ++count;
            lastFinish = activities[i].finish;
        }
    }
    return count;
}

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> finish = {2, 4, 6, 7, 9, 9};

    int result = maxActivities(start, finish);
    cout << "Maximum number of activities: " << result << endl;
    return 0;
}