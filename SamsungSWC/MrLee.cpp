/*
Mr. Lee has to travel various offices abroad to assist branches of each place. But he has a problem. 
The airfare would be real high as all offices he has to visit are in foreign countries. He wants to visit every 
location only one time and return home with the lowest expense. Help this company-caring man calculate the lowest expense.


Input format
Several test cases can be included in the inputs. T, the number of cases is given in the first row of the inputs. 
After that, the test cases as many as T (T ≤ 30) are given in a row. N, the number of offices to visit is given on 
the first row per each test case. At this moment, No. 1 office is regarded as his company (Departure point). 
(1 ≤ N ≤ 12) Airfares are given to move cities in which branches are located from the second row to N number rows.
i.e. jth number of ith row is the airfare to move from ith city to jth city. If it is impossible to move between 
two cities, it is given as zero.

Output format
Output the minimum airfare used to depart from his company, visit all offices, and then return his company on the 
first row per each test case.

Example of Input

3
5
0 14 4 10 20
14 0 7 8 7
4 5 0 7 16
11 7 9 0 2
18 7 17 4 0
5
9 9 2 9 5
6 3 5 1 5
1 8 3 3 3
6 0 9 6 8
6 6 9 4 8
3
0 2 24
3 0 2
0 4 0

Example of Output

30
18
CUSTOM - 31 <- 4
*/
#include<bits/stdc++.h>
using namespace std;

void permute(int src, vector<int> path, vector<vector<int>> adj, vector<vector<int>>& ans, int freq[], int n, int dist, int& minDist,int& lastNode, vector<int>& optimalPath)
{
    if(path.size()==n)
    {
        // ans.push_back(path);
        // cout<<"distance = "<< dist<<endl;
        // minDist = min(minDist,dist);
        if(minDist>dist && adj[path[n-1]-1][0]!=0)
        {
            minDist = dist;
            lastNode = path[n-1];
            optimalPath = path;
        }
        return;
    }
    int temp =dist;
    
    for(int i=1;i<n;i++)
    {
        if(!freq[i]){
            freq[i]=1;
            path.push_back(i);
            dist = dist + adj[src][i];
            permute(i,path,adj,ans,freq,n,dist,minDist,lastNode,optimalPath);
            dist = temp;
            freq[i]=0;
            path.pop_back();
        }

    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;cin>>t;while(t--){
        int n;
        cin>>n;
        vector<vector<int>> adj(n,vector<int>(n));
        // vector<pair<int,int>> adj[n]; // i, wt, j
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                // int wt;
                // cin>>wt;
                // adj[i].push_back({wt,j});
                cin>>adj[i][j];
            }
        }

        int freq[n];
        for(int i=0;i<n;i++) freq[i]=0;
        freq[0]=1;
        vector<vector<int>>ans;
        vector<int> path;
        path.push_back(0);
        int dist=0;
        int minDist = INT_MAX;
        int lastNode = -1;
        vector<int> optimalPath;
        permute(0,path,adj,ans,freq,n,dist,minDist,lastNode,optimalPath);
        // cout<<minDist<<" ";
        // cout<<ans[ans.size()-1][ans.size()-1]<<endl;
        // sort(ans.begin(),ans.end());
        // for(int i=0;i<ans.size();i++)
        // {
        //     for(int j=0;j<ans[0].size();j++)
        //     {
        //         cout<<ans[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        // cout<<lastNode<<" "<<minDist<<endl;
        minDist += adj[lastNode][0];
        for(auto it: optimalPath)
        {
            cout<<it<<" ";
        }
        
        cout<<endl<<minDist<<endl;

    }
}