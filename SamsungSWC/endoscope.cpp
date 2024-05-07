#include <bits/stdc++.h>
using namespace std;
int N, M;
int l;
bool isValid(int a, int b, int dir)
{
    if (a == 1)
    {
        if (b == 1)
            return true;
        if (b == 2 && (dir == 1 || dir == 3))
            return true;
        if (b == 3 && (dir == 2 || dir == 4))
            return true;
        if (b == 4 && (dir == 4 || dir == 3))
            return true;
        if (b == 5 && (dir == 4 || dir == 1))
            return true;
        if (b == 6 && (dir == 1 || dir == 2))
            return true;
        if (b == 7 && (dir == 2 || dir == 3))
            return true;
        return false;
    }
    else if (a == 2)
    {
        if (b == 2 && (dir == 1 || dir == 3))
            return true;
        if (b == 1 && (dir == 1 || dir == 3))
            return true;
        if (b == 5 && dir == 1)
            return true;
        if (b == 4 && dir == 3)
            return true;
        if (b == 6 && dir == 1)
            return true;
        if (b == 7 && dir == 3)
            return true;
        return false;
    }
    else if (a == 3)
    {
        if (b == 3 && (dir == 2 || dir == 4))
            return true;
        if (b == 1 && (dir == 2 || dir == 4))
            return true;
        if ((b == 4 || b == 5) && dir == 4)
            return true;
        if ((b == 6 || b == 7) && dir == 2)
            return true;
        return false;
    }
    else if (a == 4)
    {
        // if(b==4 && (dir==1 || dir==2)) return true;
        if (dir == 1 && (b == 1 || b == 2 || b == 5 || b == 6))
            return true;
        if (dir == 2 && (b == 1 || b == 3 || b == 6 || b == 7))
            return true;
        return false;
    }
    else if (a == 5)
    {
        // if(b==5 && (dir==2 || dir==3)) return true;
        if (dir == 2 && (b == 1 || b == 3 || b == 6 || b == 7))
            return true;
        if (dir == 3 && (b == 1 || b == 2 || b == 4 || b == 7))
            return true;
        return false;
    }
    else if (a == 6)
    {
        // if(b==6 && (dir==4 || dir==3)) return true;
        if (dir == 3 && (b == 1 || b == 2 || b == 4 || b == 7))
            return true;
        if (dir == 4 && (b == 1 || b == 3 || b == 4 || b == 5))
            return true;
        return false;
    }
    else if (a == 7)
    {
        // if(b==7 && (dir==1 || dir==4)) return true;
        if (dir == 4 && (b == 1 || b == 3 || b == 4 || b == 5))
            return true;
        if (dir == 1 && (b == 1 || b == 2 || b == 6 || b == 5))
            return true;
        return false;
    }
    else
        return false;
}

int f(int row, int col, int l, int ans, vector<vector<int>> &vis, vector<vector<int>> &grid, int N, int M)
{
    if (l == 0)
    {
        return ans;
    }

    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];

        if (nrow >= 0 && nrow < N && ncol >= 0 && ncol < M)
        {
            if (isValid(grid[row][col], grid[nrow][ncol], i + 1))
            {
                if (!vis[nrow][ncol])
                {
                    vis[nrow][ncol] = 1;
                    ans= 1 + f(nrow, ncol, l - 1, ans, vis, grid, N, M);
                }
                // else
                // {
                //     // ans= f(nrow, ncol, l - 1, ans, vis, grid, N, M,dp);
                // }
            }
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        cin >> N >> M;
        int r, c;
        cin >> r >> c;
        
        cin >> l;
        vector<vector<int>> grid(N, vector<int>(M));

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> grid[i][j];
            }
        }
        if(grid[r][c]==0) {
			cout<<0<<endl;
			continue;
		}
        int ans = 1;
        l--;
        vector<vector<int>> vis(N, vector<int>(M, 0));
        vis[r][c] = 1;
        // int dp[51][51][21];
        // memset(dp, -1, sizeof(dp));
        ans = f(r, c, l, 1, vis, grid, N, M);
        cout << ans << endl;
    }
}