/*
https://www.careercup.com/question?id=5652067409461248
https://www.geeksforgeeks.org/samsung-interview-experience-set-28-campus/

http://ideone.com/JXMl4L
https://ide.geeksforgeeks.org/tiyLThcuSN -> Zero
https://ide.geeksforgeeks.org/3Ks1tpOkwn

*https://code.hackerearth.com/ea07cfD?key=1cb190b158c79639d66d35f7dfa8ef7a -> One

Similr Problem - https://ide.codingblocks.com/s/95965


You’ll be given a grid as below:

    0 1 0 2 0
    0 2 2 2 1
    0 2 1 1 1
    1 0 1 0 0
    0 0 1 2 2
    1 1 0 0 1
    x x S x x

In the grid above,
  1: This cell has a coin.
  2: This cell has an enemy.
  0: It contains nothing.

  The highlighted(yellow) zone is the control zone. S is a spaceship that we need to control so that we can get
  maximum coins.
  Now, S’s initial position will be at the center and we can only move it right or left by one cell or do not move.
  At each time, the non-highlighted part of the grid will move down by one unit.
  We can also use a bomb but only once. If we use that, all the enemies in the 5×5 region above the control zone
  will be killed.
  If we use a bomb at the very beginning, the grid will look like this:

    0 1 0 2 0
    0 0 0 0 1
    0 0 1 1 1
    1 0 1 0 0
    0 0 1 0 0
    1 1 0 0 1
    x x S x x

  As soon as, the spaceship encounters an enemy or the entire grid has come down, the game ends.
  For example,
  At the very first instance, if we want to collect a coin we should move left( coins=1). This is because when the
  grid comes down by 1 unit we have a coin on the second position and by moving left we can collect that coin.
  Next, we should move right to collect another coin (coins=2).
  After this, remain at the same position (coins=4).
  This is the current situation after collecting 4 coins.

    0 1 0 2 0 0 1 0 0 0
    0 2 2 2 1 -->after using 0 0 0 0 1
    x x S x x -->bomb x x S x x

   Now, we can use the bomb to get out of this situation. After this, we can collect at most 1 coin. So maximum coins=5.
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> grid, int n, int temp, bool bomb, int &ans)
{
  ans = max(ans, temp);
  int delrow[] = {-1, -1, -1};
  int delcol[] = {-1, 0, 1};
  for (int i = 0; i < 3; i++)
  {
    int nrow = row + delrow[i];
    int ncol = col + delcol[i];

    if (nrow >= 0 && ncol >= 0 && ncol < 5)
    {
      if (grid[nrow][ncol] == 1)
        dfs(nrow, ncol, grid, n, temp + 1, bomb, ans);
      else if (grid[nrow][ncol] == 0)
        dfs(nrow, ncol, grid, n, temp, bomb, ans);
      else if (grid[nrow][ncol] == 2)
      {
        if (bomb == false)
        {
          vector<vector<int>> tempgrid = grid;
          for (int l = nrow; l > nrow - 5 && l >= 0; l--)
          {
            for (int m = 0; m < 5; m++)
            {
              if (grid[l][m] == 2)
                grid[l][m] = 0;
            }
          }
          dfs(nrow, ncol, grid, n, temp, true, ans);
          grid = tempgrid;
        }
      }
    }
  }
  ans = max(ans, temp);
}

int main()
{
  int t;
  cin >> t;
  for (int test_case = 1; test_case <= t; test_case++)
  {
    int ans = 0;
    int n;
    cin >> n;
    vector<vector<int>> grid(n + 2, vector<int>(5));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < 5; j++)
        cin >> grid[i][j];
    }
    for (int j = 0; j < 5; j++)
      grid[n][j] = 0;

    // (-1,-1), (-1,0), (-1,1)
    // pair<int,int> src = {n,n/2+1};

    dfs(n, 2, grid, n, 0, false, ans);
    cout << "#" << test_case << " " << ans << endl;
  }
  return 0;
}
