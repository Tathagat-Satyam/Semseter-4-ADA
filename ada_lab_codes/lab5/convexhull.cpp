#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Point {
    int x, y;
};

Point p0;

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

int distSq(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

bool compare(Point p1, Point p2) {
    int o = orientation(p0, p1, p2);
    if (o == 0)
        return distSq(p0, p2) >= distSq(p0, p1);
    return (o == 2);
}

Point nextToTop(stack<Point> &S) {
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}

void convexHull(Point points[], int n) {
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++) {
        int y = points[i].y;
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
            ymin = points[i].y, min = i;
    }

    swap(points[0], points[min]);
    p0 = points[0];
    sort(&points[1], points + n, compare);

    int m = 1;
    for (int i = 1; i < n; i++) {
        while (i < n - 1 && orientation(p0, points[i], points[i + 1]) == 0)
            i++;
        points[m] = points[i];
        m++;
    }

    if (m < 3) return;

    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    for (int i = 3; i < m; i++) {
        while (S.size() > 1 && orientation(nextToTop(S), S.top(), points[i]) != 2)
            S.pop();
        S.push(points[i]);
    }

    while (!S.empty()) {
        Point p = S.top();
        cout << "(" << p.x << ", " << p.y << ")" << endl;
        S.pop();
    }
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    Point points[n];
    for(int i = 0; i < n; i++) cin >> points[i].x >> points[i].y;

    auto start = high_resolution_clock::now();

    convexHull(points, n);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Execution Time: " << duration.count() << " microseconds" << endl;

    return 0;
}