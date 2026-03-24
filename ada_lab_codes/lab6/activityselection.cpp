#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Activity {
    int start, finish;
};

bool activityCompare(Activity s1, Activity s2) {
    return (s1.finish < s2.finish);
}

void selectActivities(vector<Activity>& acts) {
    sort(acts.begin(), acts.end(), activityCompare);

    int i = 0;
    cout << "(" << acts[i].start << ", " << acts[i].finish << ") ";

    for (int j = 1; j < acts.size(); j++) {
        if (acts[j].start >= acts[i].finish) {
            cout << "(" << acts[j].start << ", " << acts[j].finish << ") ";
            i = j;
        }
    }
    cout << endl;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<Activity> acts(n);
    for (int i = 0; i < n; i++) {
        cin >> acts[i].start >> acts[i].finish;
    }

    auto start = high_resolution_clock::now();

    selectActivities(acts);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Execution Time: " << duration.count() << " microseconds" << endl;

    return 0;
}