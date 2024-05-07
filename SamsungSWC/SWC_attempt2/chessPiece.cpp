/*
https://www.cnblogs.com/kingshow123/p/practicec2.html
http://www.voidcn.com/article/p-mpfarobd-bgr.html
*/

/*
There is a mobile piece and a stationary piece on the N×M chessboard. 
The available moves of the mobile piece are the same as set out in the image below. 
You need to capture the stationary piece by moving the mobile piece with the minimum amount of moves.

Write a program to find out the minimum number moves to catch a piece. 

[Input]
Several test cases can be included in the inputs. T, the number of cases is given in the first row of the
inputs. After that, the test cases as many as T (T ≤ 20) are given in a row. 
N, the numbers of the rows and M, the number of columns of the chessboard are given in the first row of
each test case. 
R & C is the location information of the attacking piece and S & K is the location of the defending pieces 
and are given in the row at the second line. However, the location of the uppermost end of the left end 
is (1, 1)

[Output]
For each test case, you should print "Case #T" in the first line where T means the case number.

For each test case, you should output the minimum number of movements to catch a defending piece at the 
first line of each test case. If not moveable, output equals ‘-1’. 

[I/O Example]

Input 
2
9 9
3 5 2 8
20 20
2 3 7 9

Output
Case #1
2
Case #2
5 
*/

#include<bits/stdc++.h>
using namespace std;

int mv[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};

void dfs(int r, int c, int s, int k, vector<vector<int>>& vis, int temp, int& ans, int n, int m)
{
    if(r==s && c==k)
    {
        ans = min(ans,temp);
        return;
    }
    vis[r][c]=1;

    for(int i=0;i<8;i++)
    {
        int nrow = r + mv[i][0];
        int ncol = c + mv[i][1];

        if(nrow >=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol])
        {
            dfs(r,c,s,k,vis,temp+1,ans,n,m);
        }
    }

    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;cin>>t;
    for(int test=1;test<=t;test++)
    {
        int n,m;
        cin>>n>>m;
        int r,c,s,k;
        cin>>r>>c>>s>>k;
        r--; c--; s--; k--;
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=INT_MAX;
        
        dfs(r,c,s,k,vis,0,ans,n,m);
        cout<<ans<<endl;
    }
}