
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;

void dfs(int node, vector<int> &vis, vector<int> temp, vector<int> adj[])
{
    vis[node] = 1;
    temp.push_back(node);
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, temp, adj);
        }
        else
        {
            temp.push_back(it);
            ans.push_back(temp);
        }
    }
    vis[node] = 0;
    temp.pop_back();
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> temp;
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, temp, adj);
        }
    }

    set<vector<int>> res;
    int sz = ans.size();
    for (int i = 0; i < sz; i++)
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
        {
            temp.push_back(ans[i][j]);
        }
        sort(temp.begin(), temp.end());
        res.insert(temp);
    }
    int mn = INT_MAX;
    vector<int> cycle;
    for (auto it = res.begin(); it != res.end(); it++)
    {
        int sum = 0;
        for (auto p : *it)
        {
            sum += p;
        }
        if (mn > sum)
        {
            cycle = *it;
            mn = sum;
        }
    }
    for (auto val : cycle)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
