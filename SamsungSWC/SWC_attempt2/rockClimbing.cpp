// /*
// Raka wants to climb a rock from a starting point to the destination point.
// Given a map of the rock mountain which N = height, M = width.
// In the map, character '-' is the possible foot place spot (where he can climb). He can freely move up/down at vertical spots which '-' exists sequentially.
// It's impossible to move horizontally in case '-' is not consecutive in the same height level.
// The maximum height of moving from the starting point to the destination point is the level of difficulty of rock climbing .
// The total distance of movement is not important. There is more than one path from the starting point to the destination point.
// Output: The minimum level of difficulty of all rock climbing paths level.

// Hint: Start with difficulty level 0 and then keep increasing it one by one. Raka always starts from bottom left position.

// image

// Input Format

// First line contains n,m number of rows, columns respectively Next n lines each containg m integers. interger 3 represenets goal point, interger 1 represent '-', 0 represent "no step".

// Constraints

// 1 <= N,M <= 10

// Output Format

// Single interger "level"

// Sample Input 0

// 5 8
// 1 1 1 1 0 0 0 0
// 0 0 0 3 0 1 1 1
// 1 1 1 0 0 1 0 0
// 0 0 0 0 0 0 1 0
// 1 1 1 1 1 1 1 1

// Sample Output 0

// 2

// */

#include <bits/stdc++.h>
using namespace std;

int delrow[] = {-1, 0, 1, 0};
int delcol[] = {0, 1, 0, -1};

bool dfs(int row, int col, vector<vector<int>> grid, vector<vector<int>> &vis, int level, int n, int m)
{
    vis[row][col] = 1;
    if (grid[row][col] == 3)
    {
        return true;
    }

    for (int i = 1; i <= level; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int nrow = row + i * delrow[j];
            int ncol = col + delcol[j];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] != 0)
            {
                if (dfs(nrow, ncol, grid, vis, level, n, m))
                {
                    return true;
                }
            }
        }
    }

    return false;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        
        if (grid[n - 1][0] == 3)
        {
            cout << 0 << endl;
            return 0;
        }
        int j = 0;
        bool flag = true;
        while (j < m and grid[n - 1][j] == 1)
        {
            j++;
            if (j < m and grid[n - 1][j] == 3)
            {
                cout << 0 << endl;
                flag=false;
                break;
            }
        }
        if(flag==false)
        {
            continue;
        }

        int level = 1;
        while (1)
        {
            vector<vector<int>> vis(n, vector<int>(m, 0));

            if (dfs(n - 1, 0, grid, vis, level, n, m))
            {
                break;
            }
            level++;
        }
        cout << "#" << i << " " << level << endl;
    }
    return 0;
}
