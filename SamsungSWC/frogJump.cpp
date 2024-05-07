/*
Given a 2 D matrix where 1 represents the places where the frog can jump and 0 represent the empty spaces, 
the frog can move freely in the horizontal direction (on 1’s only) without incurring any cost (jump). 
A vertical jump from a given point of the matrix to another point on the matrix can be taken (on 1’s only) with cost as the number of jumps taken.
Given a source and destination, the frog has to reach the destination minimizing the cost (jump)
*/

// My major mistake in this was
// Here my row was my x but I was adding delx in it but instead I should add dely in it.
// Here my col was my y but I was adding dely in it but instead I should add delx in it.


#include<bits/stdc++.h>
using namespace std;
int n;
void dfs(pair<int,int> src, pair<int,int> dest, vector<vector<int>> adj, vector<vector<int>> vis, int &ans, int temp)
{
        
    int row = src.first;
    int col = src.second;
    vis[row][col] = 1;

    if(src==dest)
    {
        ans = min(ans,temp);
        return;
    }

    int delrow[] = {-1,1,0,0};
    int delcol[] = {0,0,1,-1};


    for(int i=0;i<4;i++)
    {
        int nrow= row+delrow[i];
        int ncol= col+delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && adj[nrow][ncol]==1 && !vis[nrow][ncol])
        {
            if(i>=2){
                dfs({nrow,ncol},dest,adj,vis,ans, temp);
            }
            else{
                dfs({nrow,ncol},dest,adj,vis,ans,temp+1);
            }
        }
    }

    return;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    vector<vector<int>> adj(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int t;
            cin>>t;
            adj[i][j]=t;
        }
    }
    pair<int,int> src, dest;
    int a,b;
    cin>>a>>b;
    a--,b--;
    src = {a,b};
    int c,d;
    cin>>c>>d;
    c--,d--;
    dest = {c,d};
    vector<vector<int>> vis(n,vector<int>(n,0));
    int ans=INT_MAX;
    dfs(src,dest,adj,vis,ans,0);
    if(ans==INT_MAX){
        cout<<-1<<endl;
    }
    else{
        cout<<ans<<endl;
    }
    
}