// /*
// There are N fishing spots and 3 gates. At each gate there are some fishermen waiting to reach the nearest unoccupied fishing spot. (Total no of fisherman <=N)

// Distance between consecutive spots = distance between gate and nearest spot = 1 m

// Only 1 gate can be opened(other gates after that gate) at a time and all fishermen of that gate must occupy the spots before the next gate is opened.

// Distance is calculated as gate to nearest spot + nearest spot to closest vacant spot. Find the total sum of minimum distances need to walk for all the fishermen.

// image

// 5
// 10
// 4 5
// 6 2
// 10 2
// 10
// 8 5
// 9 1
// 10 2
// 24
// 15 3
// 20 4
// 23 7
// 39
// 17 8
// 30 5
// 31 9
// 60
// 57 12
// 31 19
// 38 16

// output

// #1 18
// #2 25
// #3 57
// #4 86
// #5 339

// */


#include <bits/stdc++.h>
using namespace std;

int left(vector<int> &vis, int ind, int n)
{
    // int cnt = 0;
    for (int i = ind; i > 0; i--)
    {
        if (vis[i] == 0)
            return i;
    }
    return INT_MAX;
}

int right(vector<int> &vis, int ind, int n)
{
    // int cnt = 0;
    for (int i = ind; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            return i;
        }
    }
    return INT_MAX;
}

void solve(vector<int> &vis, int x, int y, int z, vector<int> &fisher, vector<int> &gates, int n, int gate, int &ans, int curr)
{
    if (curr > ans)
        return;
    if (fisher[gate] == 0)
    {
        if (gate == x)
            gate = y;
        else if (gate == y)
            gate = z;
        else
        {
            ans = min(ans, curr);
            return;
        }
    }
    int fleft = left(vis, gates[gate], n);
    int fright = right(vis, gates[gate], n);

    bool can_left = true, can_right = true;
    if (fleft == INT_MAX)
        can_left = false;
    if (fright == INT_MAX)
        can_right = false;
    int d_left = abs(gates[gate] - fleft);
    int d_right = abs(gates[gate] - fright);
    if (d_left > d_right)
        can_left = false;
    if (d_left < d_right)
        can_right = false;

    if (can_left)
    {
        fisher[gate]--;
        vis[fleft] = 1;
        solve(vis, x, y, z, fisher, gates, n, gate, ans, curr + d_left + 1);
        vis[fleft] = 0;
        fisher[gate]++;
    }

    if (can_right)
    {
        fisher[gate]--;
        vis[fright] = 1;
        solve(vis, x, y, z, fisher, gates, n, gate, ans, curr + d_right + 1);
        vis[fright] = 0;
        fisher[gate]++;
    }
}
int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int t;
    cin >> t;
    int cnt = 0;
    while (t--)
    {
        cnt++;
        int n;
        cin >> n;

        vector<int> gates(4);
        vector<int> fisher(4);
        for (int i = 1; i <= 3; i++)
        {
            cin >> gates[i] >> fisher[i];
        }
        int ans = INT_MAX;

        vector<int> vis(n + 1, 0);
        solve(vis, 1, 2, 3, fisher, gates, n, 1, ans, 0);
        vector<int> vis1(n + 1, 0);
        solve(vis1, 2, 1, 3, fisher, gates, n, 2, ans, 0);
        vector<int> vis2(n + 1, 0);
        solve(vis2, 3, 2, 1, fisher, gates, n, 3, ans, 0);
        vector<int> vis3(n + 1, 0);
        solve(vis3, 1, 3, 2, fisher, gates, n, 1, ans, 0);
        vector<int> vis4(n + 1, 0);
        solve(vis4, 2, 3, 1, fisher, gates, n, 2, ans, 0);
        vector<int> vis5(n + 1, 0);
        solve(vis5, 3, 1, 2, fisher, gates, n, 3, ans, 0);
        cout << "#" << cnt << " " << ans << endl;
    }
    return 0;
}