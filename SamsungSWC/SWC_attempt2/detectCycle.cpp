/*
Detect and print the cycle in ascending order. If there are multiple cycles, print the cycle with nodes' sum smallest.

Input Format

Given number of nodes and edges, N,M Next line contains edges u and v (u->v edge) space separated, 2*M values

Constraints

1 < N < 10

1 < M < 50

Output Format

single line node values in sorted order
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> ans;
void dfs_cycle(vector<int> temp, vector<int> adj[], int node, vector<int> &vis, vector<int> &dfs)
{
    vis[node] = 1;
    dfs[node] = 1;
    temp.push_back(node);
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs_cycle(temp, adj, it, vis, dfs);
        }
        else if (dfs[it])
        {
            temp.push_back(it);
            ans.push_back(temp);
        }
    }
    dfs[node] = 0;
    vis[node] = 0;
    temp.pop_back();
}
int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }
    vector<int> temp;
    vector<int> vis(n + 1, 0), dfs(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs_cycle(temp, adj, i, vis, dfs);
    }

    map<int, int> mp;
    bool flag = false;
    vector<vector<int>> res;
    for (int i = 0; i < (int)ans.size(); i++)
    {
        vector<int> temp;
        int ind = 0;
        for (int j = 0; j < (int)ans[i].size(); j++)
        {
            if (ans[i][j] == ans[i][ans[i].size() - 1])
            {
                ind = j;
                break;
            }
        }

        for (int j = ind; j < ans[i].size() - 1; j++)
            temp.push_back(ans[i][j]);
        sort(temp.begin(), temp.end());
        res.push_back(temp);
    }

    vector<int> fin;
    int min = INT_MAX;
    for (int i = 0; i < res.size(); i++)
    {
        int sum = 0;
        for (int j = 0; j < res[i].size(); j++)
        {
            sum += res[i][j];
        }
        if (sum < min)
        {
            fin = res[i];
            min = sum;
        }
    }
    for (int i = 0; i < fin.size(); i++)
        cout << fin[i] << " ";
    cout << endl;

    return 0;
}