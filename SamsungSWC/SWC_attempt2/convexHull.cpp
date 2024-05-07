#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
};
// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are collinear
// 1 --> Clockwise
// 2 --> Counterclockwise

int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;             // collinear
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

// Prints convex hull of a set of n points.
void convexHull(vector<Point> &points, int n)
{
    // There must be at least 3 points
    if (n < 3)
        return;

    vector<Point> hull; // Initialize Result

    int l = 0; // Find the leftmost point
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;

    int p = l, q;
    do
    {
        hull.push_back(points[p]);
        q = (p + 1) % n;
        for (int i = 0; i < n; i++)
        {
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }
        p = q;

    } while (p != l); 

    for (int i = 0; i < hull.size(); i++)
        cout << "(" << hull[i].x << ", "
             << hull[i].y << ")\n";
}

int main()
{
    int n;
    cin >> n;
    vector<Point> points(n, {0, 0});
    for (int i = 0; i < n; ++i)
    {
        cin >> points[i].x >> points[i].y;
    }
    convexHull(points, n);
    return 0;
}