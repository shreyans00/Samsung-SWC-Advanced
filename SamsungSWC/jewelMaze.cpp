/*
https://blog.csdn.net/lihenair/article/details/17227667
http://www.mamicode.com/info-detail-995985.html
https://www.oipapio.com/cn/article-8650635
https://blog.csdn.net/broadCE/article/details/47959227
--------------------------------------------------------
There is a maze that has one entrance and one exit. Jewels are placed in passages of the maze. 
You want to pick up the jewels after getting into the maze through the entrance and before getting 
out of it through the exit. You want to get as many jewels as possible, but you don’t want to take 
the same passage you used once.

When locations of a maze and jewels are given, find out the greatest number of jewels you can get 
without taking the same passage twice, and the path taken in this case.

Input
There can be more than one test case in the input file. The first line has T, the number of test cases.
Then the totally T test cases are provided in the following lines (T ≤ 10 ).

In each test case, In the first line, the size of the maze N (1 ≤ N ≤ 10) is given. 
The maze is N×N square-shaped. From the second line through N lines, information of the maze is given.
“0” means a passage, “1” means a wall, and “2” means a location of a jewel. The entrance is located 
on the upper-most left passage and the exit is located on the lower-most right passage. 
There is no case where the path from the entrance to the exit doesn’t exist.

Output
From the first line through N lines, mark the path with 3 and output it. In N+1 line, output the 
greatest number of jewels that can be picked up. Each test case must be output separately as a empty.
*/
#include<bits/stdc++.h>
using namespace std;
// int ans = INT_MAX;
vector<vector<int>> ansvec;
void dfs(int row, int col, int n, vector<vector<int>> adj, vector<vector<int>>& vis, int temp,int &ans)
{
    
    vis[row][col] = 3;
    if(row==n-1 && col==n-1){
        // ans=min(ans,temp);
        if(temp<ans){
            ans=temp;
            ansvec=vis;
        }
        return;
    }
    
    int delrow[] = {-1,0,1,0};
    int delcol[] = {0,-1,0,1};

    for(int i=0;i<4;i++)
    {
        int nrow= row+ delrow[i];
        int ncol= col+ delcol[i];

        if(nrow>=0 && nrow<n && ncol>=0 && ncol<n)
        {
            if(vis[nrow][ncol] != 3){
                
                if(adj[nrow][ncol]==0)
                {
                    dfs(nrow,ncol,n,adj,vis,temp,ans);
                }    
                else if(adj[nrow][ncol]==2) {
                    dfs(nrow,ncol,n,adj,vis,temp+1,ans);
                }
                else continue;
            }
        }
    }
    vis[row][col]=adj[row][col];
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;cin>>t;while(t--){
        int n;
        cin>>n;
        vector<vector<int>> adj;
        for(int i=0;i<n;i++)
        {
            vector<int> temp;
            for(int j=0;j<n;j++)
            {
                int x; cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        vector<vector<int>> vis = adj;
        int ans=INT_MAX;
        dfs(0,0,n,adj,vis,0,ans);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<ansvec[i][j]<<" ";
            }
            cout<<endl;
            
        }
        cout<<ans<<endl;
    }
}