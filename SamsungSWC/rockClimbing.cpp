/*

Raka wants to climb a rock from a starting point to the destination point.
Given a map of the rock mountain which N = height, M = width.
In the map, character '-' is the possible foot place spot (where he can climb). He can freely move up/down at vertical spots which '-' exists sequentially.
It's impossible to move horizontally in case '-' is not consecutive in the same height level.
The maximum height of moving from the starting point to the destination point is the level of difficulty of rock climbing .
The total distance of movement is not important. There is more than one path from the starting point to the destination point.
Output: The minimum level of difficulty of all rock climbing paths level.

Hint: Start with difficulty level 0 and then keep increasing it one by one. Raka always starts from bottom left position.

image

Input Format

First line contains n,m number of rows, columns respectively Next n lines each containg m integers. interger 3 represenets goal point, interger 1 represent '-', 0 represent "no step".

Constraints

1 <= N,M <= 10

Output Format

Single interger "level"

Sample Input 0

5 8
1 1 1 1 0 0 0 0
0 0 0 3 0 1 1 1
1 1 1 0 0 1 0 0
0 0 0 0 0 0 1 0
1 1 1 1 1 1 1 1

Sample Output 0

2

*/

#include <bits/stdc++.h>
using namespace std;

void dfs(pair<int, int> src, pair<int, int> dest, vector<vector<int>>& graph, vector<vector<int>> vis, int &ans, int temp, int n, int m)
{
    int row = src.first;
    int col = src.second;
    if (row == dest.first && col == dest.second)
    {
        // cout<<"mai yaha pahuch gaya"<<endl;
        // cout<<temp<<endl;
        ans = min(ans, temp);
        return;
    }
    vis[row][col] = 1;

    int nrow, ncol;
    // going horizontally
    nrow = row;
    // two cases : left or right
    // 1. right
    if (col + 1 < m)
    {
        ncol = col + 1;
        if (!vis[nrow][ncol] && graph[nrow][ncol] != 0)
        {
            vis[nrow][ncol] = 1;
            dfs({nrow, ncol}, dest, graph, vis, ans, temp, n, m);
            // vis[nrow][ncol]= 0;
        }
    }
    // 2. left
    if (col - 1 >= 0)
    {
        ncol = col - 1;
        if (!vis[nrow][ncol] && graph[nrow][ncol] != 0)
        {
            vis[nrow][ncol] = 1;
            dfs({nrow, ncol}, dest, graph, vis, ans, temp, n, m);
            // vis[nrow][ncol]= 0;
        }
    }

    // going vertically
    // two cases : up or down
    // 1. Up
    ncol = col;
    int cnt = 0;
    if (row - 1 >= 0)
    {
        for (int i = row - 1; i >= 0; i--)
        {

            if (!vis[i][ncol] && graph[i][ncol] != 0)
            {
                vis[i][ncol] = 1;
                dfs({i, ncol}, dest, graph, vis, ans, max(cnt + 1, temp), n, m);
                // cnt=0;
                // vis[i][ncol]=0;
            }
            // else{
            cnt++;
            // }
        }
    }
    int cnt2 = 0;
    if (row + 1 < n)
    {
        for (int i = row + 1; i < n; i++)
        {

            if (!vis[i][ncol] && graph[i][ncol] != 0)
            {
                vis[i][ncol] = 1;
                dfs({i, ncol}, dest, graph, vis, ans, max(temp, cnt2 + 1), n, m);
                // cnt2=1;
                // vis[i][ncol]=0;
            }
            // else{
            cnt2++;
            // }
        }
    }
    return;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> graph(n, vector<int>(m));
        pair<int, int> dest;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> graph[i][j];
                if (graph[i][j] == 3)
                {
                    dest.first = i;
                    dest.second = j;
                }
            }
        }
        pair<int, int> src = {n - 1, 0};
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = INT_MAX;
        dfs(src, dest, graph, vis, ans, 0, n, m);
        cout << ans << endl;
    }
    return 0;
}
