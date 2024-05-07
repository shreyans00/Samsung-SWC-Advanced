/*
https://www.geeksforgeeks.org/samsung-interview-experience-set-39-campus-r-d-noida/
https://www.careercup.com/page?pid=samsung-interview-questions

A Doctor travels from a division to other division where divisions are connected like a graph(directed graph) and 
the edge weights are the probabilities of the doctor going from that division to other connected division but the 
doctor stays 10mins at each division now there will be given time and had to find the division in which he will be 
staying by that time and is determined by finding division which has high probability.

Input is number of test cases followed by the number of nodes, edges, time after which we need to find the division 
in which he will be there, the edges starting point, end point, probability.

Note: If he reaches a point where there are no further nodes then he leaves the lab after 10 mins and the traveling 
time is not considered and during that 10min at 10th min he will be in next division, so be careful

2
6 10 40 
1 2 0.3 
1 3 0.7 
3 3 0.2 
3 4 0.8 
2 4 1 
4 5 0.9 
4 4 0.1 
5 6 1.0 
6 3 0.5 
6 6 0.5

6 10 10 
1 2 0.3 
1 3 0.7 
3 3 0.2 
3 4 0.8 
2 4 1 
4 5 0.9 
4 4 0.1 
5 6 1.0 
6 3 0.5 
6 6 0.5

6 0.774000  
3 0.700000
*/

#include<bits/stdc++.h>
using namespace std;

void f(int node,vector<pair<int,float>> adj[], int count, vector<pair<int,float>>& final, int n,int m, float temp)
{
    if(count == 1)
    {
        final.push_back({node,temp});
        return;
    }

    for(auto it: adj[node])
    {
        int nd = it.first;
        float prb = it.second;
        f(nd,adj,count-1,final,n,m,temp*prb);
    }
    return;

}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;cin>>t;while(t--){
        int n,m,time;
        cin>>n>>m>>time;
        vector<pair<int,float>> adj[n+1];

        for(int i=0;i<m;i++)
        {
            int a,b;
            float c;
            cin>>a>>b;
            cin>>c;
            adj[a].push_back({b,c});
        }
        

        int count = time/10; 
        if(time%10 == 0) count++;
        vector<pair<int,float>> final;
        f(1,adj,count,final,n,m,1);
        
        sort(final.begin(),final.end());
        unordered_map<int,float> freq;
        for(auto it: final)
        {
            // cout<<it.first<<" "<<it.second<<endl;
            freq[it.first] += it.second;
        }

        float mx=0;
        int ans=0;
        for(auto mp:freq)
        {
            if(mx< mp.second){
                mx=mp.second;
                ans= mp.first;
            }
        }

        if(ans==0) cout<<-1;
        else {
            cout<<ans<<" ";
            cout<<fixed<<setprecision(6)<<mx<<endl;
        }

    }
}
