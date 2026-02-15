#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    int r1, c1, r2, c2;
    if (!(cin >> r1 >> c1 >> r2 >> c2)) return 0;

    if (c1 != r2) {
        cout << "Matrix multiplication not possible" << endl;
        return 0;
    }

    vector<vector<int>> a(r1, vector<int>(c1));
    vector<vector<int>> b(r2, vector<int>(c2));
    vector<vector<int>> res(r1, vector<int>(c2, 0));

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> a[i][j];

    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> b[i][j];

    auto start = high_resolution_clock::now();

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Execution Time: " << duration.count() << " microseconds" << endl;

    return 0;
}