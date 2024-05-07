/*
Rare element 5

Samsung wants to explore some of the rare elements for its semiconductor manufacturing.
Scientists use one vehicle to explore the region in order to find the rare elements.
The vehicle can move only in explored region where roads have already been constructed.
The vehicle cannot move on unexplored region where roads are not there.
In the current situation, rare elements are present in explored region only.
Unexplored regions do not contain any rare elements.

Square region is provided for exploration.
Roads are represented by 1 and where roads are not present that area is represented by 0.
Rare elements will only be on the roads where regions have already been explored.
Vehicle can move in four directions – up, down, left and right.

The shortest path for vehicle to a rare element position is called Moving Path.
The longest of the paths to all rare elements from a region called Longest Distance.

Scientists need to construct one research center so that the research center will be at the position where
the longest path to the rare elements will be shortest.
This is called Shortest Longest Distance.

Image 9

In the above picture (Fig. 1), Red, Blue and Green area represents Rare Element area.
(2, 2) is represented as Red, (2, 8) is represented as Blue and (7, 8) is represented as Green. So there are three rare elements.

If research center is constructed at (4, 4) then distance to Red rare element will be 4,
distance to Blue rare element will be 6 and distance to Green rare element will be 7. So the Longest distance will be 7.

Image 10

Now using the same region (Fig. 2), if research center is constructed at (4, 5) then distance to Red rare element will be 5, distance to Blue rare element will be 5 and distance to Green rare element will be 6. So the Longest distance will be 6.
So when research center is constructed at (4, 5) then the longest distance will be shortest. And the value of the Shortest Longest Distance will be 6. This will be the output.
There can be multiple locations from where the shortest longest distance can be same. For example if research center is constructed at (5, 5) then still the Shortest Longest distance will be 6.
So write a program to find the Shortest Longest Distance.

Constraints:
The region provided will be square region i.e. NxN (where 5 <=  N <= 20).
There can be minimum of 2 rare elements and maximum of 4 rare elements, i.e. 2 <= C <= 4.
Roads are represented by 1 while no road area is represented by 0.
Vehicle can move only on roads in explored area.
The rare elements will only be present where road are there. Rare elements will not be present where roads are not present.
Vehicle can move in UP, DOWN, LEFT and RIGHT directions.
The starting index for rare element is considers as 1.


Input:
First line will be the number of test cases. Second line will indicate region area (N) and number of rare elements (C). Next C lines will contain the position of rare elements. After that N lines will provide the region details where to tell where roads are present and where roads are not present.

Output:
Output #testcase followed by space and then shortest longest distance.
*/

#include <bits/stdc++.h>
using namespace std;
int n, c;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> c;
        vector<pair<int, int>> rare;
        for (int i = 0; i < c; i++)
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            rare.push_back({a, b});
        }
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> grid[i][j];
        }
        vector<vector<int>> finalDist(n, vector<int>(n, 0));
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};
        for (auto gem : rare)
        {
            int r = gem.first;
            int c = gem.second;
            vector<vector<int>> dist(n, vector<int>(n, 0));
            vector<vector<int>> vis(n, vector<int>(n, 0));
            queue<pair<int, int>> q;
            q.push({r, c});
            dist[r][c] = 0;
            vis[r][c] = 1;

            while (!q.empty())
            {
                auto g = q.front();
                int row = g.first;
                int col = g.second;
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];

                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
                    {
                        vis[nrow][ncol] = 1;
                        dist[nrow][ncol] = dist[row][col] + 1;
                        q.push({nrow, ncol});
                    }
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][j] > finalDist[i][j])
                        finalDist[i][j] = dist[i][j];
                }
            }
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                auto it = find(rare.begin(), rare.end(), make_pair(i, j));
                if (finalDist[i][j] && (it != rare.end()))
                    ans = min(ans, finalDist[i][j]);
            }
        }
        cout << ans << endl;
    }
}